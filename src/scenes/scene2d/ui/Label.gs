/**
 * Label.gs
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

    class Label : Widget

        text: string
        _style: LabelStyle
        labelAlign: int = Align.left
        lineAlign: int = Align.left

        construct(text: string, style: LabelStyle)
            this.text = text
            setStyle(style)
            if text != null && text.length > 0 do setSize(getPrefWidth(), getPrefHeight())


            
        // construct style(text: string, font: string, color: Color, size: int)
        //     this(text, new LabelStyle(sdx.Font.fromFile(font, size), color))


        class static LabelStyle : Object
            font: Font
            fontColor: Color
            construct(font: Font, color: Color)
                this.font = font
                this.fontColor = color


             
        def layout()
            var textSurface = _style.font.render(text, _style.fontColor)
            var texture = SDL.Video.Texture.create_from_surface(Sdx.app.renderer, textSurface)            
            sdlFailIf(texture == null, "Unable to load image texture Label.layout!")

        def draw(batch: Batch, parentAlpha: double)
            pass

        def setStyle(style: LabelStyle)
            if style == null
                raise new Exception.IllegalArgumentException("style cannot be null.")
            if style.font == null
                raise new Exception.IllegalArgumentException("Missing LabelStyle font.")
            _style = style
            invalidateHierarchy()

        def getStyle(): LabelStyle
            return _style

        def setText(newText: string)
            if text == newText do return
            this.text = newText
            invalidateHierarchy()
            
        def textEquals(other: string): bool
            return text == other
        
        def getText(): string
            return text

        def setAlignment(labelAlign: int, lineAlign: int=-1)
            if lineAlign==-1 do lineAlign = labelAlign
            this.labelAlign = labelAlign

            if (lineAlign & Align.left) != 0
                this.lineAlign = Align.left
            else if (lineAlign & Align.right) != 0
                this.lineAlign = Align.right
            else
                this.lineAlign = Align.center

            invalidate()
            


        

        