/**
 * Group.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses sdx
uses sdx.math
uses sdx.graphics.s2d

namespace sdx.scenes.scene2d

    interface Cullable
        def abstract setCullingArea(cullingArea: Rectangle)


    class Group : Actor implements Cullable

        prop children: list of Actor = new list of Actor 

        prop stage: Stage
            get
                return _stage
            set
                super.stage = value
                for var child in children
                    child.stage = value

        _stage: Stage
        cullingArea: private Rectangle
        transform: private bool = true
 
        def act(delta: double)
            super.act(delta);
            for var child in children
                child.act(delta)

        def draw(batch: Batch, parentAlpha: double)
            drawChildren(batch, parentAlpha)

        def drawChildren(batch: Batch, parentAlpha: double)
            //parentAlpha *= this.color.a
            if transform
                for var child in children
                    if child.isVisible() do child.draw(batch, parentAlpha)
            else
                var offsetX = x
                var offsetY = y
                x = 0
                y = 0
                for var child in children
                    if !!child.isVisible() do continue
                    var cx = child.x
                    var cy = child.y
                    child.x = cx + offsetX
                    child.y = cy + offsetY
                    child.draw(batch, parentAlpha)
                    child.x = cx
                    child.y = cy

                x = offsetX
                y = offsetY


        def setCullingArea(cullingArea: Rectangle)
            pass

        def getCullingArea(): Rectangle
            return null

        def hit(x: double, y: double, touchable: bool): Actor
            if touchable && this.touchable == Touchable.disabled do return null
            var v = new Vector2(x, y)
            for var child in children
                if !child.isVisible() do continue
                child.parentToLocalCoordinates(v)
                var ahit = child.hit(v.x, v.y, touchable)
                if ahit != null do return ahit
            return super.hit(x, y, touchable)

        def childrenChanged()
            pass

        def addActor(actor: Actor)
            if actor.parent != null
                if actor.parent == this do return
                actor.parent.removeActor(actor, false)
            children.add(actor)
            actor.parent = this
            actor.stage = stage
            childrenChanged()
            
        def addActorAt(index: int, actor: Actor)
            if actor.parent != null
                if actor.parent == this do return
                actor.parent.removeActor(actor, false)
            
            if index >= children.size
                children.add(actor)
            else
                children.insert(index, actor)
            actor.parent = this
            actor.stage = stage
            childrenChanged()

        def addActorBefore(actorBefore: Actor, actor: Actor)
            if actor.parent != null
                if actor.parent == this do return
                actor.parent.removeActor(actor, false)
            
            var index = children.index_of(actorBefore)
            children.insert(index, actor)
            actor.parent = this
            actor.stage = stage
            childrenChanged()

        def addActorAfter(actorAfter: Actor, actor: Actor)
            if actor.parent != null
                if actor.parent == this do return
                actor.parent.removeActor(actor, false)
            
            var index = children.index_of(actorAfter)
            if index == children.size
                children.add(actor)
            else
                children.insert(index + 1, actor)
            actor.parent = this
            actor.stage = stage
            childrenChanged()

        def removeActor(actor: Actor, unfocus: bool = true): bool
            if !children.remove(actor) do return false
            // if unfocus
            //     if stage != null do stage.unfocus(actor)
            
            actor.parent = null
            actor.stage = null
            childrenChanged()
            return true

        def clearChildren()
            for var child in children
                child.parent = null
                child.stage = null
            
            children.clear()
            childrenChanged()

        def clear()
            super.clear()
            clearChildren()

        def findActor(name: string): Actor
            for child in children
                if name == child.name do return child
            for child in children
                if child isa Group
                    var group = (Group)child
                    var actor = group.findActor(name)
                    if actor != null do return actor
            return null
        
        def hasChildren(): bool
            return children.size > 0

        def setTransform(transform: bool)    
            this.transform = transform

        def isTransform(): bool
            return transform

        def localToDescendantCoordinates(descendant: Actor, localCoords: Vector2): Vector2
            if descendant.parent == null
                raise new Exception.IllegalArgumentException("Child is not a descendant %s", descendant.name)
            if descendant.parent != this
                localToDescendantCoordinates(descendant.parent, localCoords)
            descendant.parentToLocalCoordinates(localCoords)
            return localCoords



