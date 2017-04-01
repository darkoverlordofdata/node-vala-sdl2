/**
 * TextureRegionDrawable.gs
 *
 * 
 *
 */
[indent=4]
uses sdx.graphics.s2d

namespace sdx.scenes.scene2d.utils

    class TextureRegionDrawable : BaseDrawable // implements TransformDrawable

        region: TextureRegion

        construct(region: TextureRegion)
            if region == null do return
            setRegion(region)


        def setRegion(region: TextureRegion)
            this.region = region
            setMinWidth(region.regionWidth)
            setMinHeight(region.regionHeight)

        def getRegion(): TextureRegion
            return region
