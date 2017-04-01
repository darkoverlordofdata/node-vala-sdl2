/**
 * NinePatch.gs
 *
 */
[indent=4]
uses Gee
uses sdx.graphics

namespace sdx.graphics.s2d

    /**
     *  load a 9patch image
     */
    class NinePatch : Object
 
        const TOP_LEFT: int = 0
        const TOP_CENTER: int = 1
        const TOP_RIGHT: int = 2
        const MIDDLE_LEFT: int = 3
        const MIDDLE_CENTER: int = 4
        const MIDDLE_RIGHT: int = 5
        const BOTTOM_LEFT: int = 6
        const BOTTOM_CENTER: int = 7
        const BOTTOM_RIGHT: int = 8

        texture: Texture
        bottomLeft: int = -1
        bottomCenter: int = -1
        bottomRight: int = -1
        middleLeft: int = -1
        middleCenter: int = -1
        middleRight: int = -1
        topLeft: int = -1
        topCenter: int = -1
        topRight: int = -1

        leftWidth: double
        rightWidth: double
        middleWidth: double
        middleHeight: double
        topHeight: double
        bottomHeight: double

        vertices: array of double = new array of double[9 * 4 * 5]
        idx: int
        color: Color = new Color.clone(Color.WHITE)
        padLeft: double = -1
        padRight: double = -1
        padTop: double = -1
        padBottom: double = -1

        construct(region: TextureRegion, left: int, right: int, top: int, bottom: int)
            if region == null do raise new Exception.IllegalArgumentException("region cannot be null.")
            var middleWidth = region.getRegionWidth() - left - right
            var middleHeight = region.getRegionHeight() - top - bottom

            var patches = new array of TextureRegion[9]
            if top > 0
                if left > 0 do patches[TOP_LEFT] = new TextureRegion.region(region, 0, 0, left, top)
                if middleWidth > 0 do patches[TOP_CENTER] = new TextureRegion.region(region, left, 0, middleWidth, top)
                if right > 0 do patches[TOP_RIGHT] = new TextureRegion.region(region, left + middleWidth, 0, right, top)
            
            if middleHeight > 0
                if left > 0 do patches[MIDDLE_LEFT] = new TextureRegion.region(region, 0, top, left, middleHeight)
                if middleWidth > 0 do patches[MIDDLE_CENTER] = new TextureRegion.region(region, left, top, middleWidth, middleHeight)
                if right > 0 do patches[MIDDLE_RIGHT] = new TextureRegion.region(region, left + middleWidth, top, right, middleHeight)
            
            if bottom > 0
                if left > 0 do patches[BOTTOM_LEFT] = new TextureRegion.region(region, 0, top + middleHeight, left, bottom)
                if middleWidth > 0 do patches[BOTTOM_CENTER] = new TextureRegion.region(region, left, top + middleHeight, middleWidth, bottom)
                if right > 0 do patches[BOTTOM_RIGHT] = new TextureRegion.region(region, left + middleWidth, top + middleHeight, right, bottom)
            

            // If split only vertical, move splits from right to center.
            if left == 0 && middleWidth == 0
                patches[TOP_CENTER] = patches[TOP_RIGHT]
                patches[MIDDLE_CENTER] = patches[MIDDLE_RIGHT]
                patches[BOTTOM_CENTER] = patches[BOTTOM_RIGHT]
                patches[TOP_RIGHT] = null
                patches[MIDDLE_RIGHT] = null
                patches[BOTTOM_RIGHT] = null
            
            // If split only horizontal, move splits from bottom to center.
            if top == 0 && middleHeight == 0
                patches[MIDDLE_LEFT] = patches[BOTTOM_LEFT]
                patches[MIDDLE_CENTER] = patches[BOTTOM_CENTER]
                patches[MIDDLE_RIGHT] = patches[BOTTOM_RIGHT]
                patches[BOTTOM_LEFT] = null
                patches[BOTTOM_CENTER] = null
                patches[BOTTOM_RIGHT] = null

            load(patches)
            
        // 'degenerate', i.e. only a center patch.
        // construct textureColor(texture: Texture, Color: color)
        //     this.texture(texture)
        //     setColor(color)
            
        // construct texture(texture: Texture)
        //     this.region(new TextureRegion(texture))

        // construct region(region: TextureRegion)

        // construct regionColor(region: TextureRegion, Color: color)
        //     this.region(region)
        //     setColor(color)
        construct textureXY(texture: Texture, left: int, right: int, top: int, bottom: int)
            this(new TextureRegion(texture), left, right, top, bottom)

        construct ninepatch(ninePatch: NinePatch, color:Color = null)
            texture = ninePatch.texture

            bottomLeft = ninePatch.bottomLeft
            bottomCenter = ninePatch.bottomCenter
            bottomRight = ninePatch.bottomRight
            middleLeft = ninePatch.middleLeft
            middleCenter = ninePatch.middleCenter
            middleRight = ninePatch.middleRight
            topLeft = ninePatch.topLeft
            topCenter = ninePatch.topCenter
            topRight = ninePatch.topRight

            leftWidth = ninePatch.leftWidth
            rightWidth = ninePatch.rightWidth
            middleWidth = ninePatch.middleWidth
            middleHeight = ninePatch.middleHeight
            topHeight = ninePatch.topHeight
            bottomHeight = ninePatch.bottomHeight

            padLeft = ninePatch.padLeft
            padTop = ninePatch.padTop
            padBottom = ninePatch.padBottom
            padRight = ninePatch.padRight
            
            vertices = new array of double[ninePatch.vertices.length]
            //System.arraycopy(vertices, 0, newVertices, 0, idx)
            for var i=0 to (ninePatch.vertices.length-1)
                vertices[i] = vertices[i]
            idx = ninePatch.idx
            if color == null  
                this.color.@set(ninePatch.color)
            else
                this.color.@set(color)

        def load(patches: array of TextureRegion)
            var color = Color.WHITE.toIntBits()

            if patches[BOTTOM_LEFT] != null 
                bottomLeft = add(patches[BOTTOM_LEFT], color, false, false)
                leftWidth = patches[BOTTOM_LEFT].getRegionWidth()
                bottomHeight = patches[BOTTOM_LEFT].getRegionHeight()
            
            if patches[BOTTOM_CENTER] != null 
                bottomCenter = add(patches[BOTTOM_CENTER], color, true, false)
                middleWidth = (int)Math.fmax(middleWidth, patches[BOTTOM_CENTER].getRegionWidth())
                bottomHeight = (int)Math.fmax(bottomHeight, patches[BOTTOM_CENTER].getRegionHeight())
            
            if patches[BOTTOM_RIGHT] != null 
                bottomRight = add(patches[BOTTOM_RIGHT], color, false, false)
                rightWidth = (int)Math.fmax(rightWidth, patches[BOTTOM_RIGHT].getRegionWidth())
                bottomHeight = (int)Math.fmax(bottomHeight, patches[BOTTOM_RIGHT].getRegionHeight())
            
            if patches[MIDDLE_LEFT] != null 
                middleLeft = add(patches[MIDDLE_LEFT], color, false, true)
                leftWidth = (int)Math.fmax(leftWidth, patches[MIDDLE_LEFT].getRegionWidth())
                middleHeight = (int)Math.fmax(middleHeight, patches[MIDDLE_LEFT].getRegionHeight())
            
            if patches[MIDDLE_CENTER] != null 
                middleCenter = add(patches[MIDDLE_CENTER], color, true, true)
                middleWidth = (int)Math.fmax(middleWidth, patches[MIDDLE_CENTER].getRegionWidth())
                middleHeight = (int)Math.fmax(middleHeight, patches[MIDDLE_CENTER].getRegionHeight())
            
            if patches[MIDDLE_RIGHT] != null 
                middleRight = add(patches[MIDDLE_RIGHT], color, false, true)
                rightWidth = (int)Math.fmax(rightWidth, patches[MIDDLE_RIGHT].getRegionWidth())
                middleHeight = (int)Math.fmax(middleHeight, patches[MIDDLE_RIGHT].getRegionHeight())
            
            if patches[TOP_LEFT] != null 
                topLeft = add(patches[TOP_LEFT], color, false, false)
                leftWidth = (int)Math.fmax(leftWidth, patches[TOP_LEFT].getRegionWidth())
                topHeight = (int)Math.fmax(topHeight, patches[TOP_LEFT].getRegionHeight())
            
            if patches[TOP_CENTER] != null 
                topCenter = add(patches[TOP_CENTER], color, true, false)
                middleWidth = (int)Math.fmax(middleWidth, patches[TOP_CENTER].getRegionWidth())
                topHeight = (int)Math.fmax(topHeight, patches[TOP_CENTER].getRegionHeight())
            
            if patches[TOP_RIGHT] != null 
                topRight = add(patches[TOP_RIGHT], color, false, false)
                rightWidth = (int)Math.fmax(rightWidth, patches[TOP_RIGHT].getRegionWidth())
                topHeight = (int)Math.fmax(topHeight, patches[TOP_RIGHT].getRegionHeight())
            
            if idx < vertices.length 
                var newVertices = new array of double[idx]
                //System.arraycopy(vertices, 0, newVertices, 0, idx)
                for var i=0 to (idx-1)
                    newVertices[i] = vertices[i]
                vertices = newVertices
            
        
        def add(region: TextureRegion, color: double, isStretchW: bool, isStretchH: bool): int
            if texture == null
                texture = region.texture
            else if texture != region.texture //
                raise new Exception.IllegalArgumentException("All regions must be from the same texture.")

            var u = region.u
            var v = region.v2
            var u2 = region.u2
            var v2 = region.v

            // Add half pixel offsets on stretchable dimensions to acolor bleeding when GL_LINEAR
            // filtering is used for the texture. This nudges the texture coordinate to the center
            // of the texel where the neighboring pixel has 0% contribution in linear blending mode.
            if isStretchW
                var halfTexelWidth = 0.5f * 1.0f / texture.width
                u += halfTexelWidth
                u2 -= halfTexelWidth
            
            if isStretchH
                var halfTexelHeight = 0.5f * 1.0f / texture.height
                v -= halfTexelHeight
                v2 += halfTexelHeight
            
            return idx
            
        def draw(batch:Batch, x: double, y: double, width: double, height: double)
            pass

        def setColor(color: Color)
            this.color.@set(color)

        def getColor(): Color
            return color

        def getLeftWidth(): double 
            return leftWidth

        /** Set the draw-time width of the three left edge patches */
        def setLeftWidth(leftWidth: double) 
            this.leftWidth = leftWidth

        def getRightWidth(): double
            return rightWidth

        /** Set the draw-time width of the three right edge patches */
        def setRightWidth(rightWidth: double) 
            this.rightWidth = rightWidth

        def getTopHeight(): double
            return topHeight

        /** Set the draw-time height of the three top edge patches */
        def setTopHeight(topHeight: double) 
            this.topHeight = topHeight

        def getBottomHeight(): double
            return bottomHeight

        /** Set the draw-time height of the three bottom edge patches */
        def setBottomHeight(bottomHeight: double) 
            this.bottomHeight = bottomHeight

        def getMiddleWidth(): double
            return middleWidth

        /** Set the width of the middle column of the patch. At render time, this is implicitly the requested render-width of the
        * entire nine patch, minus the left and right width. This value is only used for computing the @link #getTotalWidth() default
        * total width. */
        def setMiddleWidth(middleWidth: double) 
            this.middleWidth = middleWidth

        def getMiddleHeight(): double
            return middleHeight

        /** Set the height of the middle row of the patch. At render time, this is implicitly the requested render-height of the entire
        * nine patch, minus the top and bottom height. This value is only used for computing the @link #getTotalHeight() default
        * total height. */
        def setMiddleHeight(middleHeight: double) 
            this.middleHeight = middleHeight

        def getTotalWidth(): double
            return leftWidth + middleWidth + rightWidth

        def getTotalHeight(): double
            return topHeight + middleHeight + bottomHeight

        /** Set the padding for content inside this ninepatch. By default the padding is set to match the exterior of the ninepatch, so
        * the content should fit exactly within the middle patch. */
        def setPadding(left: double, right: double, top: double, bottom: double) 
            this.padLeft = left
            this.padRight = right
            this.padTop = top
            this.padBottom = bottom

        /** Returns the left padding if set, else returns @link #getLeftWidth(). */
        def getPadLeft(): double
            if padLeft == -1 do return getLeftWidth()
            return padLeft

        /** See @link #setPadding(float, float, float, float) */
        def setPadLeft(left: double) 
            this.padLeft = left

        /** Returns the right padding if set, else returns @link #getRightWidth(). */
        def getPadRight(): double
            if padRight == -1 do return getRightWidth()
            return padRight

        /** See @link #setPadding(float, float, float, float) */
        def setPadRight(right: double) 
            this.padRight = right

        /** Returns the top padding if set, else returns @link #getTopHeight(). */
        def getPadTop(): double
            if padTop == -1 do return getTopHeight()
            return padTop

        /** See @link #setPadding(float, float, float, float) */
        def setPadTop(top: double) 
            this.padTop = top

        /** Returns the bottom padding if set, else returns @link #getBottomHeight(). */
        def getPadBottom(): double
            if padBottom == -1 do return getBottomHeight()
            return padBottom

        /** See @link #setPadding(float, float, float, float) */
        def setPadBottom(bottom: double) 
            this.padBottom = bottom

        /** Multiplies the top/left/bottom/right sizes and padding by the specified amount. */
        def scale(scaleX: double, scaleY: double) 
            leftWidth *= scaleX
            rightWidth *= scaleX
            topHeight *= scaleY
            bottomHeight *= scaleY
            middleWidth *= scaleX
            middleHeight *= scaleY
            if padLeft != -1 do padLeft *= scaleX
            if padRight != -1 do padRight *= scaleX
            if padTop != -1 do padTop *= scaleY
            if padBottom != -1 do padBottom *= scaleY
        
        