/**
 * InputProcessor.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx

    interface InputProcessor : Object
        def abstract keyDown(keycode: int): bool
        def abstract keyUp(keycode: int): bool
        def abstract keyTyped(character: char): bool
        def abstract touchDown(screenX: int, screenY: int, pointer: int, button: int): bool
        def abstract touchUp(screenX: int, screenY: int, pointer: int, button: int): bool
        def abstract touchDragged(screenX: int, screenY: int, pointer: int): bool
        def abstract mouseMoved(screenX: int, screenY: int): bool
        def abstract scrolled(amount: int): bool

        