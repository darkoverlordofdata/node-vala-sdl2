/**
 * Event.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses sdx
uses sdx.math
uses sdx.utils

namespace sdx.scenes.scene2d

    enum InputEventType 
        touchDown
        touchUp
        touchDragged
        mouseMoved
        enter
        exit
        scrolled
        keyDown
        keyUp
        keyTyped
        
    class InputEvent: Event implements Poolable
        type: InputEventType
        stageX: double
        stageY: double
        pointer: int
        button: int
        keyCode: int
        scrollAmount: int
        character: char
        relatedActor: Actor


        def reset() 
            super.reset()
            relatedActor = null
            button = -1

        /** The stage x coordinate where the event occurred. Valid for: touchDown, touchDragged, touchUp, mouseMoved, enter, and exit. */
        def getStageX(): double 
            return stageX

        def setStageX(stageX: double) 
            this.stageX = stageX

        /** The stage x coordinate where the event occurred. Valid for: touchDown, touchDragged, touchUp, mouseMoved, enter, and exit. */
        def getStageY(): double 
            return stageY

        def setStageY(stageY: double) 
            this.stageY = stageY

        /** The type of input event. */
        def getType(): InputEventType 
            return type

        def setType(type: InputEventType) 
            this.type = type

        /** The pointer index for the event. The first touch is index 0, second touch is index 1, etc. Always -1 on desktop. Valid for:
        * touchDown, touchDragged, touchUp, enter, and exit. */
        def getPointer(): int 
            return pointer

        def setPointer(pointer: int) 
            this.pointer = pointer

        /** The index for the mouse button pressed. Always 0 on Android. Valid for: touchDown and touchUp.
        * @see Buttons */
        def getButton(): int 
            return button

        def setButton(button: int) 
            this.button = button

        /** The key code of the key that was pressed. Valid for: keyDown and keyUp. */
        def getKeyCode(): int 
            return keyCode

        def setKeyCode(keyCode: int) 
            this.keyCode = keyCode

        /** The character for the key that was type. Valid for: keyTyped. */
        def getCharacter(): char 
            return character

        def setCharacter(character: char) 
            this.character = character

        /** The amount the mouse was scrolled. Valid for: scrolled. */
        def getScrollAmount(): int 
            return scrollAmount

        def setScrollAmount(scrollAmount: int) 
            this.scrollAmount = scrollAmount

        /** The actor related to the event. Valid for: enter and exit. For enter, this is the actor being exited, or null. For exit,
        * this is the actor being entered, or null. */
        def getRelatedActor(): Actor 
            return relatedActor

        /** @param relatedActor May be null. */
        def setRelatedActor(relatedActor: Actor) 
            this.relatedActor = relatedActor

        /** Sets actorCoords to this event's coordinates relative to the specified actor.
        * @param actorCoords Output for resulting coordinates. */
        def toCoordinates(actor: Actor, actorCoords: Vector2): Vector2
            actorCoords.@set(stageX, stageY)
            actor.stageToLocalCoordinates(actorCoords)
            return actorCoords

        /** Returns true of this event is a touchUp triggered by @link Stage#cancelTouchFocus(). */
        def isTouchFocusCancel():bool 
            return stageX == int.MIN || stageY == int.MIN

        def to_string(): string 
            return type.to_string()
