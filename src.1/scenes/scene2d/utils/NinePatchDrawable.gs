/**
 * NinePatchDrawable.gs
 *
 * 
 *
 */
[indent=4]
uses sdx.graphics
uses sdx.graphics.s2d
namespace sdx.scenes.scene2d.utils

    class NinePatchDrawable : BaseDrawable // implements TransformDrawable

        patch: private NinePatch

        construct(patch: NinePatch?)
            super(null)
            setPatch(patch)

        construct drawable(drawable: NinePatchDrawable)
            super(drawable)
            setPatch(drawable.patch)

        def draw(batch: Batch, x: double, y: double, width: double, height: double) 
            patch.draw(batch, x, y, width, height)
        

        // def draw(Batch batch, x: double, y: double, originX: double, originY: double, width: double, height: double, scaleX: double, scaleY: double, rotation: double) 
        //     patch.draw(batch, x, y, originX, originY, width, height, scaleX, scaleY, rotation)
        

        def setPatch(patch: NinePatch) 
            this.patch = patch
        
            setMinWidth(patch.getTotalWidth())
            setMinHeight(patch.getTotalHeight())
            setTopHeight(patch.getPadTop())
            setRightWidth(patch.getPadRight())
            setBottomHeight(patch.getPadBottom())
            setLeftWidth(patch.getPadLeft())
        

        def getPatch(): NinePatch  
            return patch
        

        /** Creates a new drawable that renders the same as this drawable tinted the specified color. */
        def tint(tint: Color): NinePatchDrawable
            var drawable = new NinePatchDrawable.drawable(this)
            drawable.setPatch(new NinePatch.ninepatch(drawable.getPatch(), tint))
            return drawable
        
    