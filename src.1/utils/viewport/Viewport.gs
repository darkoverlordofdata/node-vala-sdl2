/**
 * Viewport.gs
 *
 * 
 *
 */
[indent=4]
uses Gee
uses sdx
uses sdx.math

namespace sdx.utils.viewport

    class Viewport
        worldWidth: double
        worldHeight: double
        screenX: int
        screenY: int
        screenWidth: int
        screenHeight: int


        def update(screenWidth: int, screenHeight: int)
            this.screenWidth = screenWidth
            this.screenHeight = screenHeight

            
