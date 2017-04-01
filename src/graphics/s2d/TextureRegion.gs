/**
 * TextureRegion.gs
 *
 */
[indent=4]
uses Gee
uses GLib
uses sdx.graphics

namespace sdx.graphics.s2d

    class TextureRegion : Object
        prop texture: Texture
        prop top: int
        prop left: int
        prop width: int
        prop height: int
        prop regionWidth: int
        prop regionHeight: int
        prop u: double
        prop v: double
        prop u2: double
        prop v2: double

        construct(texture: Texture, x: int=0, y: int=0, width: int=0, height: int=0)
            width = width == 0 ? texture.width : width
            height = height == 0 ? texture.height : height
            _texture = texture
            _top = x
            _left = y
            _width = width
            _height = height 
            setRegionXY(x, y, width, height)

        construct region(region: TextureRegion, x: int=0, y: int=0, width: int=0, height: int=0)
            if width == 0 && height == 0
                texture = region.texture
                setRegion(region.u, region.v, region.u2, region.v2)
            else
                texture = region.texture
                setRegionXY(x, y, width, height)


        def setRegion(u: double, v: double, u2: double, v2: double)
            var texWidth = texture.width
            var texHeight = texture.height
            regionWidth =(int)Math.round(Math.fabs(u2 - u) * texWidth)
            regionHeight =(int)Math.round(Math.fabs(v2 - v) * texHeight)
            if regionWidth == 1 && regionHeight == 1
                var adjustX = 0.25 / texWidth
                u = adjustX
                u2 = adjustX
                var adjustY = 0.25 / texHeight
                v = adjustY
                v2 = adjustY

        def setRegionXY(x: int, y: int, width: int, height: int)
            var invTexWidth = 1 / texture.width
            var invTexHeight = 1 / texture.height
            setRegion(x * invTexWidth, y * invTexHeight,(x + width) * invTexWidth,(y + height) * invTexHeight)
            regionWidth =(int)Math.fabs(width)
            regionHeight =(int)Math.fabs(height)

        def setByRegion(region: TextureRegion)
            texture = region.texture
            setRegion(region.u, region.v, region.u2, region.v2)


        def setByRegionXY(region: TextureRegion, x: int, y: int, width: int, height: int)
            texture = region.texture
            setRegionXY(region.getRegionX()+x, region.getRegionY()+y, width, height)
            

        def flip(x: bool, y:bool)
            if(x) 
                var temp = u
                u = u2
                u2 = temp
            if(y) 
                var temp = v
                v = v2
                v2 = temp


        def getU(): double 
            return u
        

        def setU(u: double) 
            this.u = u
            regionWidth = (int)Math.round(Math.fabs(u2 - u) * texture.width)
        

        def getV(): double
            return v
        

        def setV(v: double) 
            this.v = v
            regionHeight = (int)Math.round(Math.fabs(v2 - v) * texture.height)
        

        def getU2(): double
            return u2
        

        def setU2(u2: double) 
            this.u2 = u2
            regionWidth = (int)Math.round(Math.fabs(u2 - u) * texture.width)
        

        def getV2(): double
            return v2
        

        def setV2(v2: double) 
            this.v2 = v2
            regionHeight = (int)Math.round(Math.fabs(v2 - v) * texture.height)
        

        def getRegionX(): int
            return (int)Math.round(u * texture.width)
        

        def setRegionX(x: int)
            setU(x /(double)texture.width)
        

        def getRegionY(): int
            return (int)Math.round(v * texture.height)
        

        def setRegionY(y: int) 
            setV(y /texture.height)
        

        /** Returns the region's width. */
        def getRegionWidth(): int
            return regionWidth
        

        def setRegionWidth(width: int) 
            if isFlipX()
                setU(u2 + width /(double)texture.width)
             else 
                setU2(u + width /(double)texture.width)
            
        

        /** Returns the region's height. */
        def getRegionHeight(): int
            return regionHeight
        

        def setRegionHeight(height: int) 
            if isFlipY()
                setV(v2 + height /(double)texture.height)	
             else 
                setV2(v + height /(double)texture.height)
            
        
        def isFlipX(): bool
            return u > u2
        

        def isFlipY(): bool
            return v > v2
        
