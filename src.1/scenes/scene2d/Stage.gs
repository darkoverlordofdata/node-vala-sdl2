/**
 * Stage.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses sdx
uses sdx.math
uses sdx.graphics.s2d
uses sdx.utils
uses sdx.utils.viewport
uses sdx.scenes.scene2d.utils

namespace sdx.scenes.scene2d

    interface Disposable : Object
        def abstract dispose()

    class TouchFocus : Object implements Poolable
        listener: EventListener
        listenerActor: Actor
        target: Actor
        pointer: int
        button: int

        def reset()
            listenerActor = null
            listener = null
            target = null

    class Stage : InputAdapter implements Disposable

        tempCoords: private static Vector2 = new Vector2()
        prop viewport: Viewport
        prop batch: Batch
        prop root: Group
        prop width: double
            get
                return viewport.worldWidth
        prop height: double
            get
                return viewport.worldHeight
                
        ownsBatch: bool
        pointerOverActors: array of Actor = new array of Actor[20]
        pointerTouched: array of bool = new array of bool[20]
        pointerScreenX: array of int = new array of int[20]
        pointerScreenY: array of int = new array of int[20]
        mouseScreenX: int
        mouseScreenY: int
        mouseOverActor: Actor
        keyboardFocus: Actor
        scrollFocus: Actor
        touchFocuses: list of TouchFocus = new list of TouchFocus    
        actionsRequestRendering: bool = true
                
        construct(viewport: Viewport?=null, batch: Batch?=null)
            this.viewport = viewport == null ? new Viewport() : viewport
            ownsBatch = batch == null
            this.batch = ownsBatch ? new Batch() : batch
            root = new Group()
		    //viewport.update(Gdx.graphics.getWidth(), Gdx.graphics.getHeight(), true)
            

        
                
        def draw()
            root.draw(batch, 255)

        def act(delta: double)
            for var pointer = 0 to (pointerOverActors.length-1)
                var overLast = pointerOverActors[pointer]
                if pointerTouched[pointer]
                    if overLast != null
                        pointerOverActors[pointer] = null
                        screenToStageCoordinates(tempCoords.@set(pointerScreenX[pointer], pointerScreenY[pointer]))
                        var event = (InputEvent)Pools.obtain(typeof(InputEvent))
                        event.setStage(this)
                        event.setStageX(tempCoords.x)
                        event.setStageY(tempCoords.y)
                        event.setRelatedActor(overLast)
                        event.setPointer(pointer)
                        overLast.fire(event)
                        Pools.free(event)
                    continue
                pointerOverActors[pointer] = fireEnterAndExit(overLast, pointerScreenX[pointer], pointerScreenY[pointer], pointer)
            mouseOverActor = fireEnterAndExit(mouseOverActor, mouseScreenX, mouseScreenY, -1)                        
            root.act(delta)

        def fireEnterAndExit(overLast: Actor, screenX: int, screenY: int, pointer: int): Actor
            screenToStageCoordinates(tempCoords.@set(screenX, screenY))
            var over = hit(tempCoords.x, tempCoords.y, true)
            if over == overLast do return overLast
            if overLast != null
                var event = (InputEvent)Pools.obtain(typeof(InputEvent))
                event.setStage(this)
                event.setStageX(tempCoords.x)
                event.setStageY(tempCoords.y)
                event.setPointer(pointer)
                event.setType(InputEventType.exit)
                event.setRelatedActor(over)
                overLast.fire(event)
                Pools.free(event)

            if over != null
                var event = (InputEvent)Pools.obtain(typeof(InputEvent))
                event.setStage(this)
                event.setStageX(tempCoords.x)
                event.setStageY(tempCoords.y)
                event.setPointer(pointer)
                event.setType(InputEventType.enter)
                event.setRelatedActor(overLast)
                over.fire(event)
                Pools.free(event)
            return over

        def touchDown(screenX: int, screenY: int, pointer: int, button: int): bool
            if screenX < viewport.screenX || screenX >= viewport.screenX + viewport.screenWidth            
            // if (Gdx.graphics.getHeight() - screenY < viewport.getScreenY()
            //     || Gdx.graphics.getHeight() - screenY >= viewport.getScreenY() + viewport.getScreenHeight()) return false

            pointerTouched[pointer] = true
            pointerScreenX[pointer] = screenX
            pointerScreenY[pointer] = screenY

            screenToStageCoordinates(tempCoords.@set(screenX, screenY))

            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setType(InputEventType.touchDown)
            event.setStage(this)
            event.setStageX(tempCoords.x)
            event.setStageY(tempCoords.y)
            event.setPointer(pointer)
            event.setButton(button)

            var target = hit(tempCoords.x, tempCoords.y, true)
            if target == null
                if root.touchable == Touchable.enabled do root.fire(event)
            else
                target.fire(event)

            var handled = event.isHandled()
            Pools.free(event)
            return handled

        def touchDragged(screenX: int, screenY: int, pointer: int): bool
            pointerScreenX[pointer] = screenX
            pointerScreenY[pointer] = screenY
            mouseScreenX = screenX
            mouseScreenY = screenY

            if touchFocuses.size == 0 do return false

            screenToStageCoordinates(tempCoords.@set(screenX, screenY))

            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setType(InputEventType.touchDragged)
            event.setStage(this)
            event.setStageX(tempCoords.x)
            event.setStageY(tempCoords.y)
            event.setPointer(pointer)

            //var focuses = touchFocuses.begin()
            for var focus in touchFocuses
                if focus.pointer != pointer do continue
                if !touchFocuses.contains(focus) do continue // Touch focus already gone.
                event.setTarget(focus.target)
                event.setListenerActor(focus.listenerActor)
                if focus.listener.handle(event) do event.handle()
            //touchFocuses.end()

            var handled = event.isHandled()
            Pools.free(event)
            return handled
            
        def touchUp(screenX: int, screenY: int, pointer: int, button: int): bool
            pointerTouched[pointer] = false
            pointerScreenX[pointer] = screenX
            pointerScreenY[pointer] = screenY

            if touchFocuses.size == 0 do return false

            screenToStageCoordinates(tempCoords.@set(screenX, screenY))

            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setType(InputEventType.touchUp)
            event.setStage(this)
            event.setStageX(tempCoords.x)
            event.setStageY(tempCoords.y)
            event.setPointer(pointer)
            event.setButton(button)

            //var focuses = touchFocuses.begin()
            for var focus in touchFocuses
                if focus.pointer != pointer || focus.button != button do continue
                if !touchFocuses.remove(focus) do continue // Touch focus already gone.
                event.setTarget(focus.target)
                event.setListenerActor(focus.listenerActor)
                if focus.listener.handle(event) do event.handle()
                Pools.free(focus)
            
            //touchFocuses.end()

            var handled = event.isHandled()
            Pools.free(event)
            return handled

        def mouseMoved(screenX: int, screenY: int): bool
            if screenX < viewport.screenX || screenX >= viewport.screenX + viewport.screenWidth do return false
            // if (Gdx.graphics.getHeight() - screenY < viewport.getScreenY()
            //     || Gdx.graphics.getHeight() - screenY >= viewport.getScreenY() + viewport.getScreenHeight()) return false

            mouseScreenX = screenX
            mouseScreenY = screenY

            screenToStageCoordinates(tempCoords.@set(screenX, screenY))

            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setStage(this)
            event.setType(InputEventType.mouseMoved)
            event.setStageX(tempCoords.x)
            event.setStageY(tempCoords.y)

            var target = hit(tempCoords.x, tempCoords.y, true)
            if target == null do target = root

            target.fire(event)
            var handled = event.isHandled()
            Pools.free(event)
            return handled

        def scrolled(amount: int): bool 
            var target = scrollFocus == null ? root : scrollFocus

            screenToStageCoordinates(tempCoords.@set(mouseScreenX, mouseScreenY))

            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setStage(this)
            event.setType(InputEventType.scrolled)
            event.setScrollAmount(amount)
            event.setStageX(tempCoords.x)
            event.setStageY(tempCoords.y)
            target.fire(event)
            var handled = event.isHandled()
            Pools.free(event)
            return handled
                   
        def keyDown(keyCode: int): bool
            var target = keyboardFocus == null ? root : keyboardFocus
            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setStage(this)
            event.setType(InputEventType.keyDown)
            event.setKeyCode(keyCode)
            target.fire(event)
            var handled = event.isHandled()
            Pools.free(event)
            return handled
                            
        def keyUp(keyCode: int): bool
            var target = keyboardFocus == null ? root : keyboardFocus
            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setStage(this)
            event.setType(InputEventType.keyUp)
            event.setKeyCode(keyCode)
            target.fire(event)
            var handled = event.isHandled()
            Pools.free(event)
            return handled

        def keyTyped(character: char): bool
            var target = keyboardFocus == null ? root : keyboardFocus
            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setStage(this)
            event.setType(InputEventType.keyTyped)
            event.setCharacter(character)
            target.fire(event)
            var handled = event.isHandled()
            Pools.free(event)
            return handled
        
        def addTouchFocus(listener: EventListener, listenerActor: Actor, target: Actor, pointer: int, button: int)
            var focus = (TouchFocus)Pools.obtain(typeof(TouchFocus))
            focus.listenerActor = listenerActor
            focus.target = target
            focus.listener = listener
            focus.pointer = pointer
            focus.button = button
            touchFocuses.add(focus)

        def removeTouchFocus(listener: EventListener, listenerActor: Actor, target: Actor, pointer: int, button: int)
            for var focus in touchFocuses
                if (focus.listener == listener && focus.listenerActor == listenerActor 
                && focus.target == target && focus.pointer == pointer && focus.button == button)
                    touchFocuses.remove(focus)
                    Pools.free(focus)


        def cancelTouchFocus(actor: Actor = null)
            if actor == null
                cancelTouchFocusExcept(null, null)
            else
                var event = (InputEvent)Pools.obtain(typeof(InputEvent))
                event.setStage(this)
                event.setType(InputEventType.touchUp)
                event.setStageX(int.MIN)
                event.setStageY(int.MIN)
            
                for var focus in touchFocuses
                    if focus.listenerActor != actor do continue
                    if !touchFocuses.remove(focus) do continue // Touch focus already gone.
                    event.setTarget(focus.target)
                    event.setListenerActor(focus.listenerActor)
                    event.setPointer(focus.pointer)
                    event.setButton(focus.button)
                    focus.listener.handle(event)
                //touchFocuses.end()
                Pools.free(event)

        def cancelTouchFocusExcept(exceptListener: EventListener, exceptActor: Actor)
            var event = (InputEvent)Pools.obtain(typeof(InputEvent))
            event.setStage(this)
            event.setType(InputEventType.touchUp)
            event.setStageX(int.MIN)
            event.setStageY(int.MIN)

            for var focus in touchFocuses
                if focus.listener == exceptListener && focus.listenerActor == exceptActor do continue
                if !touchFocuses.remove(focus) do continue // Touch focus already gone.
                event.setTarget(focus.target)
                event.setListenerActor(focus.listenerActor)
                event.setPointer(focus.pointer)
                event.setButton(focus.button)
                focus.listener.handle(event)
            //touchFocuses.end()
            Pools.free(event)

        def addActor(actor: Actor)
            root.addActor(actor)

        def addAction(action: Action)
            root.addAction(action)

        def getActors(): list of Actor
            return root.children

        def addListener(listener: EventListener): bool
            return root.addListener(listener)

        def removeListener(listener: EventListener): bool
            return root.removeListener(listener)

        def addCaptureListener(listener: EventListener): bool
            return root.addCaptureListener(listener)

        def removeCaptureListener(listener: EventListener): bool
            return root.removeCaptureListener(listener)
        
        def clear()
            unfocusAll()
            root.clear()

        def unfocusAll () 
            setScrollFocus(null)
            setKeyboardFocus(null)
            cancelTouchFocus()
        
        def unfocus(actor: Actor)
            cancelTouchFocus(actor)
            if scrollFocus != null && scrollFocus.isDescendantOf(actor) do setScrollFocus(null)
            if keyboardFocus != null && keyboardFocus.isDescendantOf(actor) do setKeyboardFocus(null)

        def setKeyboardFocus(actor: Actor): bool
            if keyboardFocus == actor do return true
            var event = (FocusEvent)Pools.obtain(typeof(FocusEvent))
            event.setStage(this)
            event.setType(FocusEvent.FocusEventType.keyboard)
            var oldKeyboardFocus = keyboardFocus
            if oldKeyboardFocus != null
                event.setFocused(false)
                event.setRelatedActor(actor)
                oldKeyboardFocus.fire(event)
            
            var success = !event.isCancelled()
            if success
                keyboardFocus = actor
                if actor != null
                    event.setFocused(true)
                    event.setRelatedActor(oldKeyboardFocus)
                    actor.fire(event)
                    success = !event.isCancelled()
                    if !success do setKeyboardFocus(oldKeyboardFocus)

            Pools.free(event)
            return success

        def getKeyboardFocus(): Actor
            return keyboardFocus 
        
        def setScrollFocus(actor: Actor): bool
            if scrollFocus == actor do return true
            var event = (FocusEvent)Pools.obtain(typeof(FocusEvent))
            event.setStage(this)
            event.setType(FocusEvent.FocusEventType.scroll)
            var oldScrollFocus = scrollFocus
            if oldScrollFocus != null
                event.setFocused(false)
                event.setRelatedActor(actor)
                oldScrollFocus.fire(event)
            
            var success = !event.isCancelled()
            if success
                scrollFocus = actor
                if actor != null
                    event.setFocused(true)
                    event.setRelatedActor(oldScrollFocus)
                    actor.fire(event)
                    success = !event.isCancelled()
                    if !success do setScrollFocus(oldScrollFocus)

            Pools.free(event)
            return success

        def getScrollFocus(): Actor
            return scrollFocus

        def hit(stageX: double, stageY: double, touchable: bool): Actor
            root.parentToLocalCoordinates(tempCoords.@set(stageX, stageY))
            return root.hit(tempCoords.x, tempCoords.y, touchable)
            
        def screenToStageCoordinates(screenCoords: Vector2): Vector2
            // viewport.unproject(screenCoords);
            return screenCoords

        def stageToScreenCoordinates(stageCoords: Vector2): Vector2
            // viewport.project(stageCoords)
            stageCoords.y = viewport.screenHeight - stageCoords.y
            return stageCoords
        
            

        def dispose()
            pass 
