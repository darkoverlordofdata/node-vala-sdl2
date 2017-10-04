###~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~##
##
##   Sdx ffi bindings for node
##
##   replaces sdx.gir
##   requires CoffeeScript 2.0.0-alpha1
##
##  Copyright 2017 darkoverlordofdata
##
##
#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~#~####
ffi = require 'ffi'
ref = require 'ref'

#
#   Vala Objects/Ptrs
#
VGame = ref.types.void
VGamePtr = ref.refType(VGame)

VFont = ref.types.void
VFontPtr = ref.refType(VFont)

VSprite = ref.types.void
VSpritePtr = ref.refType(VSprite)

VAtlas = ref.types.void
VAtlasPtr = ref.refType(VAtlas)

VSound = ref.types.void
VSoundPtr = ref.refType(VSound)

VText = ref.types.void
VTextPtr = ref.refType(VText)

VColor = ref.types.void
VColorPtr = ref.refType(VColor)

VFiles = ref.types.void
VFilesPtr = ref.refType(VFiles)

VFileHandler = ref.types.void
VFileHandlerPtr = ref.refType(VFileHandler)

VGraphics = ref.types.void
VGraphicsPtr = ref.refType(VGraphics)

VAudio = ref.types.void
VAudioPtr = ref.refType(VAudio)


sdx = ffi.Library 'sdx', 
    sdx_get_version:                        ['string', []]
    sdx_createJsGame:                       [VGamePtr, ['string', 'int', 'int', 'string']]
    sdx_createSprite:                       [VSpritePtr, ['string']]
    sdx_createAtlas:                        [VAtlasPtr, ['string']]
    sdx_createSound:                        [VSoundPtr, ['string']]
    sdx_createFont:                         [VFontPtr, ['string', 'int']]
    sdx_createText:                         [VTextPtr, ['string', VFontPtr, VColorPtr]]
    sdx_createColor:                        [VColorPtr, ['double', 'double', 'double', 'double']]
    sdx_audio_sound_play:                   ['void', [VSoundPtr, 'int']]
    sdx_audio_newSound:                     [VSoundPtr, [VAudioPtr]]
    sdx_files_get_isResource:               ['bool', [VFilesPtr]]
    sdx_files_get_resourcePath:             ['bool', [VFilesPtr]]
    sdx_files_getHandle:                    [VFileHandlerPtr, [VFilesPtr, 'string', 'int']]
    sdx_files_internal:                     [VFileHandlerPtr, [VFilesPtr, 'string']]
    sdx_files_resource:                     [VFileHandlerPtr, [VFilesPtr, 'string']]
    sdx_files_external:                     [VFileHandlerPtr, [VFilesPtr, 'string']]
    sdx_files_absolute:                     [VFileHandlerPtr, [VFilesPtr, 'string']]
    sdx_files_local:                        [VFileHandlerPtr, [VFilesPtr, 'string']]
    sdx_graphics_get_deltaTime:             ['double', [VGraphicsPtr]]
    sdx_graphics_get_frames:                ['int', [VGraphicsPtr]]
    sdx_graphics_get_fps:                   ['int', [VGraphicsPtr]]
    sdx_graphics_get_width:                 ['int', [VGraphicsPtr]]
    sdx_graphics_get_height:                ['int', [VGraphicsPtr]]
    sdx_graphics_get_scale:                 ['double', [VGraphicsPtr]]
    sdx_graphics_get_pixelFactor:           ['double', [VGraphicsPtr]]
    sdx_graphics_setSize:                   ['void', [VGraphicsPtr, 'int', 'int']]
    sdx_graphics_updateTime:                ['void', [VGraphicsPtr]]
    sdx_graphics_color_get_r:               ['double', [VColorPtr]]
    sdx_graphics_color_set_r:               ['void', [VColorPtr, 'double']]
    sdx_graphics_color_get_g:               ['double', [VColorPtr]]
    sdx_graphics_color_set_g:               ['void', [VColorPtr, 'double']]
    sdx_graphics_color_get_b:               ['double', [VColorPtr]]
    sdx_graphics_color_set_b:               ['void', [VColorPtr, 'double']]
    sdx_graphics_color_get_a:               ['double', [VColorPtr]]
    sdx_graphics_color_set_a:               ['void', [VColorPtr, 'double']]

    sdx_graphics_color_get_RED:             [VColorPtr, []]
    sdx_graphics_color_get_CLEAR:           [VColorPtr, []]
    sdx_graphics_color_get_BLACK:           [VColorPtr, []]
    sdx_graphics_color_get_WHITE:           [VColorPtr, []]
    sdx_graphics_color_get_LIGHT_GRAY:      [VColorPtr, []]
    sdx_graphics_color_get_GRAY:            [VColorPtr, []]
    sdx_graphics_color_get_DARK_GRAY:       [VColorPtr, []]
    sdx_graphics_color_get_BLUE:            [VColorPtr, []]
    sdx_graphics_color_get_NAVY:            [VColorPtr, []]
    sdx_graphics_color_get_ROYAL:           [VColorPtr, []]
    sdx_graphics_color_get_SLATE:           [VColorPtr, []]
    sdx_graphics_color_get_SKY:             [VColorPtr, []]
    sdx_graphics_color_get_CYAN:            [VColorPtr, []]
    sdx_graphics_color_get_TEAL:            [VColorPtr, []]
    sdx_graphics_color_get_GREEN:           [VColorPtr, []]
    sdx_graphics_color_get_CHARTREUSE:      [VColorPtr, []]
    sdx_graphics_color_get_LIME:            [VColorPtr, []]
    sdx_graphics_color_get_FOREST:          [VColorPtr, []]
    sdx_graphics_color_get_OLIVE:           [VColorPtr, []]
    sdx_graphics_color_get_YELLOW:          [VColorPtr, []]
    sdx_graphics_color_get_GOLD:            [VColorPtr, []]
    sdx_graphics_color_get_GOLDENROD:       [VColorPtr, []]
    sdx_graphics_color_get_ORANGE:          [VColorPtr, []]
    sdx_graphics_color_get_BROWN:           [VColorPtr, []]
    sdx_graphics_color_get_TAN:             [VColorPtr, []]
    sdx_graphics_color_get_FIREBRICK:       [VColorPtr, []]
    sdx_graphics_color_get_RED:             [VColorPtr, []]
    sdx_graphics_color_get_SCARLET:         [VColorPtr, []]
    sdx_graphics_color_get_SALMON:          [VColorPtr, []]
    sdx_graphics_color_get_PINK:            [VColorPtr, []]
    sdx_graphics_color_get_MAGENTA:         [VColorPtr, []]
    sdx_graphics_color_get_PURPLE:          [VColorPtr, []]
    sdx_graphics_color_get_VIOLET:          [VColorPtr, []]
    sdx_graphics_color_get_MAROON:          [VColorPtr, []]


    sdx_graphics_s2d_font_get_path:         ['string', [VFontPtr]]
    sdx_graphics_s2d_sprite_get_x:          ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_x:          ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_y:          ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_y:          ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_r:          ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_r:          ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_g:          ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_g:          ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_b:          ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_b:          ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_a:          ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_a:          ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_width:      ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_width:      ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_height:     ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_height:     ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_get_centered:   ['bool', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_centered:   ['void', [VSpritePtr, 'bool']]
    sdx_graphics_s2d_sprite_get_layer:      ['int', [VSpritePtr]]
    sdx_graphics_s2d_sprite_set_layer:      ['void', [VSpritePtr, 'int']]
    sdx_graphics_s2d_sprite_setScale:       ['void', [VSpritePtr, 'double', 'double']]
    sdx_graphics_s2d_sprite_setColor:       ['void', [VSpritePtr, 'double', 'double', 'double']]
    sdx_graphics_s2d_sprite_setText:        ['void', [VSpritePtr, 'string', VFontPtr, VColorPtr]]

    sdx_graphics_s2d_texture_atlas_createSprite:    [VSpritePtr, [VAtlasPtr, 'string', 'int']]

    sdx_iapplication_get_width:             ['int', [VGamePtr]]
    sdx_iapplication_get_height:            ['int', [VGamePtr]]
    sdx_js_game_start:                      ['void', [VGamePtr]]
    sdx_js_game_get_running:                ['bool', [VGamePtr]]
    sdx_js_game_handleEvents:               ['void', [VGamePtr]]
    sdx_js_game_getKey:                     ['bool', [VGamePtr, 'int']]
    sdx_js_game_draw:                       ['void', [VGamePtr]]
    sdx_js_game_get_base:                   ['string', [VGamePtr]]
    sdx_js_game_get_profile:                ['bool', [VGamePtr]]
    sdx_js_game_set_profile:                ['void', [VGamePtr, 'bool']]
    sdx_js_game_get_mouseX:                 ['int', [VGamePtr]]
    sdx_js_game_get_mouseY:                 ['int', [VGamePtr]]
    sdx_js_game_get_mouseDown:              ['bool', [VGamePtr]]
    sdx_js_game_get_showFps:                ['bool', [VGamePtr]]
    sdx_js_game_set_showFps:                ['void', [VGamePtr], 'bool'],
    sdx_js_game_get_deltaTime:              ['double', [VGamePtr]]
    sdx_js_game_addSprite:                  ['void', [VGamePtr, VSpritePtr]]
    sdx_js_game_addOnce:                    ['void', [VGamePtr, VSpritePtr]]
    sdx_js_game_removeSprite:               ['void', [VGamePtr, VSpritePtr]]
    sdx_sdx_get_app:                        [VGamePtr, []]
    sdx_sdx_get_graphics:                   [VGraphicsPtr, []]
    sdx_sdx_get_audio:                      [VAudioPtr, []]
    # sdx_sdx_get_input:                      [GInputPtr, []]
    sdx_sdx_get_files:                      [VFilesPtr, []]

##
 # base instance class 
 # with property getters and setters
##
class ValaProxy
    @property = (props) -> Object.defineProperties @::, props
    constructor:(@instance) ->

##
 # Game instance wrapper
##
class Game extends ValaProxy

    @audio = null
    @files = null
    @game = null
    @graphics = null
    
    @property
        name:           
            get:()  -> sdx.sdx_js_game_get_name(@instance)
        base:           
            get:()  -> sdx.sdx_js_game_get_base(@instance)
        running:        
            get:()  -> sdx.sdx_js_game_get_running(@instance)
        profile:        
            get:()  -> sdx.sdx_js_game_get_profile(@instance)
            set:(v) -> sdx.sdx_js_game_set_profile(@instance, v)
        mouseX:         
            get:()  -> sdx.sdx_js_game_get_mouseX(@instance)
        mouseY:         
            get:()  -> sdx.sdx_js_game_get_mouseY(@instance)
        mouseDown:      
            get:()  -> sdx.sdx_js_game_get_mouseDown(@instance)
        showFps:        
            get:()  -> sdx.sdx_js_game_get_showFps(@instance)
            set:(v) -> sdx.sdx_js_game_set_showFps(@instance, v)
        deltaTime:      
            get:()  -> sdx.sdx_js_game_get_deltaTime(@instance)
        width:        
            get:()  -> sdx.sdx_iapplication_get_width(@instance)
        height:        
            get:()  -> sdx.sdx_iapplication_get_height(@instance)
    constructor:(instance) ->
        super instance
        Game.game = this
        Game.audio = new Audio(sdx.sdx_sdx_get_audio())
        Game.files = new Files(sdx.sdx_sdx_get_files())
        Game.graphics = new Graphics(sdx.sdx_sdx_get_graphics())

    start:() => 
        sdx.sdx_js_game_start(@instance)
    handleEvents:() => 
        sdx.sdx_js_game_handleEvents(@instance)
    getKey:(key) => 
        sdx.sdx_js_game_getKey(@instance, key)
    draw:() => 
        sdx.sdx_js_game_draw(@instance)
    addSprite:(sprite) =>
        sdx.sdx_js_game_addSprite(@instance, sprite.instance)
    addOnce:(sprite) => 
        sdx.sdx_js_game_addOnce(@instance, sprite.instance)
    removeSprite:(sprite) => 
        sdx.sdx_js_game_removeSprite(@instance, sprite.instance)
    
##
 # Sprite instance wrapper
##
class Sprite extends ValaProxy

    @property
        x:          
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_x(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_x(@instance, v) 
        y:          
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_y(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_y(@instance, v) 
        r:          
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_r(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_r(@instance, v) 
        g:          
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_g(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_g(@instance, v) 
        b:          
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_b(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_b(@instance, v) 
        a:          
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_a(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_a(@instance, v) 
        width:      
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_width(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_width(@instance, v) 
        height:     
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_height(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_height(@instance, v) 
        centered:   
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_centered(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_centered(@instance, v) 
        layer:      
            get:()  -> sdx.sdx_graphics_s2d_sprite_get_layer(@instance)
            set:(v) -> sdx.sdx_graphics_s2d_sprite_set_layer(@instance, v) 

    setScale:(x, y) => 
        sdx.sdx_graphics_s2d_sprite_setScale(@instance, x, y) 
    setColor:(r, g, b) => 
        sdx.sdx_graphics_s2d_sprite_setColor(@instance, r, g, b) 
    setText:(str, font, color) => 
        sdx.sdx_graphics_s2d_sprite_setText(@instance, str, font, color) 

##
 # Atlas instance wrapper
##
class Atlas extends ValaProxy
    
    createSprite:(path, index=-1) => 
        new Sprite(sdx.sdx_graphics_s2d_texture_atlas_createSprite(@instance, path, parseInt(index)))

##
 # Sound instance wrapper
##
class Sound extends ValaProxy
    
    play:(l) => 
        sdx.sdx_audio_sound_play(@instance, l) 

##
 # Font instance wrapper
##
class Font extends ValaProxy
    @property
        path:       
            get:()  -> sdx.sdx_graphics_s2d_font_get_path(@instance)
    

##
 # Color instance wrapper
##
class Color extends ValaProxy
    @property
        r:  
            get:()  -> sdx.sdx_graphics_color_get_r(@instance)
            set:(v) -> sdx.sdx_graphics_color_set_r(@instance, v) 
        g:  
            get:()  -> sdx.sdx_graphics_color_get_g(@instance)
            set:(v) -> sdx.sdx_graphics_color_set_g(@instance, v) 
        b:  
            get:()  -> sdx.sdx_graphics_color_get_b(@instance)
            set:(v) -> sdx.sdx_graphics_color_set_b(@instance, v) 
        a:  
            get:()  -> sdx.sdx_graphics_color_get_a(@instance)
            set:(v) -> sdx.sdx_graphics_color_set_a(@instance, v) 
    

##
 # Graphics instance wrapper
##
class Graphics extends ValaProxy
    @property
        deltaTime: 
            get:()  -> sdx.sdx_graphics_get_deltaTime(@instance)
        frames:
            get:()  -> sdx.sdx_graphics_get_frames(@instance)
        fps: 
            get:()  -> sdx.sdx_graphics_get_fps(@instance)
        width: 
            get:()  -> sdx.sdx_graphics_get_width(@instance)
        height: 
            get:()  -> sdx.sdx_graphics_get_height(@instance)
        scale:
            get:()  -> sdx.sdx_graphics_get_scale(@instance)
        pixelFactor: 
            get:()  -> sdx.sdx_graphics_get_pixelFactor(@instance)
    
    setSize:(width, height) =>
        sdx.sdx_graphics_setSize(@instance, width, height)
    updateTime:() =>
        sdx.sdx_graphics_updateTime(@instance)

##
 # Audio instance wrapper
##
class Audio extends ValaProxy
    
    newSound:(file) =>
        sdx.sdx_audio_newSound(@instance, file)

##
 # Files instance wrapper
##
class Files extends ValaProxy
    @property
        isResource: 
            get:()  -> sdx.sdx_files_get_isResource(@instance)
        resourcePath: 
            get:()  -> sdx.sdx_files_get_resourcePath(@instance)
    
    getHandle: (path, type) =>
        sdx.sdx_files_getHandle(@instance, path, type)
    internal: (path) =>
        sdx.sdx_files_internal(@instance, path)
    resource: (path) =>
        sdx.sdx_files_resource(@instance, path)
    external: (path) =>
        sdx.sdx_files_external(@instance, path)
    absolute: (path) =>
        sdx.sdx_files_absolute(@instance, path)
    local: (path) =>
        sdx.sdx_files_local(@instance, path)


##
 # Global factory
##
Object.defineProperties sdx, 
    createGame: value: (title, height, width, base) ->
        new Game(sdx.sdx_createJsGame(title, height, width, base))
    
    createSprite: value: (path) ->
        new Sprite(sdx.sdx_createSprite(path))
    
    createAtlas: value: (path) ->
        new Atlas(sdx.sdx_createAtlas(path))
    
    createSound: value: (path) ->
        new Sound(sdx.sdx_createSound(path))
    
    createFont: value: (path, size) ->
        new Font(sdx.sdx_createFont(path, size))
    
    createText: value: (text, font, color) ->
        new Sprite(sdx.sdx_createText(text, font, color))
    
    createColor: value: (r, g, b, a) ->
        new Color(sdx.sdx_createColor(r, g, b, a))

    graphics:   value: {}
    Input:      value: {}
    Sdx:        value: {}

##
 # Enums
##
Object.defineProperties sdx.Input, 
    Keys: { value: {
        Esc: 27,
        a: 97,
        b: 98,
        c: 99,
        d: 100,
        e: 101,
        f: 102,
        g: 103,
        h: 104,
        i: 105,
        j: 106,
        k: 107,
        l: 108,
        m: 109,
        n: 110,
        o: 111,
        p: 112,
        q: 113,
        r: 114,
        s: 115,
        t: 116,
        u: 117,
        v: 118,
        w: 119,
        x: 120,
        y: 121,
        z: 122
    } }

Object.defineProperties sdx.graphics, 
    color:      value: {} 

Object.defineProperties sdx.graphics.color, 
    CLEAR:      get:()  -> sdx.sdx_graphics_color_get_CLEAR()
    BLACK:      get:()  -> sdx.sdx_graphics_color_get_BLACK()
    WHITE:      get:()  -> sdx.sdx_graphics_color_get_WHITE()
    LIGHT_GRAY: get:()  -> sdx.sdx_graphics_color_get_LIGHT_GRAY()
    GRAY:       get:()  -> sdx.sdx_graphics_color_get_GRAY()
    DARK_GRAY:  get:()  -> sdx.sdx_graphics_color_get_DARK_GRAY()
    BLUE:       get:()  -> sdx.sdx_graphics_color_get_BLUE()
    NAVY:       get:()  -> sdx.sdx_graphics_color_get_NAVY()
    ROYAL:      get:()  -> sdx.sdx_graphics_color_get_ROYAL()
    SLATE:      get:()  -> sdx.sdx_graphics_color_get_SLATE()
    SKY:        get:()  -> sdx.sdx_graphics_color_get_SKY()
    CYAN:       get:()  -> sdx.sdx_graphics_color_get_CYAN()
    TEAL:       get:()  -> sdx.sdx_graphics_color_get_TEAL()
    GREEN:      get:()  -> sdx.sdx_graphics_color_get_GREEN()
    CHARTREUSE: get:()  -> sdx.sdx_graphics_color_get_CHARTREUSE()
    LIME:       get:()  -> sdx.sdx_graphics_color_get_LIME()
    FOREST:     get:()  -> sdx.sdx_graphics_color_get_FOREST()
    OLIVE:      get:()  -> sdx.sdx_graphics_color_get_OLIVE()
    YELLOW:     get:()  -> sdx.sdx_graphics_color_get_YELLOW()
    GOLD:       get:()  -> sdx.sdx_graphics_color_get_GOLD()
    GOLDENROD:  get:()  -> sdx.sdx_graphics_color_get_GOLDENROD()
    ORANGE:     get:()  -> sdx.sdx_graphics_color_get_ORANGE()
    BROWN:      get:()  -> sdx.sdx_graphics_color_get_BROWN()
    TAN:        get:()  -> sdx.sdx_graphics_color_get_TAN()
    FIREBRICK:  get:()  -> sdx.sdx_graphics_color_get_FIREBRICK()
    RED:        get:()  -> sdx.sdx_graphics_color_get_RED()
    SCARLET:    get:()  -> sdx.sdx_graphics_color_get_SCARLET()
    SALMON:     get:()  -> sdx.sdx_graphics_color_get_SALMON()
    PINK:       get:()  -> sdx.sdx_graphics_color_get_PINK()
    MAGENTA:    get:()  -> sdx.sdx_graphics_color_get_MAGENTA()
    PURPLE:     get:()  -> sdx.sdx_graphics_color_get_PURPLE()
    VIOLET:     get:()  -> sdx.sdx_graphics_color_get_VIOLET()
    MAROON:     get:()  -> sdx.sdx_graphics_color_get_MAROON()

Object.defineProperties sdx.Sdx, 
    app:        get:()  -> Game.game
    graphics:   get:()  -> Game.graphics
    audio:      get:()  -> Game.audio
    files:      get:()  -> Game.files
    
Object.defineProperties sdx,
    # version:    get:()  -> "420"
    version:    get:()  -> sdx.sdx_get_version()

module.exports = sdx