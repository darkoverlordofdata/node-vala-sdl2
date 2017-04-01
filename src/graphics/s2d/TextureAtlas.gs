/**
 * TextureAtlas.gs
 *
 */
[indent=4]
uses Gee
uses sdx.files
uses sdx.graphics

namespace sdx.graphics.s2d

    /**
     *  load a libgdx format atlas
     */
    class TextureAtlas : Object
        prop readonly textures: HashSet of Texture = new HashSet of Texture
        prop readonly regions: list of AtlasRegion = new list of AtlasRegion

        /**
         * @param root location of resources
         */
        construct(data: TextureAtlasData?=null)
            if data != null do load(data)

        construct file(packFile: FileHandle, imageDir: FileHandle?=null, flip:bool=false)
            this(new TextureAtlasData(packFile, imageDir == null ? packFile.getParent() : imageDir, flip))

        class static TextureAtlasData : Object
            prop pages: list of Page
            prop regions: list of Region

            /**
             * @param packFile the atlas file
             * @param imagesDir for the bitmap(s)
             * @param flip
             */
            construct(packFile: FileHandle, imagesDir: FileHandle, flip: bool)
                _pages = new list of Page
                _regions = new list of Region
                var reader = new DataInputStream(packFile.read())
                try
                    pageImage: Page = null
                    while true
                        var line = reader.read_line()
                        if line == null do break
                        if line.strip().length == 0
                            pageImage = null
                        else if pageImage == null
                            var file = imagesDir.child(line)
                            var width = 0
                            var height = 0
                            if readTuple(reader) == 2
                                width = int.parse(tuple[0])
                                height = int.parse(tuple[1])
                                readTuple(reader)
                            var format = Format.from(tuple[0])
                            readTuple(reader)
                            var min = TextureFilter.from(tuple[0])
                            var max = TextureFilter.from(tuple[1])
                            var direction = readValue(reader)
                            var repeatX = TextureWrap.ClampToEdge
                            var repeatY = TextureWrap.ClampToEdge
                            if direction == "x"
                                repeatX = TextureWrap.Repeat
                            else if direction == "y"
                                repeatY = TextureWrap.Repeat
                            else if direction == "xy"
                                repeatX = TextureWrap.Repeat
                                repeatY = TextureWrap.Repeat

                            pageImage = new Page(file, width, height, min.isMipMap(), format, min, max, repeatX, repeatY)
                            pages.add(pageImage)
                        else
                            var rotate = bool.parse(readValue(reader))

                            readTuple(reader)
                            var left = int.parse(tuple[0])
                            var top = int.parse(tuple[1])

                            readTuple(reader)
                            var width = int.parse(tuple[0])
                            var height = int.parse(tuple[1])

                            var region = new Region(pageImage, left, top, width, height, line, rotate)

                            if readTuple(reader) == 4
                                region.splits = {int.parse(tuple[0]), int.parse(tuple[1]), 
                                    int.parse(tuple[2]), int.parse(tuple[3])}

                                if readTuple(reader) == 4
                                    region.pads = {int.parse(tuple[0]), int.parse(tuple[1]), 
                                        int.parse(tuple[2]), int.parse(tuple[3])}


                                    readTuple(reader)

                            region.originalWidth = int.parse(tuple[0])
                            region.originalHeight = int.parse(tuple[1])

                            readTuple(reader)
                            region.offsetX = int.parse(tuple[0])
                            region.offsetY = int.parse(tuple[1])

                            region.index = int.parse(readValue(reader))

                            if flip do region.flip = true

                            regions.add(region)

                except e: Error
                    print e.message


            /**
             * povo - one for each atlas file 
             */
            class static Page
                prop textureFile: FileHandle
                prop texture: Texture
                prop height: int
                prop width: int
                prop useMipMaps: bool
                prop format: Format
                prop minFilter: int
                prop magFilter: int
                prop uWrap: int
                prop vWrap: int
                construct(handle: FileHandle, width: int, height: int, useMipMaps: bool, format: Format, minFilter: int,
                    magFilter: int, uWrap: int, vWrap: int)
                    _textureFile = handle
                    _height = height
                    _width = width
                    _useMipMaps = useMipMaps
                    _format = format
                    _minFilter = minFilter
                    _magFilter = magFilter
                    _uWrap = uWrap
                    _vWrap = vWrap


            /**
             * povo - one for each region in the atlas file 
             */
            class static Region
                prop page: Page
                prop index: int
                prop name: string
                prop offsetX: int
                prop offsetY: int
                prop originalWidth: int
                prop originalHeight: int
                prop rotate: bool
                prop left: int
                prop top: int
                prop width: int
                prop height: int
                prop flip: bool
                prop splits: array of int
                prop pads: array of int
                construct(page: Page, left: int, top: int, width: int, height: int, name: string, rotatate: bool)
                    _page = page
                    _left = left
                    _top = top
                    _width = width
                    _height = height
                    _name = name
                    _rotate = rotate



        def findRegion(name:string, index:int=-1): AtlasRegion
            for region in regions   
                if index == -1
                    if region.name == name do return region
                else
                    if region.name == name && region.index == index do return region

            return null

        def createSprite(name: string, index:int=-1): Sprite?
            for region in regions
                if index == -1
                    if region.name == name
                        return new Sprite.region(region)
                else    
                    if region.name == name && region.index == index
                        return new Sprite.region(region)
            return null
        

        /**
         * @param data config to load images from
         */
        def load(data: TextureAtlasData)
        
            texture: Texture = null
            var pageToTexture = new dict of TextureAtlasData.Page, Texture
            for page in data.pages
                if page.texture == null
                    texture = new Texture(page.textureFile) //, page.format, page.useMipMaps)
                else    
                    texture = page.texture
                texture.setFilter(page.minFilter, page.magFilter)
                texture.setWrap(page.uWrap, page.vWrap)
                textures.add(texture)
                pageToTexture[page] = texture

            for region in data.regions
                var width = region.width
                var height = region.height
                var atlasRegion = new AtlasRegion(pageToTexture[region.page], region.left, region.top,
				    region.rotate ? height : width, region.rotate ? width : height)
                atlasRegion.index = region.index
                atlasRegion.name = region.name
                atlasRegion.offsetX = region.offsetX
                atlasRegion.offsetY = region.offsetY
                atlasRegion.originalHeight = region.originalHeight
                atlasRegion.originalWidth = region.originalWidth
                atlasRegion.rotate = region.rotate
                atlasRegion.splits = region.splits
                atlasRegion.pads = region.pads
                if region.flip do atlasRegion.flip(false, true)
                regions.add(atlasRegion)

        /** tuple used to return the parsed values */
        prop private static tuple: array of string
	    /** Returns the number of tuple values read (1, 2 or 4). */
        def static readTuple(reader: DataInputStream): int raises IOException
            var line = reader.read_line()
            var ts = line.split(":")
            if ts.length == 0 do raise new IOException.InvalidData("invalid line %s", line)
            tuple = ts[1].split(",") 
            for var i=0 to (tuple.length-1)
                tuple[i] = tuple[i].strip()
            return tuple.length

        /** Returns the single value */
        def static readValue(reader: DataInputStream): string raises IOException
            var line = reader.read_line()
            var ts = line.split(":")
            if ts.length == 0 do raise new IOException.InvalidData("invalid line %s", line)
            return ts[1].strip()


        /** Describes the region of a packed image and provides information about the original image before it was packed. */
        class static AtlasRegion : TextureRegion
            /** The number at the end of the original image file name, or -1 if none.<br>
            * <br>
            * When sprites are packed, if the original file name ends with a number, it is stored as the index and is not considered as
            * part of the sprite's name. This is useful for keeping animation frames in order.
            * @see TextureAtlas#findRegions(String) */
            prop index: int
            /** The name of the original image file, up to the first underscore. Underscores denote special instructions to the texture
            * packer. */
            prop name: string
		    /** The offset from the left of the original image to the left of the packed image, after whitespace was removed for packing. */
            prop offsetX: int
            /** The offset from the bottom of the original image to the bottom of the packed image, after whitespace was removed for
            * packing. */
            prop offsetY: int
		    /** The width of the image, after whitespace was removed for packing. */
            prop packedWidth: int
		    /** The height of the image, after whitespace was removed for packing. */
            prop packedHeight: int
    		/** The width of the image, before whitespace was removed and rotation was applied for packing. */
            prop originalWidth: int
    		/** The height of the image, before whitespace was removed for packing. */
            prop originalHeight: int
		    /** If true, the region has been rotated 90 degrees counter clockwise. */
            prop rotate: bool
		    /** The ninepatch splits, or null if not a ninepatch. Has 4 elements: left, right, top, bottom. */
            prop splits: array of int
		    /** The ninepatch pads, or null if not a ninepatch or the has no padding. Has 4 elements: left, right, top, bottom. */
            prop pads: array of int

            construct(texture: Texture, x: int, y: int, width: int, height: int)
                super(texture, x, y, width, height)


            def flip(x: bool, y:bool)
                super.flip(x, y)

