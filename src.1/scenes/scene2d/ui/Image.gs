/**
 * Image.gs
 *
 * 
 *
 */
[indent=4]
uses sdx.graphics
uses sdx.graphics.s2d
uses sdx.math
uses sdx.scenes.scene2d.utils
uses sdx.utils


namespace sdx.scenes.scene2d.ui

    class Image : Widget

        scaling: Scaling
        align: int = Align.center
        imageX: double
        imageY: double
        imageWidth: double
        imageHeight: double
        drawable: Drawable
        

        construct(drawable: Drawable=null, scaling:Scaling=Scaling.stretch, align:int=0)
            setDrawable(drawable)
            this.scaling = scaling
            this.align = align
            setSize(getPrefWidth(), getPrefHeight())

        construct region(region: TextureRegion)
            // this(new TextureRegionDrawable(region), Scaling.stretch, Align.center)
            setDrawable(new TextureRegionDrawable(region))
            this.scaling = scaling
            this.align = align
            setSize(getPrefWidth(), getPrefHeight())

        construct ninepatch(patch:NinePatch)
            var d = new NinePatchDrawable(patch)
            this(d, Scaling.stretch, Align.center)

        def layout()
            if drawable == null do return

            var regionWidth = drawable.getMinWidth()
            var regionHeight = drawable.getMinHeight()
            var width = getWidth()
            var height = getHeight()

            var size = scaling.apply(regionWidth, regionHeight, width, height)
            imageWidth = size.x
            imageHeight = size.y

            if (align & Align.left) != 0
                imageX = 0
            else if (align & Align.right) != 0
                imageX = (int)(width - imageWidth)
            else
                imageX = (int)(width / 2 - imageWidth / 2)

            if (align & Align.top) != 0
                imageY = (int)(height - imageHeight)
            else if (align & Align.bottom) != 0
                imageY = 0
            else
                imageY = (int)(height / 2 - imageHeight / 2)

        def draw(batch: Batch, parentAlpha: double)
            validate()

            batch.setColor(color.r, color.g, color.b, color.a * parentAlpha)

            var x = getX()
            var y = getY()
            var scaleX = getScaleX()
            var scaleY = getScaleY()

            // if drawable isa TransformDrawable {
            //     var rotation = getRotation()
            //     if scaleX != 1 || scaleY != 1 || rotation != 0
            //         ((TransformDrawable)drawable).draw(batch, x + imageX, y + imageY, getOriginX() - imageX, getOriginY() - imageY,
            //             imageWidth, imageHeight, scaleX, scaleY, rotation)
            //         return
            
            if drawable != null 
                drawable.draw(batch, x + imageX, y + imageY, imageWidth * scaleX, imageHeight * scaleY)
            
        def setDrawable(drawable: Drawable)
            if this.drawable == drawable do return
            if drawable != null
                if getPrefWidth() != drawable.getMinWidth() || getPrefHeight() != drawable.getMinHeight()
                    invalidateHierarchy()
            else
                invalidateHierarchy()
            this.drawable = drawable

        def getDrawable(): Drawable
            return drawable

        def setScaling(scaling: Scaling)
            // if scaling == null 
            //     raise new Exception.IllegalArgumentException("scaling cannot be null.")
            this.scaling = scaling
            invalidate()

        def setAlign(align: int)
            this.align = align
            invalidate()

        def getMinWidth(): double
            return 0

        def getMinHeight(): double
            return 0

        def getPrefWidth(): double
            if drawable != null do return drawable.getMinWidth()
            return 0

        def getPrefHeight(): double
            if (drawable != null) do return drawable.getMinHeight()
            return 0

        def getImageX(): double
            return imageX

        def getImageY(): double
            return imageY
            
        def getImageWidth(): double
            return imageWidth

        def getImageHeight(): double
            return imageHeight
            
                    


        