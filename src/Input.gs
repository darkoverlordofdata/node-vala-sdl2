/**
 * Input.gs
 *
 * Author: 
 *      bruce davidson
 */
[indent=4]
namespace sdx

    class Input : Object

        prop readonly keys : array of uint8 = new array of uint8[255]
        processor: private InputProcessor
        evt : private SDL.Event

        enum Buttons
            LEFT
            RIGHT
            MIDDLE
            BACK
            FORWARD

        enum Keys // Map SDL definitions
            Esc = SDL.Input.Keycode.ESCAPE
            a = SDL.Input.Keycode.a
            b = SDL.Input.Keycode.b
            c = SDL.Input.Keycode.c
            d = SDL.Input.Keycode.d
            e = SDL.Input.Keycode.e
            f = SDL.Input.Keycode.f
            g = SDL.Input.Keycode.g
            h = SDL.Input.Keycode.h
            i = SDL.Input.Keycode.i
            j = SDL.Input.Keycode.j
            k = SDL.Input.Keycode.k
            l = SDL.Input.Keycode.l
            m = SDL.Input.Keycode.m
            n = SDL.Input.Keycode.n
            o = SDL.Input.Keycode.o
            p = SDL.Input.Keycode.p
            q = SDL.Input.Keycode.q
            r = SDL.Input.Keycode.r
            s = SDL.Input.Keycode.s
            t = SDL.Input.Keycode.t
            u = SDL.Input.Keycode.u
            v = SDL.Input.Keycode.v
            w = SDL.Input.Keycode.w
            x = SDL.Input.Keycode.x
            y = SDL.Input.Keycode.y
            z = SDL.Input.Keycode.z



        def setInputProcessor(processor: InputProcessor)
            this.processor = processor

        def processEvents(): bool
            if processor != null
                while SDL.Event.poll(out evt) != 0
                    case evt.type
                    
                        when  SDL.EventType.KEYDOWN
                            if evt.key.keysym.sym <= 255
                                keys[evt.key.keysym.sym] = 1
                                processor.keyDown(evt.key.keysym.sym)

                        when  SDL.EventType.KEYUP
                            if evt.key.keysym.sym <= 255
                                keys[evt.key.keysym.sym] = 0
                                processor.keyUp(evt.key.keysym.sym)

                        when  SDL.EventType.MOUSEMOTION
                            processor.touchDragged(evt.motion.x, evt.motion.y, 0)
                            processor.mouseMoved(evt.motion.x, evt.motion.y)

                        when  SDL.EventType.MOUSEBUTTONDOWN
                            processor.touchDown(evt.motion.x, evt.motion.y, 0, 0)

                        when  SDL.EventType.MOUSEBUTTONUP
                            processor.touchUp(evt.motion.x, evt.motion.y, 0, 0)

                        when SDL.EventType.QUIT
                            return false

            // return ((test++) == 0)  // run once
            return true
        //test: int 
