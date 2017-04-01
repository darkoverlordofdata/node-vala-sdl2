/**
 * GlyphLayout.gs
 *
 */
[indent=4]
uses GLib
uses sdx
uses sdx.utils
uses sdx.files
uses sdx.graphics
namespace sdx.graphics.s2d

    class GlyphLayout : Object implements Poolable

        runs: list of GlyphRun = new list of GlyphRun
        width: double
        height: double
        colorStack: list of Color

        construct(font: BitmapFont?=null, str: string, color: Color?=null, targetWidth: double=0, halign: double=0, wrap: bool=false, truncate: string=null)
            setText(font, str, 0, str.length, color, targetWidth, halign, wrap, truncate)


        class static GlyphRun : Object implements Poolable

            glyphs: list of BitmapFont.Glyph = new list of BitmapFont.Glyph

            xAdvances: list of double?

            x: double
            y: double
            width: double

            color: Color = new Color()

            def reset()
                glyphs.clear()
                xAdvances.clear()
                width = 0

        def setText(font: BitmapFont, str: string, start: int, end: int, color: Color?=null, targetWidth: double=0, halign: double=0, wrap: bool=false, truncate: string=null)
            if truncate != null
                wrap = true
            else if targetWidth <= font.data.spaceWidth
                wrap = false
            
            var fontData = font.data
            var markupEnabled = fontData.markupEnabled

            var glyphRunPool  = Pools.@get(typeof(GlyphRun)) 
            for var run in runs do glyphRunPool.free(run)
            runs.clear()

            var x = 0.0
            var y = 0.0
            var width = 0.0
            var lines = 0
            var blankLines = 0

            var nextColor = color
            colorStack.add(color)
            var colorPool = Pools.@get(typeof(Color))

            var runStart = start
            while true
                var runEnd = -1
                var newline = false
                var colorRun = false
                if start == end
                    if runStart == end do break // End of string with no run to process, we're done.
                    runEnd = end // End of string, process last run.
                else
                    case str[start++]
                        when '\n'
                            runEnd = start - 1
                            newline = true
                        when '['
                            if markupEnabled
                                var length = parseColorMarkup(str, start, end, colorPool)
                                if length >= 0
                                    runEnd = start - 1
                                    start += length + 1
                                    nextColor = colorStack.last()
                                    colorRun = true
                                else if length == -2
                                    start++ // Skip first of "[[" escape sequence.
                                    continue
                            
                if runEnd != -1
                    if runEnd != runStart // Can happen (eg) when a color tag is at text start or a line is "\n".
                        // Store the run that has ended.
                        var run = (GlyphRun)glyphRunPool.obtain()
                        run.color.@set(color)
                        run.x = x
                        run.y = y
                        fontData.getGlyphs(run, str, runStart, runEnd, colorRun)
                        if run.glyphs.size == 0
                            glyphRunPool.free(run)
                        else
                            runs.add(run)

                            // Compute the run width, wrap if necessary, and position the run.
                            var xAdvances = run.xAdvances
                            var n = xAdvances.size
                            for var i = 0 to (n-1)
                                var xAdvance = xAdvances[i]
                                x += xAdvance

                                // Don't wrap if the glyph would fit with just its width (no xadvance or kerning).
                                if wrap && x > targetWidth && i > 1 && x - xAdvance + (run.glyphs.@get(i - 1).xoffset + run.glyphs.@get(i - 1).width) * fontData.scaleX - 0.0001 > targetWidth

                                    if truncate != null
                                        this.truncate(fontData, run, targetWidth, truncate, i, glyphRunPool)
                                        x = run.x + run.width
                                        break
                                    

                                    var wrapIndex = fontData.getWrapIndex(i, run.glyphs)
                                    if (run.x == 0 && wrapIndex == 0) || wrapIndex >= run.glyphs.size
                                        wrapIndex = i - 1
                                    

                                    next: GlyphRun 
                                    if wrapIndex == 0
                                        next = run // No wrap index, move entire run to next line.
                                    else 
                                        next = this.wrap(fontData, run, glyphRunPool, wrapIndex, i)
                                        runs.add(next)
                                    

                                    // Start the loop over with the new run on the next line.
                                    width = Math.fmax(width, run.x + run.width)
                                    x = 0
                                    y += fontData.down
                                    lines++
                                    next.x = 0
                                    next.y = y
                                    i = -1
                                    n = next.xAdvances.size
                                    xAdvances = next.xAdvances
                                    run = next
                                else
                                    run.width += xAdvance

                    if newline
                        // Next run will be on the next line.
                        width = Math.fmax(width, x)
                        x = 0
                        var down = fontData.down
                        if runEnd == runStart // Blank line.
                            down *= fontData.blankLineScale
                            blankLines++
                        else
                            lines++
                        y += down

                    runStart = start
                    color = nextColor
                            
                
        def truncate(fontData: BitmapFont.BitmapFontData, run: GlyphRun, targetWidth: double, truncate: string, widthIndex: int, glyphRunPool: Pool)
            pass


        def parseColorMarkup(str: string, start: int, end:int, colorPool: Pool): int
            return 0


        def wrap(fontData: BitmapFont.BitmapFontData, first: GlyphRun, glyphRunPool: Pool, wrapIndex: int, widthIndex: int): GlyphRun
            return first

        def reset()
            pass
