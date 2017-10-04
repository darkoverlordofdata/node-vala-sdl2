/**
 * ApplicationListener.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses GLib
uses sdx
uses sdx.math
uses sdx.graphics
uses sdx.graphics.s2d
uses sdx.utils

namespace sdx.scenes.scene2d

    enum Touchable
        enabled
        disabled
        childrenOnly

    const PI: double = 3.1415927
    const degreesToRadians: double = PI / 180.0

    class Actor : Object
        prop stage: Stage
        prop parent: Group
        prop touchable: Touchable = Touchable.enabled
        prop userObject: Object
        prop color: Color// = Color.White
        prop name: string

        listeners: list of EventListener = new list of EventListener
        captureListeners: list of EventListener = new list of EventListener
        actions: list of Action = new list of Action

        visible: bool = true
        x: double
        y: double
        width: double
        height: double
        originX: double
        originY: double
        scaleX: double = 1
        scaleY: double = 1
        rotation: double

        /**
         * draw the actor
         */
        def draw(batch: Batch, parentAlpha: double)
            pass

        /**
         * update the actor each frame
         */
        def act(delta: double)
            if actions.size > 0
                //if stage != null
                for var i=0 to (actions.size-1)
                    var action = actions[i]
                    if action.act(delta)
                        var current = actions[i]
                        var actionIndex = current == action ? i : actions.index_of(action)
                        if actionIndex != -1
                            actions.remove_at(actionIndex)
                            action.actor = null
                            i--


        /**
         * fire event and propogate up the chain to parent nodes
         */
        def fire(event:Event): bool
            if event.getStage() == null do event.setStage(stage)
            event.setTarget(this)

            var ancestors = (list of Group) Pools.obtain(typeof(list of Group))
            var parent = this.parent
            while parent != null
                ancestors.add(parent)
                parent = parent.parent

            for var i = ancestors.size-1 to 0
                var currentTarget = ancestors[i]
                currentTarget.notify(event, true)
                if event.isStopped() do return event.isCancelled()

            notify(event, true)
            if event.isStopped() do return event.isCancelled()
            
            notify(event, false)
            if !event.getBubbles() do return event.isCancelled()
            if event.isStopped() do return event.isCancelled()

            for var i=0 to (ancestors.size-1)
                ancestors[i].notify(event, false)
                if event.isStopped() do return event.isCancelled()

            return event.isCancelled()

        /**
         * notify listeners
         */
        def notify(event: Event, capture: bool): bool

            if event.getTarget() == null
                raise new Exception.IllegalArgumentException("The event target cannot be null.")
            var listeners = capture ? captureListeners : this.listeners
            if listeners.size == 0 do return event.isCancelled()

            event.setListenerActor(this)
            event.setCapture(capture)
            if event.getStage() == null do event.setStage(stage)

            for var i = 0 to  (listeners.size-1)
                var listener = listeners[i]
                if listener.handle(event)
                    event.handle()

            return event.isCancelled()


        /**
         * hit - does the actor contain (x,y)
         */
        def hit(x: double, y:double, touchable: bool): Actor
            if touchable && this.touchable != Touchable.enabled do return null
            return x >= 0 && x < width && y >= 0 && y < height ? this : null


        def remove(): bool
            if parent != null do return parent.removeActor(this)
            return false

        def addListener(listener: EventListener): bool
            if listener == null
                raise new Exception.IllegalArgumentException("listener cannot be null.")
            if !listeners.contains(listener)
                listeners.add(listener)
                return true
            return false

        def removeListener(listener: EventListener): bool
            if listener == null
                raise new Exception.IllegalArgumentException("listener cannot be null.")    
            return listeners.remove(listener)

            
        def getListeners(): list of EventListener
            return listeners


        def addCaptureListener(listener: EventListener): bool
            if listener == null
                raise new Exception.IllegalArgumentException("listener cannot be null.")
            if !captureListeners.contains(listener)
                captureListeners.add(listener)
            return true

        def removeCaptureListener(listener: EventListener): bool
            if listener == null
                raise new Exception.IllegalArgumentException("listener cannot be null.")    
            return captureListeners.remove(listener)

        def getCaptureListeners(): list of EventListener
            return captureListeners

        def addAction(action:Action)
            action.actor = this
            actions.add(action)
		    //if (stage != null && stage.getActionsRequestRendering()) Gdx.graphics.requestRendering();

        def removeAction(action:Action)
            if actions.remove(action) do action.actor = null

        def getActions(): list of Action
            return actions

        def hasActions(): bool  
            return actions.size > 0

        def clearActions()
            for action in actions
                action.actor = null
            actions.clear()

        def clearListeners()
            listeners.clear()
            captureListeners.clear()

        def clear()
            clearActions()
            clearListeners()
            
        def isDescendantOf(actor:Actor):bool
            if actor == null
                raise new Exception.IllegalArgumentException("actor cannot be null.")    
            var parent = this
            while true
                if parent == null do return false
                if parent == actor do return true
                parent = parent.parent
        
        def isAscendantOf(actor:Actor):bool
            if actor == null
                raise new Exception.IllegalArgumentException("actor cannot be null.")    
            var parent = this
            while true
                if actor == null do return false
                if actor == this do return true
                parent = parent.parent

        def firstAscendant(type: Type): Actor
            // if type == null
            //     raise new Exception.IllegalArgumentException("actor cannot be null.")   
            var actor = this
            do
                if actor.get_type() == type
                    return actor
                actor = actor.parent
            while actor != null
            return null

        def hasParent(): bool
            return parent != null

        def isTouchable(): bool
            return touchable == Touchable.enabled
        
        def isVisible(): bool
            return visible

        def setVisible(visible: bool)
            this.visible = visible

        def getX(): double
            return x
        
        def setX(x: double)
            if this.x != x
                this.x = x  
                positionChanged()

        def getY(): double
            return y

        def setY(y: double)
            if this.y != y  
                this.y = y  
                positionChanged()

        def setPosition(x: double, y: double)
            if this.x != x && this.y != y
                this.x = x
                this.y = y
                positionChanged()

        def moveBy(x: double, y: double)
            if x != 0 || y != 0
                this.x += x
                this.y += y
                positionChanged()
                                
        def getWidth(): double
            return width

        def setWidth(width: double)
            if this.width != width
                this.width = width
                sizeChanged()

        def getHeight(): double
            return height
        
        def setHeight(height: double)
            if this.height != height
                this.height = height
                sizeChanged()
                
        def getTop(): double
            return y + height

        def getRight(): double
            return x + width

        def positionChanged()
            pass

        def sizeChanged()
            pass

        def rotationChanged()
            pass

        def setSize(width: double, height: double)
            if this.width != width || this.height != height
                this.width = width
                this.height = height
                sizeChanged()

        def sizeBy(size: double)
            if size != 0
                width += size
                height += size
                sizeChanged()

        def setBounds(x: double, y: double, width: double, height: double)
            if this.x != x && this.y != y
                this.x = x
                this.y = y
                positionChanged()
            if this.width != width || this.height != height
                this.width = width
                this.height = height
                sizeChanged()

        def getOriginX(): double
            return originX

        def setOriginX(originX: double)
            this.originX = originX

        def getOriginY(): double
            return originY

        def setOriginY(originY: double)
            this.originY = originY

        def setOrigin(originX: double, originY: double)
            this.originX = originX
            this.originY = originY

        def getScaleX(): double
            return scaleX

        def setScaleX(scaleX: double)
            this.scaleX = scaleX

        def getScaleY(): double
            return scaleY

        def setScaleY(scaleXY: double)
            this.scaleX = scaleXY
            this.scaleY = scaleXY

        def setScale(scaleX: double, scaleY: double=0)
            if scaleY == 0 do scaleY = scaleX
            this.scaleX = scaleX
            this.scaleY = scaleY
            


        def scaleBy(scaleX: double, scaleY: double)
            this.scaleX += scaleX
            this.scaleY += scaleY

        def getRotation(): double
            return rotation
            
        def setRotation(degrees: double)
            if this.rotation != degrees
                this.rotation = degrees
            rotationChanged()

        def rotateBy(amountInDegrees: double)
            if amountInDegrees != 0
                rotation += amountInDegrees
                rotationChanged()
            
        def toFront()
            setZIndex(int.MAX)

        def toBack()
            setZIndex(0)

        def setZIndex(index: int)
            if (index < 0) do raise new Exception.IllegalArgumentException("ZIndex cannot be < 0.")
            if parent == null do return
            var children = parent.children
            if children.size == 1 do return
            index = (int)Math.fmin(index, children.size-1)
            if children[index] == this do return
            if !children.remove(this) do return
            children.insert(index, this)

        def getZIndex(): int
            if parent == null do return -1
            return parent.children.index_of(this)
        
        def screenToLocalCoordinates(screenCoords: Vector2): Vector2
            if stage == null do return screenCoords
            return stageToLocalCoordinates(stage.screenToStageCoordinates(screenCoords))

        def stageToLocalCoordinates(stageCoords: Vector2): Vector2
            if parent != null do parent.stageToLocalCoordinates(stageCoords)
            parentToLocalCoordinates(stageCoords)
            return stageCoords

        def localToStageCoordinates(localCoords: Vector2): Vector2
            return localToAscendantCoordinates(null, localCoords)

        def localToParentCoordinates(localCoords: Vector2): Vector2
            if rotation == 0
                if scaleX == 1 && scaleY == 1
                    localCoords.x += x
                    localCoords.y += y
                else
                    localCoords.x = (localCoords.x - originX) * scaleX + originX + x
                    localCoords.y = (localCoords.y - originY) * scaleY + originY + y
            else
                var cos1 = Math.cos(rotation * degreesToRadians)
                var sin1 = Math.sin(rotation * degreesToRadians)
                var tox = (localCoords.x - originX) * scaleX
                var toy = (localCoords.y - originY) * scaleY
                localCoords.x = (tox * cos1 + toy * sin1) + originX + x
                localCoords.y = (tox * -sin1 + toy * cos1) + originY + y
            return localCoords

        def localToAscendantCoordinates(ascendant: Actor, localCoords: Vector2): Vector2
            var actor = this
            while actor != null
                actor.localToParentCoordinates(localCoords)
                actor = actor.parent
                if actor == ascendant do break
            return localCoords

        def parentToLocalCoordinates(parentCoords: Vector2): Vector2
            var childX = x
            var childY = y
            if rotation == 0
                if scaleX == 1 && scaleY == 1
                    parentCoords.x -= childX
                    parentCoords.y -= childY
                else
                    parentCoords.x = (parentCoords.x - childX - originX) / scaleX + originX
                    parentCoords.y = (parentCoords.y - childY - originY) / scaleY + originY
            else
                var cos1 = Math.cos(rotation * degreesToRadians)
                var sin1 = Math.sin(rotation * degreesToRadians)
                var tox = parentCoords.x - childX - originX
                var toy = parentCoords.y - childY - originY
                parentCoords.x = (tox * cos1 + toy * sin1) / scaleX + originX
                parentCoords.y = (tox * -sin1 + toy * cos1) / scaleY + originY
            return parentCoords


