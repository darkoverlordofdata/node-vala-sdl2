/**
 * Align.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx.utils

    enum Align
        center = 1 << 0
        top = 1 << 1
        bottom = 1 << 2
        left = 1 << 3
        right = 1 << 4

        topLeft = top | left
        topRight = top | right
        bottomLeft = bottom | left
        bottomRight = bottom | right
    
    // class Align : Object

    //     prop static readonly center: int = 1 << 0
    //     prop static readonly top: int = 1 << 1
    //     prop static readonly bottom: int = 1 << 2
    //     prop static readonly left: int = 1 << 3
    //     prop static readonly right: int = 1 << 4

    //     prop static readonly topLeft: int = top | left
    //     prop static readonly topRight: int = top | right
    //     prop static readonly bottomLeft: int = bottom | left
    //     prop static readonly bottomRight: int = bottom | right
       