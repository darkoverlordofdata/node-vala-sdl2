/**
 * Script facing factory methods
 */
[indent=4]

uses SDL
uses SDL.Video
uses Gee
uses sdx.graphics.s2d
namespace sdx 

    /**
     * createGame
     *
     * @param name for title bar
     * @param height in pixels
     * @param width in pixels
     * @param base asset url
     * @return the new game
     */
    def createJsGame(name:string, height:int, width:int, base:string):Object
        return (Object)(new JsGame(name, height, width, base))

    /**
     * createSprite
     *
     * @param path to asset
     * @return the new sprite
     */
    def createSprite(path:string):Object
        return (Object)(new Sprite(path))

    /**
     * createSound
     *
     * @param path to asset
     * @return the new sound chunk
     */
    def createSound(path:string):Object
        return (Object)Sdx.audio.newSound(Sdx.files.resource(path))

    /**
     * createFont
     *
     * @param path to asset
     * @param size
     * @return the new font
     */
    def createFont(path:string, size:int):Object
        return (Object)(new Font(Sdx.files.resource(path), size))


    /**
     * createText
     *
     * @param text
     * @param font
     * @param color
     * @return the new text sprite
     */
    def createText(text:string, font:Object, color:Object):Object
        return (Object)(new Sprite.text(text, (Font)font, (sdx.graphics.Color)color))
        

    /**
     * createColor
     *
     * @param r
     * @param g
     * @param b
     * @param a
     * @return the new color
     */
    def createColor(r:double, g:double, b:double, a:double):Object
        return (Object)(new sdx.graphics.Color.rgba(r, g, b, a))

    def createAtlas(path:string):Object
        var file = Sdx.files.resource(path)
        if !file.exists() do return null
        return new TextureAtlas.file(file)
       