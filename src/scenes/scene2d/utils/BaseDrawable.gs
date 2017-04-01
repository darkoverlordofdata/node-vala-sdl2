/**
 * BaseDrawable.gs
 *
 * 
 *
 */
[indent=4]

uses sdx.graphics.s2d

namespace sdx.scenes.scene2d.utils

    class BaseDrawable : Object implements Drawable

        name: string
        leftWidth: double
        rightWidth: double 
        topHeight: double 
        bottomHeight: double 
        minWidth: double 
        minHeight: double

        construct(drawable: Drawable? = null)
            if drawable == null do return
            if drawable isa BaseDrawable do name = ((BaseDrawable)drawable).name
            leftWidth = drawable.getLeftWidth()
            rightWidth = drawable.getRightWidth()
            topHeight = drawable.getTopHeight()
            bottomHeight = drawable.getBottomHeight()
            minWidth = drawable.getMinWidth()
            minHeight = drawable.getMinHeight()
            
            
        def draw(batch: Batch, x: double, y: double, width: double, height: double)
            pass
    
        def getLeftWidth(): double
            return leftWidth

        def setLeftWidth(leftWidth: double)
            this.leftWidth = leftWidth

        def getRightWidth(): double
            return rightWidth

        def setRightWidth(rightWidth: double)
            this.rightWidth = rightWidth

        def getTopHeight(): double
            return topHeight

        def setTopHeight(topHeight: double)
            this.topHeight = topHeight

        def getBottomHeight(): double
            return bottomHeight

        def setBottomHeight(bottomHeight: double)
            this.bottomHeight = bottomHeight

        def getMinWidth(): double
            return minWidth

        def setMinWidth(minWidth: double)
            this.minWidth = minWidth

        def getMinHeight(): double
            return minHeight

        def setMinHeight(minHeight: double)
            this.minHeight = minHeight

            
