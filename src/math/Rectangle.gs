/**
 * Rectangle.gs
 *
 * 
 *
 */
[indent=4]
uses GLib

namespace sdx.math

    class Rectangle: Object
        x: double
        y: double
        width: double
        height: double

        construct(x:double=0, y:double=0, width:double=0, height:double=0)
            this.x = x
            this.y = y
            this.width = width
            this.height = height

        construct rectangle(rect:Rectangle)
            this.x = rect.x
            this.y = rect.y
            this.width = rect.width
            this.height = rect.height


            