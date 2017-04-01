/**
 * InputListener.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses sdx
uses sdx.math

namespace sdx.scenes.scene2d

    class InputListener : Object implements EventListener
        prop static private tmpCoords: Vector2 = new Vector2()

        def handle(e: Event): bool
            var event = e as InputEvent
            if event == null do return false
            case event.getType()
                when InputEventType.keyDown
                    return keyDown(event, event.getKeyCode())
                
                when InputEventType.keyUp
                    return keyUp(event, event.getKeyCode())

                when InputEventType.keyTyped
                    return keyTyped(event, (char)(event.getKeyCode()))

            event.toCoordinates(event.getListenerActor(), tmpCoords)

            case event.getType()
                when InputEventType.touchDown
                    return touchDown(event, tmpCoords.x, tmpCoords.y, event.getPointer(), event.getButton())
                when InputEventType.touchUp
                    touchUp(event, tmpCoords.x, tmpCoords.y, event.getPointer(), event.getButton())
                    return true
                when InputEventType.touchDragged
                    touchDragged(event, tmpCoords.x, tmpCoords.y, event.getPointer())
                    return true
                when InputEventType.mouseMoved
                    return mouseMoved(event, tmpCoords.x, tmpCoords.y)
                when InputEventType.scrolled
                    return scrolled(event, tmpCoords.x, tmpCoords.y, event.getScrollAmount())
                when InputEventType.enter
                    enter(event, tmpCoords.x, tmpCoords.y, event.getPointer(), event.getRelatedActor())
                    return false
                when InputEventType.exit
                    exit(event, tmpCoords.x, tmpCoords.y, event.getPointer(), event.getRelatedActor())
                    return false
            return false
        
        def touchDown(event: InputEvent, x: double, y: double, pointer: int, button: int): bool
            return false

        def touchUp (event: InputEvent, x: double, y: double, pointer: int, button: int)
            pass

        def touchDragged (event: InputEvent, x: double, y: double, pointer: int)
            pass

        def mouseMoved (event: InputEvent, x: double, y: double): bool
            return false

        def enter (event: InputEvent, x: double, y: double, pointer: int, fromActor: Actor)
            pass

        def exit (event: InputEvent, x: double, y: double, pointer: int, toActor: Actor)
            pass

        def scrolled (event: InputEvent, x: double, y: double, amount: int): bool
            return false

        def keyDown (event: InputEvent, keycode: int): bool
            return false

        def keyUp (event: InputEvent, keycode: int): bool
            return false

        def keyTyped (event: InputEvent, character: char): bool
            return false
