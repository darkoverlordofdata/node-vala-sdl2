/**
 * Color.gs
 *
 * Copyright 2016 Dark Overlord of Data
 * This library is free software you can redistribute it and/or
 * modify it under the terms of the he MIT License (MIT).
 *
 * Author: 
 *      bruce davidson
 */
[indent=4]
uses Gee
uses SDL
uses GLib

namespace sdx.graphics

    class Color:  Object

        prop r: double
        prop g: double
        prop b: double
        prop a: double

        r8: uint8
        g8: uint8
        b8: uint8
        a8: uint8
        /** 
         *  values
         */
        prop static readonly CLEAR          : Color = new Color.rgba(0, 0, 0, 0) 
        prop static readonly BLACK          : Color = new Color.rgba(0, 0, 0, 1)
        prop static readonly WHITE          : Color = new Color(0xffffffff)
        prop static readonly LIGHT_GRAY     : Color = new Color(0xbfbfbfff)
        prop static readonly GRAY           : Color = new Color(0x7f7f7fff)
        prop static readonly DARK_GRAY      : Color = new Color(0x3f3f3fff)
        prop static readonly BLUE           : Color = new Color.rgba(0, 0, 1, 1)
        prop static readonly NAVY           : Color = new Color.rgba(0, 0, 0.5f, 1)
        prop static readonly ROYAL          : Color = new Color(0x4169e1ff)
        prop static readonly SLATE          : Color = new Color(0x708090ff)
        prop static readonly SKY            : Color = new Color(0x87ceebff)
        prop static readonly CYAN           : Color = new Color.rgba(0, 1, 1, 1)
        prop static readonly TEAL           : Color = new Color.rgba(0, 0.5f, 0.5f, 1)
        prop static readonly GREEN          : Color = new Color(0x00ff00ff)
        prop static readonly CHARTREUSE     : Color = new Color(0x7fff00ff)
        prop static readonly LIME           : Color = new Color(0x32cd32ff)
        prop static readonly FOREST         : Color = new Color(0x228b22ff)
        prop static readonly OLIVE          : Color = new Color(0x6b8e23ff)
        prop static readonly YELLOW         : Color = new Color(0xffff00ff)
        prop static readonly GOLD           : Color = new Color(0xffd700ff)
        prop static readonly GOLDENROD      : Color = new Color(0xdaa520ff)
        prop static readonly ORANGE         : Color = new Color(0xffa500ff)
        prop static readonly BROWN          : Color = new Color(0x8b4513ff)
        prop static readonly TAN            : Color = new Color(0xd2b48cff)
        prop static readonly FIREBRICK      : Color = new Color(0xb22222ff)
        prop static readonly RED            : Color = new Color(0xff0000ff)
        prop static readonly SCARLET        : Color = new Color(0xff341cff)
        //prop static readonly CORAL          : Color = new Color(0xff7f50ff)
        prop static readonly SALMON         : Color = new Color(0xfa8072ff)
        prop static readonly PINK           : Color = new Color(0xff69b4ff)
        prop static readonly MAGENTA        : Color = new Color.rgba(1, 0, 1, 1)
        prop static readonly PURPLE         : Color = new Color(0xa020f0ff)
        prop static readonly VIOLET         : Color = new Color(0xee82eeff)
        prop static readonly MAROON         : Color = new Color(0xb03060ff)
        prop static readonly TransparentBlack: Color = new Color(0x00000000)
        prop static readonly TransparentWhite: Color = new Color(0xffffffff)
        prop static readonly AliceBlue       : Color = new Color(0xf8f0ffff)
        prop static readonly AntiqueWhite    : Color = new Color(0xD7EBD7FA)
        prop static readonly Aqua            : Color = new Color(0xFFFFFF00)
        prop static readonly Aquamarine      : Color = new Color(0xD4FFD47F)
        prop static readonly Azure           : Color = new Color(0xFFFFFFF0)
        prop static readonly Beige           : Color = new Color(0xdcf5dcf5)
        prop static readonly Bisque          : Color = new Color(0xc4e4c4ff)
        prop static readonly Black           : Color = new Color(0x00000000)
        prop static readonly BlanchedAlmond  : Color = new Color(0xcdebcdff)
        prop static readonly Blue            : Color = new Color(0xff00ff00)
        prop static readonly BlueViolet      : Color = new Color(0xe22be28a)
        prop static readonly Brown           : Color = new Color(0x2a2a2aa5)
        prop static readonly BurlyWood       : Color = new Color(0x87b887de)
        prop static readonly CadetBlue       : Color = new Color(0xa09ea05f)
        prop static readonly Chartreuse      : Color = new Color(0x00ff007f)
        prop static readonly Chocolate       : Color = new Color(0x1e691ed2)
        prop static readonly Coral           : Color = new Color(0x507f50ff)
        prop static readonly CornflowerBlue  : Color = new Color(0xed95ed64)
        prop static readonly Cornsilk        : Color = new Color(0xdcf8dcff)
        prop static readonly Crimson         : Color = new Color(0x3c143cdc)
        prop static readonly Cyan            : Color = new Color(0xffffff00)
        prop static readonly DarkBlue        : Color = new Color(0x8b008b00)
        prop static readonly DarkCyan        : Color = new Color(0x8b8b8b00)
        prop static readonly DarkGoldenrod   : Color = new Color(0x0b860bb8)
        prop static readonly DarkGray        : Color = new Color(0xa9a9a9a9)
        prop static readonly DarkGreen       : Color = new Color(0x00640000)
        prop static readonly DarkKhaki       : Color = new Color(0x6bb76bbd)
        prop static readonly DarkMagenta     : Color = new Color(0x8b008b8b)
        prop static readonly DarkOliveGreen  : Color = new Color(0x2f6b2f55)
        prop static readonly DarkOrange      : Color = new Color(0x008c00ff)
        prop static readonly DarkOrchid      : Color = new Color(0xcc32cc99)
        prop static readonly DarkRed         : Color = new Color(0x0000008b)
        prop static readonly DarkSalmon      : Color = new Color(0x7a967ae9)
        prop static readonly DarkSeaGreen    : Color = new Color(0x8bbc8b8f)
        prop static readonly DarkSlateBlue   : Color = new Color(0x8b3d8b48)
        prop static readonly DarkSlateGray   : Color = new Color(0x4f4f4f2f)
        prop static readonly DarkTurquoise   : Color = new Color(0xd1ced100)
        prop static readonly DarkViolet      : Color = new Color(0xd300d394)
        prop static readonly DeepPink        : Color = new Color(0x931493ff)
        prop static readonly DeepSkyBlue     : Color = new Color(0xffbfff00)
        prop static readonly DimGray         : Color = new Color(0x69696969)
        prop static readonly DodgerBlue      : Color = new Color(0xff90ff1e)
        prop static readonly Firebrick       : Color = new Color(0x222222b2)
        prop static readonly FloralWhite     : Color = new Color(0xf0faf0ff)
        prop static readonly ForestGreen     : Color = new Color(0x228b2222)
        prop static readonly Fuchsia         : Color = new Color(0xff00ffff)
        prop static readonly Gainsboro       : Color = new Color(0xdcdcdcdc)
        prop static readonly GhostWhite      : Color = new Color(0xfff8fff8)
        prop static readonly Gold            : Color = new Color(0x00d700ff)
        prop static readonly Goldenrod       : Color = new Color(0x20a520da)
        prop static readonly Gray            : Color = new Color(0x80808080)
        prop static readonly Green           : Color = new Color(0x00800000)
        prop static readonly GreenYellow     : Color = new Color(0x2fff2fad)
        prop static readonly Honeydew        : Color = new Color(0xf0fff0f0)
        prop static readonly HotPink         : Color = new Color(0xb469b4ff)
        prop static readonly IndianRed       : Color = new Color(0x5c5c5ccd)
        prop static readonly Indigo          : Color = new Color(0x8200824b)
        prop static readonly Ivory           : Color = new Color(0xf0fff0ff)
        prop static readonly Khaki           : Color = new Color(0x8ce68cf0)
        prop static readonly Lavender        : Color = new Color(0xfae6fae6)
        prop static readonly LavenderBlush   : Color = new Color(0xf5f0f5ff)
        prop static readonly LawnGreen       : Color = new Color(0x00fc007c)
        prop static readonly LemonChiffon    : Color = new Color(0xcdfacdff)
        prop static readonly LightBlue       : Color = new Color(0xe6d8e6ad)
        prop static readonly LightCoral      : Color = new Color(0x808080f0)
        prop static readonly LightCyan       : Color = new Color(0xffffffe0)
        prop static readonly LightGoldenrodYellow : Color = new Color(0xd2fad2fa)
        prop static readonly LightGray       : Color = new Color(0xd3d3d3d3)
        prop static readonly LightGreen      : Color = new Color(0x90ee9090)
        prop static readonly LightPink       : Color = new Color(0xc1b6c1ff)
        prop static readonly LightSalmon     : Color = new Color(0x7aa07aff)
        prop static readonly LightSeaGreen   : Color = new Color(0xaab2aa20)
        prop static readonly LightSkyBlue    : Color = new Color(0xfacefa87)
        prop static readonly LightSlateGray  : Color = new Color(0x99889977)
        prop static readonly LightSteelBlue  : Color = new Color(0xdec4deb0)
        prop static readonly LightYellow     : Color = new Color(0xe0ffe0ff)
        prop static readonly Lime            : Color = new Color(0x00ff0000)
        prop static readonly LimeGreen       : Color = new Color(0x32cd3232)
        prop static readonly Linen           : Color = new Color(0xe6f0e6fa)
        prop static readonly Magenta         : Color = new Color(0xff00ffff)
        prop static readonly Maroon          : Color = new Color(0x00000080)
        prop static readonly MediumAquamarine: Color = new Color(0xaacdaa66)
        prop static readonly MediumBlue      : Color = new Color(0xcd00cd00)
        prop static readonly MediumOrchid    : Color = new Color(0xd355d3ba)
        prop static readonly MediumPurple    : Color = new Color(0xdb70db93)
        prop static readonly MediumSeaGreen  : Color = new Color(0x71b3713c)
        prop static readonly MediumSlateBlue : Color = new Color(0xee68ee7b)
        prop static readonly MediumSpringGreen : Color = new Color(0x9afa9a00)
        prop static readonly MediumTurquoise : Color = new Color(0xccd1cc48)
        prop static readonly MediumVioletRed : Color = new Color(0x851585c7)
        prop static readonly MidnightBlue    : Color = new Color(0x70197019)
        prop static readonly MintCream       : Color = new Color(0xfafffaf5)
        prop static readonly MistyRose       : Color = new Color(0xe1e4e1ff)
        prop static readonly Moccasin        : Color = new Color(0xb5e4b5ff)
        prop static readonly MonoGameOrange  : Color = new Color(0x003c00e7)
        prop static readonly NavajoWhite     : Color = new Color(0xaddeadff)
        prop static readonly Navy            : Color = new Color(0x80008000)
        prop static readonly OldLace         : Color = new Color(0xe6f5e6fd)
        prop static readonly Olive           : Color = new Color(0x00800080)
        prop static readonly OliveDrab       : Color = new Color(0x238e236b)
        prop static readonly Orange          : Color = new Color(0x00a500ff)
        prop static readonly OrangeRed       : Color = new Color(0x004500ff)
        prop static readonly Orchid          : Color = new Color(0xd670d6da)
        prop static readonly PaleGoldenrod   : Color = new Color(0xaae8aaee)
        prop static readonly PaleGreen       : Color = new Color(0x98fb9898)
        prop static readonly PaleTurquoise   : Color = new Color(0xeeeeeeaf)
        prop static readonly PaleVioletRed   : Color = new Color(0x937093db)
        prop static readonly PapayaWhip      : Color = new Color(0xd5efd5ff)
        prop static readonly PeachPuff       : Color = new Color(0xb9dab9ff)
        prop static readonly Peru            : Color = new Color(0x3f853fcd)
        prop static readonly Pink            : Color = new Color(0xcbc0cbff)
        prop static readonly Plum            : Color = new Color(0xdda0dddd)
        prop static readonly PowderBlue      : Color = new Color(0xe6e0e6b0)
        prop static readonly Purple          : Color = new Color(0x80008080)
        prop static readonly Red             : Color = new Color(0x000000ff)
        prop static readonly RosyBrown       : Color = new Color(0x8f8f8fbc)
        prop static readonly RoyalBlue       : Color = new Color(0xe169e141)
        prop static readonly SaddleBrown     : Color = new Color(0x1345138b)
        prop static readonly Salmon          : Color = new Color(0x728072fa)
        prop static readonly SandyBrown      : Color = new Color(0x60a460f4)
        prop static readonly SeaGreen        : Color = new Color(0x578b572e)
        prop static readonly SeaShell        : Color = new Color(0xeef5eeff)
        prop static readonly Sienna          : Color = new Color(0x2d522da0)
        prop static readonly Silver          : Color = new Color(0xc0c0c0c0)
        prop static readonly SkyBlue         : Color = new Color(0xebceeb87)
        prop static readonly SlateBlue       : Color = new Color(0xcd5acd6a)
        prop static readonly SlateGray       : Color = new Color(0x90809070)
        prop static readonly Snow            : Color = new Color(0xfafafaff)
        prop static readonly SpringGreen     : Color = new Color(0x7fff7f00)
        prop static readonly SteelBlue       : Color = new Color(0xb482b446)
        prop static readonly Tan             : Color = new Color(0x8cb48cd2)
        prop static readonly Teal            : Color = new Color(0x80808000)
        prop static readonly Thistle         : Color = new Color(0xd8bfd8d8)
        prop static readonly Tomato          : Color = new Color(0x476347ff)
        prop static readonly Turquoise       : Color = new Color(0xd0e0d040)
        prop static readonly Violet          : Color = new Color(0xee82eeee)
        prop static readonly Wheat           : Color = new Color(0xb3deb3f5)
        prop static readonly White           : Color = new Color(0xFFFFFFFF)
        prop static readonly WhiteSmoke      : Color = new Color(0xf5f5f5f5)
        prop static readonly Yellow          : Color = new Color(0x00ff00ff)
        prop static readonly YellowGreen     : Color = new Color(0x32cd329a)


        construct(value: int64=0)
            
            r8 = (uint8) ((value & 0xff000000) >> 24)
            g8 = (uint8) ((value & 0x00ff0000) >> 16)
            b8 = (uint8) ((value & 0x0000ff00) >> 8)
            a8 = (uint8) ((value & 0x000000ff))
            this.r = r8 / 255
            this.g = g8 / 255
            this.b = b8 / 255
            this.a = a8 / 255

        construct rgba(r: double, g: double, b: double, a:double)

            r8 = (uint8) (255 * r)
            g8 = (uint8) (255 * g)
            b8 = (uint8) (255 * b)
            a8 = (uint8) (255 * a)
            this.r = r
            this.g = g
            this.b = b
            this.a = a
            clamp()

        construct clone(color: Color)   
            @set(color)


        def @set(color: Color): Color
            this.r = color.r
            this.g = color.g
            this.b = color.b
            this.a = color.a
            return this
            
            
        def clamp(): Color  
            if r < 0
                r = 0
            else if r > 1 do r = 1
            if g < 0
                g = 0
            else if g > 1 do g = 1
            if b < 0
                b = 0
            else if b > 1 do b = 1
            if a < 0
                a = 0
            else if a > 1 do a = 1
            return this

        // def toDoubleBits (): double
        //     int color = ((int)(255 * a) << 24) | ((int)(255 * b) << 16) | ((int)(255 * g) << 8) | ((int)(255 * r))
        //     return NumberUtils.intToFloatColor(color)
        // }
        def toIntBits(): int
            bits:int = ((int)(255 * a) << 24) | ((int)(255 * b) << 16) | ((int)(255 * g) << 8) | ((int)(255 * r))
            return bits
        

            