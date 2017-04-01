
namespace sdx.graphics.s2d {

    public enum TextureFilter {
        Nearest,
        Linear,
        MipMap,
        MipMapNearestNearest,
        MipMapLinearNearest,
        MipMapNearestLinear,
        MipMapLinearLinear;
        public static TextureFilter from(string value) {
            switch (value)  {
                case "Nearest": return Nearest;
                case "Linear": return Linear;
                case "MipMap": return MipMap;
                case "MipMapNearestNearest": return MipMapNearestNearest;
                case "MipMapLinearNearest": return MipMapLinearNearest;
                case "MipMapNearestLinear": return MipMapNearestLinear;
                case "MipMapLinearLinear": return MipMapLinearLinear;
                default: assert_not_reached();
            }
        }

        public bool isMipMap() {
            return this != TextureFilter.Nearest && this != TextureFilter.Linear;
        }


        public string to_string() {
            switch (this) {
                case Nearest: return "Nearest";
                case Linear: return "Linear";
                case MipMap: return "MipMap";
                case MipMapNearestNearest: return "MipMapNearestNearest";
                case MipMapLinearNearest: return "MipMapLinearNearest";
                case MipMapNearestLinear: return "MipMapNearestLinear";
                case MipMapLinearLinear: return "MipMapLinearLinear";
                default: assert_not_reached();
            }
        }
    }


    public enum TextureWrap {
        ClampToEdge = 1,
        Repeat = 2;
        public static TextureWrap from(string value) {
            switch (value)  {
                case "ClampToEdge": return ClampToEdge;
                case "Repeat": return Repeat;
                default: assert_not_reached();
            }
        }
        public string to_string() {
            switch (this) {
                case ClampToEdge: return "ClampToEdge";
                case Repeat: return "Repeat";
                default: assert_not_reached();
            }
        }
    }

    public enum Format {
        Alpha,
        Intensity,
        LuminanceAlpha,
        RGB565,
        RGBA4444,
        RGB888,
        RGBA8888;
        public static Format from(string value) {
            switch (value)  {
                case "Alpha": return Alpha;
                case "Intensity": return Intensity;
                case "LuminanceAlpha": return LuminanceAlpha;
                case "RGB565": return RGB565;
                case "RGBA4444": return RGBA4444;
                case "RGB888": return RGB888;
                case "RGBA8888": return RGBA8888;
                default: assert_not_reached();
            }
        }
        public string to_string() {
            switch (this) {
                case Alpha: return "Alpha";
                case Intensity: return "Intensity";
                case LuminanceAlpha: return "LuminanceAlpha";
                case RGB565: return "RGB565";
                case RGBA4444: return "RGBA4444";
                case RGB888: return "RGB888";
                case RGBA8888: return "RGBA8888";
                default: assert_not_reached();
            }
        }

    }

}