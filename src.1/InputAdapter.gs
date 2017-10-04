/**
 * InputAdapter.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx

    class InputAdapter : Object implements InputProcessor

        def keyDown(keycode: int): bool
            return false

        def keyUp(keycode: int): bool
            return false

        def keyTyped(character: char): bool
            return false

        def touchDown(screenX: int, screenY: int, pointer: int, button: int): bool
            return false

        def touchUp(screenX: int, screenY: int, pointer: int, button: int): bool
            return false

        def touchDragged(screenX: int, screenY: int, pointer: int): bool
            return false

        def mouseMoved(screenX: int, screenY: int): bool
            return false

        def scrolled(amount: int): bool
            return false
