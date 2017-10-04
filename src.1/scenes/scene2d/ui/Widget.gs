/**
 * Widget.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses sdx.graphics.s2d
uses sdx.scenes.scene2d.utils

namespace sdx.scenes.scene2d.ui

    class Widget : Actor implements Layout 

        needsLayout: private bool = true
        fillParent: private bool
        layoutEnabled: private bool = true

        def getMinWidth(): double
            return getPrefWidth()

        def getMinHeight(): double
            return getPrefHeight()

        def getPrefWidth(): double
            return 0

        def getPrefHeight(): double
            return 0

        def getMaxWidth(): double
            return 0

        def getMaxHeight(): double
            return 0

        def setLayoutEnabled(enabled: bool)
            layoutEnabled = enabled
            if enabled do invalidateHierarchy()
        
        def validate()
            if !layoutEnabled do return

            if fillParent && parent != null
                var parentWidth = 0.0
                var parentHeight = 0.0
                if stage != null && parent == stage.root
                    parentWidth = stage.width
                    parentHeight = stage.height
                else
                    parentWidth = parent.getWidth()
                    parentHeight = parent.getHeight()
                setSize(parentWidth, parentHeight)

            if !needsLayout do return
            needsLayout = false
            layout()

        def invalidate()
            needsLayout = true
            
        def invalidateHierarchy()
            if !layoutEnabled do return
            invalidate()
            if parent isa Layout do ((Layout)parent).invalidateHierarchy()

        def sizeChanged()
            invalidate()

        def pack()
            setSize(getPrefWidth(), getPrefHeight())
            validate()

        def setFillParent(fillParent: bool)
            this.fillParent = fillParent

        def draw(batch: Batch, parentAlpha: double)
            validate()

        def layout()
            pass
