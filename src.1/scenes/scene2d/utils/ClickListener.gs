/**
 * ClickListener.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses GLib
uses sdx
uses sdx.math

namespace sdx.scenes.scene2d.utils

    class ClickListener : InputListener

        prop static visualPressedDuration: double = 0.1
        prop button: int 
        prop tapCount: int
        prop readonly touchDownX: double = -1
        prop readonly touchDownY: double = -1
        prop readonly pressedPointer: int = -1
        prop readonly pressedButton: int = -1
        prop tapSquareSize: double = 14

        pressed: private bool
        over: private bool
        cancelled: private bool
        visualPressedTime: private int
        tapCountInterval: private int
        lastTapTime: private int

        construct()
            pass

        construct with_button(button: int)
            this.button = button

        def touchDown(event: InputEvent, x: float, y: float, pointer: int, button: int): bool
            return false

        def touchUp (event: InputEvent, x: float, y: float, pointer: int, button: int)
            pass

        def touchDragged (event: InputEvent, x: float, y: float, pointer: int)
            pass

        def enter (event: InputEvent, x: float, y: float, pointer: int, fromActor: Actor)
            pass

        def exit (event: InputEvent, x: float, y: float, pointer: int, toActor: Actor)
            pass

        def cancel()
            if pressedPointer == -1
                cancelled = true
                pressed = false
                
        def clicked(event: InputEvent, x:double, y:double)
            pass

        def isOver(actor: Actor, x:double, y:double): bool
            var hit = actor.hit(x, y, true)
            if hit == null || !hit.isDescendantOf(actor) do return inTapSquare(x, y)
            return true

        def inTapSquare(x:double, y:double): bool
            if touchDownX == -1 && touchDownY == -1 do return false
            return Math.fabs(x - touchDownX) < tapSquareSize && Math.fabs(y - touchDownY) < tapSquareSize

        def invalidateTapSquare()
            _touchDownX = -1
            _touchDownY = -1
        
        def isPressed(): bool
            return pressed

        def isVisualPressed(): bool
            if pressed do return true
            if visualPressedTime <= 0 do return false
            //if visualPressedTime > TimeUtils.millis() do return true
            visualPressedTime = 0
            return false
            
        // def isOver(): bool
        //     return over || pressed

        def setTapCountInterval(tapCountInterval: double)
            this.tapCountInterval = (int)(tapCountInterval * 1000000000l)

            
