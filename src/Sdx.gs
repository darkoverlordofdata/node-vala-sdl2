/**
 * Sdx.gs
 *
 * Author: 
 *      bruce davidson
 */
[indent=4]
uses SDL
uses SDL.Video
namespace sdx

    def inline sdlFailIf(cond: bool, reason: string)
        if cond
            raise new Exception.SDLException(reason + ", SDL error: " + SDL.get_error())
            GLib.Process.exit(0)


    interface IApplication: Object
        prop abstract width:int
        prop abstract height:int
        prop abstract readonly renderer : unowned Renderer
        

    class Sdx : Object

        prop static readonly app: IApplication
        prop static readonly graphics: Graphics
        prop static readonly audio: Audio
        prop static readonly input: Input
        prop static readonly files: Files
        prop static readonly net: Net = new Net()

        construct(app: IApplication, width: int, height: int, base: string)
            _app = app
            app.width = width
            app.height = height
            _graphics = new Graphics().setSize(width, height)
            _audio = new Audio()
            _input = new Input()
            _files = new Files(base)
            new sdx.graphics.Color(0)
            print "Sdx is initialized."

        
