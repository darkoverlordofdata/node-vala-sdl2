/**
 * TransformDrawable.gs
 *
 * 
 *
 */
[indent=4]
uses sdx.graphics.s2d


namespace sdx.scenes.scene2d.utils

    interface TransformDrawable : Drawable
        def abstract draw(batch: Batch, x: double, y: double, originX: double, originY: double, width: double, height: double, scaleX: double, scaleY: double, rotation: double)
