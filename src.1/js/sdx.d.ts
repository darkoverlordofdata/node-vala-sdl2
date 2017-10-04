/**
 * Sdx.d.ts
 *
 */
declare module 'Sdx' {

    export function sdx_get_version():string
    export const PI:number
    export const degreesToRadians:number
    export const VERSION:string
    export function createJsGame(name: string, height: number, width: number, base: string):JsGame
    export function createGame(name: string, height: number, width: number, base: string):JsGame
    export function createSprite(path: string):graphics.s2d.Sprite 
    export function createAtlas(path: string):graphics.s2d.TextureAtlas 
    export function createSound(path: string):audio.Sound
    export function createFont(path: string, size: number):graphics.s2d.Font
    export function createText(text: string, font: any, color: any):graphics.s2d.Sprite
    export function createColor(r: number, g: number, b: number, a: number):graphics.Color
    export function sdlFailIf(cond: boolean, reason: string):void
    export enum FileType {
        INTERNAL,
        RESOURCE,
        EXTERNAL,
        ABSOLUTE,
        LOCAL,
    }

    namespace Input {

        export enum Buttons {
            LEFT,
            RIGHT,
            MIDDLE,
            BACK,
            FORWARD,
        }
        export enum Keys {
            Esc,
            a,
            b,
            c,
            d,
            e,
            f,
            g,
            h,
            i,
            j,
            k,
            l,
            m,
            n,
            o,
            p,
            q,
            r,
            s,
            t,
            u,
            v,
            w,
            x,
            y,
            z,
        }
    }
    namespace graphics {
        namespace s2d {
            export function texture_filter_from(value: string):any
            export function texture_filter_isMipMap():boolean
            export function texture_filter_to_string():string
            export function texture_wrap_from(value: string):any
            export function texture_wrap_to_string():string
            export function format_from(value: string):any
            export function format_to_string():string

            export enum TextureFilter {
                NEAREST,
                LINEAR,
                MIPMAP,
                MIPMAPNEARESTNEAREST,
                MIPMAPLINEARNEAREST,
                MIPMAPNEARESTLINEAR,
                MIPMAPLINEARLINEAR,
            }
            export enum TextureWrap {
                CLAMPTOEDGE,
                REPEAT,
            }
            export enum Format {
                ALPHA,
                INTENSITY,
                LUMINANCEALPHA,
                RGB565,
                RGBA4444,
                RGB888,
                RGBA8888,
            }
            export class Font {
                path:string
                render(text: string, color: any):any
            }
            export class GlyphLayout {
                setText(font: any, str: string, start: number, end: number, color: any, targetWidth: number, halign: number, wrap: boolean, truncate: string):void
                truncate(fontData: any, run: any, targetWidth: number, truncate: string, widthIndex: number, glyphRunPool: any):void
                parseColorMarkup(str: string, start: number, end: number, colorPool: any):number
                wrap(fontData: any, first: any, glyphRunPool: any, wrapIndex: number, widthIndex: number):any
            }
            export class GlyphLayoutGlyphRun {
            }
            export class NinePatch {
                static textureXY(texture: any, left: number, right: number, top: number, bottom: number):NinePatch
                static ninepatch(ninePatch: any, color: any):NinePatch
                load(patches: any[], patches_length1: number):void
                add(region: any, color: number, isStretchW: boolean, isStretchH: boolean):number
                draw(batch: any, x: number, y: number, width: number, height: number):void
                setColor(color: any):void
                getColor():any
                getLeftWidth():number
                setLeftWidth(leftWidth: number):void
                getRightWidth():number
                setRightWidth(rightWidth: number):void
                getTopHeight():number
                setTopHeight(topHeight: number):void
                getBottomHeight():number
                setBottomHeight(bottomHeight: number):void
                getMiddleWidth():number
                setMiddleWidth(middleWidth: number):void
                getMiddleHeight():number
                setMiddleHeight(middleHeight: number):void
                getTotalWidth():number
                getTotalHeight():number
                setPadding(left: number, right: number, top: number, bottom: number):void
                getPadLeft():number
                setPadLeft(left: number):void
                getPadRight():number
                setPadRight(right: number):void
                getPadTop():number
                setPadTop(top: number):void
                getPadBottom():number
                setPadBottom(bottom: number):void
                scale(scaleX: number, scaleY: number):void
            }
            export class Sprite {
                width:number
                height:number
                x:number
                y:number
                r:number
                g:number
                b:number
                a:number
                centered:boolean
                layer:number
                static file(file: any):Sprite
                static region(region: any):Sprite
                static text(text: string, font: any, color: any):Sprite
                setScale(x: number, y: number):void
                setColor(r: number, g: number, b: number):void
                setText(text: string, font: any, color: any):void
                render(renderer: any, x: number, y: number, clip: any):void
            }
            export class TextureAtlas {
                textures:any
                regions:any
                static readTuple(reader: any):number
                static readValue(reader: any):string
                static file(packFile: any, imageDir: any, flip: boolean):TextureAtlas
                findRegion(name: string, index: number):any
                createSprite(name: string, index: number):any
                load(data: any):void
            }
            export class TextureAtlasTextureAtlasData {
                pages:any
                regions:any
            }
            export class TextureAtlasAtlasRegion extends TextureRegion {
                index:number
                name:string
                offsetX:number
                offsetY:number
                packedWidth:number
                packedHeight:number
                originalWidth:number
                originalHeight:number
                rotate:boolean
                get_splits(result_length1: number):number[]
                set_splits(value: number[], value_length1: number):void
                get_pads(result_length1: number):number[]
                set_pads(value: number[], value_length1: number):void
                flip(x: boolean, y: boolean):void
            }
            export class TextureRegion {
                texture:any
                top:number
                left:number
                width:number
                height:number
                regionWidth:number
                regionHeight:number
                u:number
                v:number
                u2:number
                v2:number
                static region(region: any, x: number, y: number, width: number, height: number):TextureRegion
                setRegion(u: number, v: number, u2: number, v2: number):void
                setRegionXY(x: number, y: number, width: number, height: number):void
                setByRegion(region: any):void
                setByRegionXY(region: any, x: number, y: number, width: number, height: number):void
                flip(x: boolean, y: boolean):void
                getU():number
                setU(u: number):void
                getV():number
                setV(v: number):void
                getU2():number
                setU2(u2: number):void
                getV2():number
                setV2(v2: number):void
                getRegionX():number
                setRegionX(x: number):void
                getRegionY():number
                setRegionY(y: number):void
                getRegionWidth():number
                setRegionWidth(width: number):void
                getRegionHeight():number
                setRegionHeight(height: number):void
                isFlipX():boolean
                isFlipY():boolean
            }
        }
    }
    namespace graphics {
        export class Color {
            static CLEAR:Color
            static BLACK:Color
            static WHITE:Color
            static LIGHT_GRAY:Color
            static GRAY:Color
            static DARK_GRAY:Color
            static BLUE:Color
            static NAVY:Color
            static ROYAL:Color
            static SLATE:Color
            static SKY:Color
            static CYAN:Color
            static TEAL:Color
            static GREEN:Color
            static CHARTREUSE:Color
            static LIME:Color
            static FOREST:Color
            static OLIVE:Color
            static YELLOW:Color
            static GOLD:Color
            static GOLDENROD:Color
            static ORANGE:Color
            static BROWN:Color
            static TAN:Color
            static FIREBRICK:Color
            static RED:Color
            static SCARLET:Color
            static SALMON:Color
            static PINK:Color
            static MAGENTA:Color
            static PURPLE:Color
            static VIOLET:Color
            static MAROON:Color
            static TransparentBlack:Color
            static TransparentWhite:Color
            static AliceBlue:Color
            static AntiqueWhite:Color
            static Aqua:Color
            static Aquamarine:Color
            static Azure:Color
            static Beige:Color
            static Bisque:Color
            static Black:Color
            static BlanchedAlmond:Color
            static Blue:Color
            static BlueViolet:Color
            static Brown:Color
            static BurlyWood:Color
            static CadetBlue:Color
            static Chartreuse:Color
            static Chocolate:Color
            static Coral:Color
            static CornflowerBlue:Color
            static Cornsilk:Color
            static Crimson:Color
            static Cyan:Color
            static DarkBlue:Color
            static DarkCyan:Color
            static DarkGoldenrod:Color
            static DarkGray:Color
            static DarkGreen:Color
            static DarkKhaki:Color
            static DarkMagenta:Color
            static DarkOliveGreen:Color
            static DarkOrange:Color
            static DarkOrchid:Color
            static DarkRed:Color
            static DarkSalmon:Color
            static DarkSeaGreen:Color
            static DarkSlateBlue:Color
            static DarkSlateGray:Color
            static DarkTurquoise:Color
            static DarkViolet:Color
            static DeepPink:Color
            static DeepSkyBlue:Color
            static DimGray:Color
            static DodgerBlue:Color
            static Firebrick:Color
            static FloralWhite:Color
            static ForestGreen:Color
            static Fuchsia:Color
            static Gainsboro:Color
            static GhostWhite:Color
            static Gold:Color
            static Goldenrod:Color
            static Gray:Color
            static Green:Color
            static GreenYellow:Color
            static Honeydew:Color
            static HotPink:Color
            static IndianRed:Color
            static Indigo:Color
            static Ivory:Color
            static Khaki:Color
            static Lavender:Color
            static LavenderBlush:Color
            static LawnGreen:Color
            static LemonChiffon:Color
            static LightBlue:Color
            static LightCoral:Color
            static LightCyan:Color
            static LightGoldenrodYellow:Color
            static LightGray:Color
            static LightGreen:Color
            static LightPink:Color
            static LightSalmon:Color
            static LightSeaGreen:Color
            static LightSkyBlue:Color
            static LightSlateGray:Color
            static LightSteelBlue:Color
            static LightYellow:Color
            static Lime:Color
            static LimeGreen:Color
            static Linen:Color
            static Magenta:Color
            static Maroon:Color
            static MediumAquamarine:Color
            static MediumBlue:Color
            static MediumOrchid:Color
            static MediumPurple:Color
            static MediumSeaGreen:Color
            static MediumSlateBlue:Color
            static MediumSpringGreen:Color
            static MediumTurquoise:Color
            static MediumVioletRed:Color
            static MidnightBlue:Color
            static MintCream:Color
            static MistyRose:Color
            static Moccasin:Color
            static MonoGameOrange:Color
            static NavajoWhite:Color
            static Navy:Color
            static OldLace:Color
            static Olive:Color
            static OliveDrab:Color
            static Orange:Color
            static OrangeRed:Color
            static Orchid:Color
            static PaleGoldenrod:Color
            static PaleGreen:Color
            static PaleTurquoise:Color
            static PaleVioletRed:Color
            static PapayaWhip:Color
            static PeachPuff:Color
            static Peru:Color
            static Pink:Color
            static Plum:Color
            static PowderBlue:Color
            static Purple:Color
            static Red:Color
            static RosyBrown:Color
            static RoyalBlue:Color
            static SaddleBrown:Color
            static Salmon:Color
            static SandyBrown:Color
            static SeaGreen:Color
            static SeaShell:Color
            static Sienna:Color
            static Silver:Color
            static SkyBlue:Color
            static SlateBlue:Color
            static SlateGray:Color
            static Snow:Color
            static SpringGreen:Color
            static SteelBlue:Color
            static Tan:Color
            static Teal:Color
            static Thistle:Color
            static Tomato:Color
            static Turquoise:Color
            static Violet:Color
            static Wheat:Color
            static White:Color
            static WhiteSmoke:Color
            static Yellow:Color
            static YellowGreen:Color
            static rgba(r: number, g: number, b: number, a: number):Color
            static clone(color: any):Color
            set(color: any):any
            clamp():any
            toIntBits():number
        }
        export class Texture {
            path:string
            width:number
            height:number
            static getSurface(ext: string, raw: any):any
            static uri(path: string):Texture
            setFilter(minFilter: number, magFilter: number):void
            setWrap(u: number, v: number):void
        }
    }
    namespace scenes {
        namespace scene2d {
            export enum Touchable {
                ENABLED,
                DISABLED,
                CHILDRENONLY,
            }
            export enum InputEventType {
                TOUCHDOWN,
                TOUCHUP,
                TOUCHDRAGGED,
                MOUSEMOVED,
                ENTER,
                EXIT,
                SCROLLED,
                KEYDOWN,
                KEYUP,
                KEYTYPED,
            }
            export class Action {
                pool:any
                target:any
                actor:any
                act(delta: number):boolean
                restart():void
            }
            export class Actor {
                stage:any
                parent:any
                touchable:any
                userObject:any
                color:any
                name:string
                draw(batch: any, parentAlpha: number):void
                act(delta: number):void
                fire(event: any):boolean
                notify(property_name: string):void

                hit(x: number, y: number, touchable: boolean):any
                remove():boolean
                addListener(listener: any):boolean
                removeListener(listener: any):boolean
                getListeners():any
                addCaptureListener(listener: any):boolean
                removeCaptureListener(listener: any):boolean
                getCaptureListeners():any
                addAction(action: any):void
                removeAction(action: any):void
                getActions():any
                hasActions():boolean
                clearActions():void
                clearListeners():void
                clear():void
                isDescendantOf(actor: any):boolean
                isAscendantOf(actor: any):boolean
                firstAscendant(type: any):any
                hasParent():boolean
                isTouchable():boolean
                isVisible():boolean
                setVisible(visible: boolean):void
                getX():number
                setX(x: number):void
                getY():number
                setY(y: number):void
                setPosition(x: number, y: number):void
                moveBy(x: number, y: number):void
                getWidth():number
                setWidth(width: number):void
                getHeight():number
                setHeight(height: number):void
                getTop():number
                getRight():number
                positionChanged():void
                sizeChanged():void
                rotationChanged():void
                setSize(width: number, height: number):void
                sizeBy(size: number):void
                setBounds(x: number, y: number, width: number, height: number):void
                getOriginX():number
                setOriginX(originX: number):void
                getOriginY():number
                setOriginY(originY: number):void
                setOrigin(originX: number, originY: number):void
                getScaleX():number
                setScaleX(scaleX: number):void
                getScaleY():number
                setScaleY(scaleXY: number):void
                setScale(scaleX: number, scaleY: number):void
                scaleBy(scaleX: number, scaleY: number):void
                getRotation():number
                setRotation(degrees: number):void
                rotateBy(amountInDegrees: number):void
                toFront():void
                toBack():void
                setZIndex(index: number):void
                getZIndex():number
                screenToLocalCoordinates(screenCoords: any):any
                stageToLocalCoordinates(stageCoords: any):any
                localToStageCoordinates(localCoords: any):any
                localToParentCoordinates(localCoords: any):any
                localToAscendantCoordinates(ascendant: any, localCoords: any):any
                parentToLocalCoordinates(parentCoords: any):any
            }
            export class Event {
                handle():void
                cancel():void
                stop():void
                getTarget():any
                setTarget(targetActor: any):void
                getListenerActor():any
                setListenerActor(listenerActor: any):void
                getBubbles():boolean
                setBubbles(bubbles: boolean):void
                isHandled():boolean
                isStopped():boolean
                isCancelled():boolean
                setCapture(capture: boolean):void
                isCapture():boolean
                setStage(stage: any):void
                getStage():any
            }
            export class Group extends Actor {
                children:any
                stage:any
                act(delta: number):void
                draw(batch: any, parentAlpha: number):void
                drawChildren(batch: any, parentAlpha: number):void
                getCullingArea():any
                hit(x: number, y: number, touchable: boolean):any
                childrenChanged():void
                addActor(actor: any):void
                addActorAt(index: number, actor: any):void
                addActorBefore(actorBefore: any, actor: any):void
                addActorAfter(actorAfter: any, actor: any):void
                removeActor(actor: any, unfocus: boolean):boolean
                clearChildren():void
                clear():void
                findActor(name: string):any
                hasChildren():boolean
                setTransform(transform: boolean):void
                isTransform():boolean
                localToDescendantCoordinates(descendant: any, localCoords: any):any
            }
            export class InputEvent extends Event {
                getStageX():number
                setStageX(stageX: number):void
                getStageY():number
                setStageY(stageY: number):void
                getType():any
                setType(type: any):void
                getPointer():number
                setPointer(pointer: number):void
                getButton():number
                setButton(button: number):void
                getKeyCode():number
                setKeyCode(keyCode: number):void
                getCharacter():number
                setCharacter(character: number):void
                getScrollAmount():number
                setScrollAmount(scrollAmount: number):void
                getRelatedActor():any
                setRelatedActor(relatedActor: any):void
                toCoordinates(actor: any, actorCoords: any):any
                isTouchFocusCancel():boolean
                to_string():string
            }
            export class InputListener {
                touchDown(event: any, x: number, y: number, pointer: number, button: number):boolean
                touchUp(event: any, x: number, y: number, pointer: number, button: number):void
                touchDragged(event: any, x: number, y: number, pointer: number):void
                mouseMoved(event: any, x: number, y: number):boolean
                enter(event: any, x: number, y: number, pointer: number, fromActor: any):void
                exit(event: any, x: number, y: number, pointer: number, toActor: any):void
                scrolled(event: any, x: number, y: number, amount: number):boolean
                keyDown(event: any, keycode: number):boolean
                keyUp(event: any, keycode: number):boolean
                keyTyped(event: any, character: number):boolean
            }
            export class TouchFocus {
            }
            export class Stage extends InputAdapter {
                viewport:any
                batch:any
                root:any
                width:number
                draw():void
                act(delta: number):void
                fireEnterAndExit(overLast: any, screenX: number, screenY: number, pointer: number):any
                touchDown(screenX: number, screenY: number, pointer: number, button: number):boolean
                touchDragged(screenX: number, screenY: number, pointer: number):boolean
                touchUp(screenX: number, screenY: number, pointer: number, button: number):boolean
                mouseMoved(screenX: number, screenY: number):boolean
                scrolled(amount: number):boolean
                keyDown(keyCode: number):boolean
                keyUp(keyCode: number):boolean
                keyTyped(character: number):boolean
                addTouchFocus(listener: any, listenerActor: any, target: any, pointer: number, button: number):void
                removeTouchFocus(listener: any, listenerActor: any, target: any, pointer: number, button: number):void
                cancelTouchFocus(actor: any):void
                cancelTouchFocusExcept(exceptListener: any, exceptActor: any):void
                addActor(actor: any):void
                addAction(action: any):void
                getActors():any
                addListener(listener: any):boolean
                removeListener(listener: any):boolean
                addCaptureListener(listener: any):boolean
                removeCaptureListener(listener: any):boolean
                clear():void
                unfocusAll():void
                unfocus(actor: any):void
                setKeyboardFocus(actor: any):boolean
                getKeyboardFocus():any
                setScrollFocus(actor: any):boolean
                getScrollFocus():any
                hit(stageX: number, stageY: number, touchable: boolean):any
                screenToStageCoordinates(screenCoords: any):any
                stageToScreenCoordinates(stageCoords: any):any
            }
            namespace ui {
                export function scaling_apply(sourceWidth: number, sourceHeight: number, targetWidth: number, targetHeight: number):any
                export enum Scaling {
                    FIT,
                    FILL,
                    FILLX,
                    FILLY,
                    STRETCH,
                    STRETCHX,
                    STRETCHY,
                    NONE,
                }
                export class Image extends Widget {
                    static region(region: any):Image
                    static ninepatch(patch: any):Image
                    layout():void
                    draw(batch: any, parentAlpha: number):void
                    setDrawable(drawable: any):void
                    getDrawable():any
                    setScaling(scaling: any):void
                    setAlign(align: number):void
                    getMinWidth():number
                    getMinHeight():number
                    getPrefWidth():number
                    getPrefHeight():number
                    getImageX():number
                    getImageY():number
                    getImageWidth():number
                    getImageHeight():number
                }
                export class Label extends Widget {
                    layout():void
                    draw(batch: any, parentAlpha: number):void
                    setStyle(style: any):void
                    getStyle():any
                    setText(newText: string):void
                    textEquals(other: string):boolean
                    getText():string
                    setAlignment(labelAlign: number, lineAlign: number):void
                }
                export class LabelLabelStyle {
                }
                export class Widget extends Actor {
                    sizeChanged():void
                    draw(batch: any, parentAlpha: number):void
                }
            }
            namespace utils {
                export enum FocusEventFocusEventType {
                    KEYBOARD,
                    SCROLL,
                }
                export class BaseDrawable {
                    constructor(config?: any)
                }
                export class ClickListener extends InputListener {
                    button:number
                    tapCount:number
                    touchDownX:number
                    pressedPointer:number
                    tapSquareSize:number
                    static visualPressedDuration:number
                    static with_button(button: number):ClickListener
                    touchDown(event: any, x: number, y: number, pointer: number, button: number):boolean
                    touchUp(event: any, x: number, y: number, pointer: number, button: number):void
                    touchDragged(event: any, x: number, y: number, pointer: number):void
                    enter(event: any, x: number, y: number, pointer: number, fromActor: any):void
                    exit(event: any, x: number, y: number, pointer: number, toActor: any):void
                    cancel():void
                    clicked(event: any, x: number, y: number):void
                    isOver(actor: any, x: number, y: number):boolean
                    inTapSquare(x: number, y: number):boolean
                    invalidateTapSquare():void
                    isPressed():boolean
                    isVisualPressed():boolean
                    setTapCountInterval(tapCountInterval: number):void
                }
                export class FocusEvent extends Event {
                    isFocused():boolean
                    setFocused(focused: boolean):void
                    getType():any
                    setType(focusType: any):void
                    getRelatedActor():any
                    setRelatedActor(relatedActor: any):void
                }
                export class FocusListener {
                    keyboardFocusChanged(event: any, actor: any, focused: boolean):void
                    scrollFocusChanged(event: any, actor: any, focused: boolean):void
                }
                export class NinePatchDrawable extends BaseDrawable {
                    static drawable(drawable: any):NinePatchDrawable
                    draw(batch: any, x: number, y: number, width: number, height: number):void
                    setPatch(patch: any):void
                    getPatch():any
                    tint(tint: any):any
                }
                export class TextureRegionDrawable extends BaseDrawable {
                    constructor(config?: any)
                    setRegion(region: any):void
                    getRegion():any
                }
            }
        }
    }
    
    namespace audio {
        export class Sound {
            play(loops: number):void
        }
    }
    namespace files {
        export class FileHandle {
            file:any
            path:string
            getRWops():any
            getType():any
            getName():string
            getExt():string
            getPath():string
            getParent():any
            exists():boolean
            child(name: string):any
            read():any
            bytes():any
        }
    }
    namespace math {
        export class Rectangle {
            static rectangle(rect: any):Rectangle
        }
        export class Vector2 {
            static X:graphics.Color
            static Y:graphics.Color
            static Zero:graphics.Color
            static vector(v: any):Vector2
            setZero():any
            set(x: number, y: number):any
        }

    }
    namespace utils {

        export enum Align {
            CENTER,
            TOP,
            BOTTOM,
            LEFT,
            RIGHT,
            TOPLEFT,
            TOPRIGHT,
            BOTTOMLEFT,
            BOTTOMRIGHT,
        }

        export class JSON {
            static parse(stream: any):any
        }
        export class Pool {
            newObject():any
            obtain():any
            free(object: any):void
            reset(object: any):void
            freeAll(objects: any[], objects_length1: number):void
            clear():void
            getFree():number
        }
        export class Pools {
            static get(type: any):any
            static set(type: any, pool: any):void
            static obtain(type: any):any
            static free(object: any):void
        }
    }

    export class JsGame {
        yield_for_events_ms:number
        profile:boolean
        mouseDown:boolean
        mouseX:number
        mouseY:number
        running:boolean
        name:string
        base:string
        fps:number
        showFps:boolean
        deltaTime:number
        font:any
        width:number
        height:number
        addSprite(sprite: any):void
        addOnce(sprite: any):void
        removeSprite(sprite: any):void
        setApplicationListener(listener: any):void
        initialize():void
        start():void
        getKey(code: number):number
        handleEvents():number
        draw():void
    }
    export class Application {
        setApplicationListener(listener: any):void
        run():number
        draw():void
        dispose():void
        initialize():boolean
    }
    export class Audio {
        newSound(file: any):any
    }
    export class Files {
        isResource:boolean
        resourcePath:string
        getHandle(path: string, type: any):any
        internal(path: string):any
        resource(path: string):any
        external(path: string):any
        absolute(path: string):any
        local(path: string):any
    }
    export class Game extends Application {
        create():void
        setScreen(screen: any):void
        getScreen():any
    }
    export class Graphics {
        deltaTime:number
        frames:number
        fps:number
        width:number
        height:number
        scale:number
        pixelFactor:number
        setSize(width: number, height: number):any
        updateTime():void
    }
    export class Input {
        setInputProcessor(processor: any):void
        processEvents():boolean
        get_keys(result_length1: number):number[]
    }
    export class InputAdapter {
    }
    export class Sdx {
        static app:JsGame
        static graphics:Graphics
        static audio:Audio
        static input:Input
        static files:File
    }
}