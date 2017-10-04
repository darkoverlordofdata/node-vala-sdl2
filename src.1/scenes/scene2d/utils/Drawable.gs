/**
 * Drawable.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses sdx.graphics.s2d

namespace sdx.scenes.scene2d.utils

    interface Drawable: Object

        def abstract draw(batch: Batch, x: double, y: double, width: double, height: double)
    
        def abstract getLeftWidth(): double

        def abstract setLeftWidth(leftWidth: double)

        def abstract getRightWidth(): double

        def abstract setRightWidth(rightWidth: double)

        def abstract getTopHeight(): double

        def abstract setTopHeight(topHeight: double)

        def abstract getBottomHeight(): double

        def abstract setBottomHeight(bottomHeight: double)

        def abstract getMinWidth(): double

        def abstract setMinWidth(minWidth: double)

        def abstract getMinHeight(): double

        def abstract setMinHeight(minHeight: double)
