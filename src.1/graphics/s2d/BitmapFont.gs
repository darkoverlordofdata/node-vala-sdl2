/**
 * BitmapFont.gs
 *
 */
[indent=4]
uses GLib
uses sdx
uses sdx.files
uses sdx.utils
/**
 * parse the *.fnt file
 * use angelcode.com format
 */
namespace sdx.graphics.s2d

    class BitmapFont

        const LOG2_PAGE_SIZE: int = 9
        const PAGE_SIZE:int = 1 << LOG2_PAGE_SIZE
        const PAGES: int = 0x10000 / PAGE_SIZE

        data: BitmapFontData
        regions: list of TextureRegion


        class static Glyph
            id: int
            x: int
            y: int
            width: int
            height: int
            u: double
            v: double
            u2: double
            v2: double
            xoffset: int
            yoffset: int
            xadvance: int
            kerning: array of char[,]
            fixedWidth: bool
            page: int = 0

            def getKerning(ch: char): int
                if kerning != null
                    var i = ch >> LOG2_PAGE_SIZE
                    var j = ch & PAGE_SIZE - 1
                    return kerning[i,j]
                return 0

            def setKerning(ch: int, value: int)
                if kerning == null do kerning = new array of char[PAGES,PAGE_SIZE]
                var i = ch >> LOG2_PAGE_SIZE
                var j = ch & PAGE_SIZE - 1
                kerning[i,j] = (char)value
                
        class static BitmapFontData
            imagePaths: array of string
            fontFile: FileHandle
            flipped: bool
            padTop: double
            padRight: double
            padBottom: double
            padLeft: double
            lineHeight: double
            capHeight: double = 1
            ascent: double
            descent: double
            down: double
            blankLineScale: double = 1
            scaleX: double = 1
            scaleY: double = 1
            markupEnabled: bool
            cursorX: double
            glyphs: array of Glyph[,] = new array of Glyph[PAGES,PAGE_SIZE]
            missingGlyph: Glyph
            spaceWidth: double
            xHeight: double = 1
            breakChars: array of char[]
            xChars: array of char[] = {'x', 'e', 'a', 'o', 'n', 's', 'r', 'c', 'u', 'm', 'v', 'w', 'z'}
            capChars: array of char[] = {'M', 'N', 'B', 'D', 'C', 'E', 'F', 'K', 'A', 'G', 'H', 'I', 'J', 'L', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}

            construct(fontFile: FileHandle? = null, flip: bool = false)
                if fontFile != null
                    this.fontFile = fontFile
                    this.flipped = flip
                    load(fontFile, flip)

            def load(fontFile: FileHandle, flip: bool)
                if imagePaths != null do raise new Exception.IllegalStateException("Already loaded.")
                var reader = new DataInputStream(fontFile.read())
                try 

                    var line = reader.read_line()
                    if line == null do raise new Exception.SdxRuntimeException("File is empty.")

                    line = line.substring(line.index_of("padding=") + 8)
                    var padding = line.substring(0, line.index_of(" ")).split(",", 4)
                    if padding.length != 4 do raise new Exception.SdxRuntimeException("Invalid padding.")
                    padTop = int.parse(padding[0])
                    padRight = int.parse(padding[1])
                    padBottom = int.parse(padding[2])
                    padLeft = int.parse(padding[3])
                    var padY = padTop + padBottom

                    line = reader.read_line()
                    if line == null do raise new Exception.SdxRuntimeException("Missing common header.")
                    var common = line.split(" ", 7) // At most we want the 6th element i.e. "page=N"
                    // At least lineHeight and base are required.
                    if common.length < 3 do raise new Exception.SdxRuntimeException("Invalid common header.")

                    if common[1].index_of("lineHeight=") != 0 do raise new Exception.SdxRuntimeException("Missing: lineHeight")
                    lineHeight = int.parse(common[1].substring(11))

                    if common[2].index_of("base=") != 0 do raise new Exception.SdxRuntimeException("Missing: base")
                    var baseLine = int.parse(common[2].substring(5))

                    var pageCount = 1
                    if common.length >= 6 && common[5] != null && common[5].index_of("pages=") == 0
                        try 
                            pageCount = (int)Math.fmax(1, int.parse(common[5].substring(6)))
                        except e: Error
                            pass

                    imagePaths = new array of string[pageCount]

                    // Read each page definition.
                    for var p = 0 to (pageCount-1)
                        // Read each "page" info line.
                        line = reader.read_line()
                        if line == null do raise new Exception.SdxRuntimeException("Missing additional page definitions.")

                        info: MatchInfo
                        // Expect ID to mean "index".
                        var matcher = new Regex(".*id=(\\d+)")
                        if matcher.match(line, 0, out info)
                            var id = info.fetch(1)
                            try 
                                var pageID = int.parse(id)
                                if pageID != p do raise new Exception.SdxRuntimeException("Page IDs must be indices starting at 0: " + id)
                            except ex: Error
                                raise new Exception.SdxRuntimeException("Invalid page id: " + id)

                        matcher = new Regex(".*file=\"?([^\"]+)\"?")
                        if (!matcher.match(line, 0, out info)) do raise new Exception.SdxRuntimeException("Missing: file")
                        var fileName = info.fetch(1)

                        imagePaths[p] = fontFile.getParent().child(fileName).getPath()

                    descent = 0

                    while true
                        line = reader.read_line()
                        if line == null do break
                        if line.index_of("kernings ") == 0 do break
                        if line.index_of("char ") != 0 do continue

                        var glyph = new Glyph()
                        var tokens = new StringTokenizer(line, " =")
                        tokens.nextToken()
                        tokens.nextToken()
                        var ch = int.parse(tokens.nextToken())
                        if ch <= 0
                            missingGlyph = glyph
                        else if ch <= 255
                            setGlyph(ch, glyph)
                        else
                            continue
                        glyph.id = ch
                        tokens.nextToken()
                        glyph.x = int.parse(tokens.nextToken())
                        tokens.nextToken()
                        glyph.y = int.parse(tokens.nextToken())
                        tokens.nextToken()
                        glyph.width = int.parse(tokens.nextToken())
                        tokens.nextToken()
                        glyph.height = int.parse(tokens.nextToken())
                        tokens.nextToken()
                        glyph.xoffset = int.parse(tokens.nextToken())
                        tokens.nextToken()
                        if flip
                            glyph.yoffset = int.parse(tokens.nextToken())
                        else
                            glyph.yoffset = -(glyph.height + int.parse(tokens.nextToken()))
                        tokens.nextToken()
                        glyph.xadvance = int.parse(tokens.nextToken())
                        if tokens.hasMoreTokens() do tokens.nextToken()
                        if tokens.hasMoreTokens()
                            try 
                                glyph.page = int.parse(tokens.nextToken())
                            except e: Error
                                pass

                        if glyph.width > 0 && glyph.height > 0 do descent = Math.fmin(baseLine + glyph.yoffset, descent)
                    
                    descent += padBottom
                    
                    while true
                        line = reader.read_line()
                        if line == null do break
                        if line.index_of("kerning ") != 0 do break

                        var tokens = new StringTokenizer(line, " =")
                        tokens.nextToken()
                        tokens.nextToken()
                        var first = int.parse(tokens.nextToken())
                        tokens.nextToken()
                        var second = int.parse(tokens.nextToken())
                        if first < 0 || first > 255 || second < 0 || second > 255 do continue
                        var glyph = getGlyph((char)first)
                        tokens.nextToken()
                        var amount = int.parse(tokens.nextToken())
                        if glyph != null// Kernings may exist for glyph pairs not contained in the font.
                            glyph.setKerning(second, amount)
                    
                    var spaceGlyph = getGlyph(' ')
                    if spaceGlyph == null
                        spaceGlyph = new Glyph()
                        spaceGlyph.id = (int)' '
                        var xadvanceGlyph = getGlyph('l')
                        if xadvanceGlyph == null do xadvanceGlyph = getFirstGlyph()
                        spaceGlyph.xadvance = xadvanceGlyph.xadvance
                        setGlyph(' ', spaceGlyph)
                    
                    if spaceGlyph.width == 0
                        spaceGlyph.width = (int)(padLeft + spaceGlyph.xadvance + padRight)
                        spaceGlyph.xoffset = (int)(-padLeft)
                    
                    spaceWidth = spaceGlyph.width

                    xGlyph: Glyph = null
                    for var xChar in xChars
                        xGlyph = getGlyph(xChar)
                        if xGlyph != null do break
                    
                    if xGlyph == null do xGlyph = getFirstGlyph()
                    xHeight = xGlyph.height - padY

                    capGlyph: Glyph = null
                    for var capChar in capChars
                        capGlyph = getGlyph(capChar)
                        if capGlyph != null do break
                    
                    if capGlyph == null
                        for var p = 0 to (PAGES-1)
                            for var g = 0 to (PAGE_SIZE-1)
                                var glyph = glyphs[p,g]
                                if glyph == null || glyph.height == 0 || glyph.width == 0 do continue
                                capHeight = Math.fmax(capHeight, glyph.height)
                            
                        
                    else
                        capHeight = capGlyph.height
                    capHeight -= padY

                    ascent = baseLine - capHeight
                    down = -lineHeight
                    if flip
                        ascent = -ascent
                        down = -down

                except ex: Exception
                    raise new Exception.SdxRuntimeException("Error loading font file: " + fontFile.getName())



            def setGlyphRegion(glyph: Glyph, region: TextureRegion)
                var texture = region.texture
                var invTexWidth = 1.0 / texture.width
                var invTexHeight = 1.0 / texture.height

                var offsetX = 0
                var offsetY = 0
                var u = region.u
                var v = region.v
                var regionWidth = region.getRegionWidth()
                var regionHeight = region.getRegionHeight()
                if region isa TextureAtlas.AtlasRegion
                    // Compensate for whitespace stripped from left and top edges.
                    var atlasRegion = (TextureAtlas.AtlasRegion)region
                    offsetX = atlasRegion.offsetX
                    offsetY = atlasRegion.originalHeight - atlasRegion.packedHeight - atlasRegion.offsetY
                

                var x = glyph.x
                var x2 = glyph.x + glyph.width
                var y = glyph.y
                var y2 = glyph.y + glyph.height

                // Shift glyph for left and top edge stripped whitespace. Clip glyph for right and bottom edge stripped whitespace.
                if offsetX > 0
                    x -= offsetX
                    if x < 0
                        glyph.width += x
                        glyph.xoffset -= x
                        x = 0
                    
                    x2 -= offsetX
                    if x2 > regionWidth
                        glyph.width -= x2 - regionWidth
                        x2 = regionWidth

                if offsetY > 0
                    y -= offsetY
                    if y < 0
                        glyph.height += y
                        y = 0
                    
                    y2 -= offsetY
                    if y2 > regionHeight
                        var amount = y2 - regionHeight
                        glyph.height -= amount
                        glyph.yoffset += amount
                        y2 = regionHeight

                glyph.u = u + x * invTexWidth
                glyph.u2 = u + x2 * invTexWidth
                if flipped
                    glyph.v = v + y * invTexHeight
                    glyph.v2 = v + y2 * invTexHeight
                else
                    glyph.v2 = v + y * invTexHeight
                    glyph.v = v + y2 * invTexHeight
                
            def setLineHeight(height: double)
                lineHeight = height * scaleY
                down = flipped ? lineHeight : -lineHeight

            def setGlyph(ch: int, glyph: Glyph)
                glyphs[ch / PAGE_SIZE, ch & PAGE_SIZE - 1] = glyph

            def getFirstGlyph(): Glyph
                for var p = 0 to (PAGES-1)
                    for var g = 0 to (PAGE_SIZE-1)
                        var glyph = glyphs[p,g]
                        if glyph == null || glyph.height == 0 || glyph.width == 0 do continue
                        return glyph;
                raise new Exception.SdxRuntimeException("No glyphs found.")
                
            def hasGlyph(ch: char): bool
                if missingGlyph != null do return true
                return getGlyph(ch) != null
                
            def getGlyph(ch: char): Glyph
                return glyphs[ch / PAGE_SIZE, ch & PAGE_SIZE - 1]

            def getGlyphs(run: GlyphLayout.GlyphRun, str: string, start: int, end: int, tightBounds: bool)
                pass

            def getWrapIndex(start: int, glyphs: list of Glyph): int
                return 0

            def isBreakChar(c: char): bool
                return false

            def isWhitespace(c: char): bool
                case c  
                    when '\n'
                        return true
                    when '\r'
                        return true
                    when '\t'
                        return true
                    when ' '
                        return true
                return false

            def getImagePath(index: int): string
                return imagePaths[index]

            def setScale(scaleX: double, scaleY: double)
                pass

            def scale(amount: double)
                pass





            


