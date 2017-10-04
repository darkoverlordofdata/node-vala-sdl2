/**
 * Vector2.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses GLib

namespace sdx.math

    class Vector2: Object

        prop static readonly X: Vector2 = new Vector2(1, 0)
        prop static readonly Y: Vector2 = new Vector2(0, 1)
        prop static readonly Zero: Vector2 = new Vector2(0, 0)

        x: double
        y: double

        construct(x: double=0, y:double=0)
            this.@set(x, y)

        construct vector(v: Vector2)
            this.@set(v.x, v.y)

        
        def setZero(): Vector2
            this.@set(0, 0)
            return this

        def @set(x: double, y:double): Vector2
            this.x = x
            this.y = y
            return this
