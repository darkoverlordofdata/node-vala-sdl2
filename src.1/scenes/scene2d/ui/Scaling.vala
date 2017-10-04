/**
 * Scaling.gs
 *
 * 
 *
 */
using sdx.math;

namespace sdx.scenes.scene2d.ui {

    public enum Scaling {
        fit,
        fill,
        fillX,
        fillY,
        stretch,
        stretchX,
        stretchY,
        none;

        public Vector2 apply(double sourceWidth, double sourceHeight, double targetWidth, double targetHeight) {

            Vector2 temp = new Vector2();
            switch (this) {
            case fit: {
                double targetRatio = targetHeight / targetWidth;
                double sourceRatio = sourceHeight / sourceWidth;
                double scale = targetRatio > sourceRatio ? targetWidth / sourceWidth : targetHeight / sourceHeight;
                temp.x = sourceWidth * scale;
                temp.y = sourceHeight * scale;
                break;
            }
            case fill: {
                double targetRatio = targetHeight / targetWidth;
                double sourceRatio = sourceHeight / sourceWidth;
                double scale = targetRatio < sourceRatio ? targetWidth / sourceWidth : targetHeight / sourceHeight;
                temp.x = sourceWidth * scale;
                temp.y = sourceHeight * scale;
                break;
            }
            case fillX: {
                double scale = targetWidth / sourceWidth;
                temp.x = sourceWidth * scale;
                temp.y = sourceHeight * scale;
                break;
            }
            case fillY: {
                double scale = targetHeight / sourceHeight;
                temp.x = sourceWidth * scale;
                temp.y = sourceHeight * scale;
                break;
            }
            case stretch:
                temp.x = targetWidth;
                temp.y = targetHeight;
                break;
            case stretchX:
                temp.x = targetWidth;
                temp.y = sourceHeight;
                break;
            case stretchY:
                temp.x = sourceWidth;
                temp.y = targetHeight;
                break;
            case none:
                temp.x = sourceWidth;
                temp.y = sourceHeight;
                break;
            }
            return temp;
        }

    }
}



        
