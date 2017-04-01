/**
 * Sprite.gs
 *
 * Wrapper for Texture with a Surface
 *
 * Copyright 2016 Dark Overlord of Data
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the he MIT License (MIT).
 *
 * Author: 
 *      bruce davidson
 */
[indent=4]
uses SDL
uses SDL.Video
uses SDLImage
uses SDLTTF
uses GLib
uses sdx
uses sdx.files

namespace sdx.graphics.s2d

    struct Scale
        x : double
        y : double

    class Sprite : Object

        uniqueId : static int = 0
        texture : Video.Texture
        prop width : int
        prop height : int
        prop x : int
        prop y : int
        scale : Scale = Scale() { x = 1.0, y = 1.0 }
        //color : Color = Color() { r = 255, g = 255, b = 255, a = 255 }
        prop r: int = 255
        prop g: int = 255
        prop b: int = 255
        prop a: int = 255
        prop centered : bool = true
        prop layer : int = 0
        id : int = ++uniqueId
        path: string

        construct(path: string="")
            if path != "" do this.file(Sdx.files.resource(path))
            //pass

        /**
         *  Create sprite from fileHandle
         *
         * @param file fileHandle
         */
        construct file(file: FileHandle)
            path = file.getPath()
            var raw = file.getRWops()
            if raw == null do return
            sdlFailIf(raw == null, @"Unable to load RWops for Sprite.file: $path")
            var surface = Texture.getSurface(file.getExt(), raw)

            texture = Video.Texture.create_from_surface(Sdx.app.renderer, surface)
        
            sdlFailIf(texture == null, @"Unable to load image texture in Sprite.file: $path")
            texture.set_blend_mode(Video.BlendMode.BLEND)

            width = surface.w
            height = surface.h

        /**
         *  Create sprite from Atlas region
         *
         * @param region Atlas region
         */
        construct region(region: TextureAtlas.AtlasRegion)
            var flags = (uint32)0x00010000  // SDL_SRCALPHA
            var rmask = (uint32)0x000000ff  
            var gmask = (uint32)0x0000ff00
            var bmask = (uint32)0x00ff0000
            var amask = (uint32)0xff000000

            var x = region.top
            var y = region.left
            var w = region.width
            var h = region.height
            var surface = new Video.Surface.legacy_rgb(flags, region.width, region.height, 
                    32, rmask, gmask, bmask, amask)
            region.texture.data.blit({x, y, w, h}, surface, {0, 0, w, h})
            this.texture = Video.Texture.create_from_surface(Sdx.app.renderer, surface)
            sdlFailIf(this.texture == null, "Unable to load image texture Sprite.region!")
            this.texture.set_blend_mode(Video.BlendMode.BLEND)
            this.width = surface.w
            this.height = surface.h
            this.path = region.name

        /**
         *  Create sprite from text value of a Sprite.fromRenderedText
         *
         * @param text string of text to generate
         * @param font used to generate text
         * @param color foregound text color (background transparent)
         */
        construct text(text : string, font : Font, color : sdx.graphics.Color)
            var surface = font.render(text, color)

            texture = Video.Texture.create_from_surface(Sdx.app.renderer, surface)
            sdlFailIf(texture == null, "Unable to load image texture Sprite.text!")

            texture.set_blend_mode(Video.BlendMode.BLEND)
            width = surface.w
            height = surface.h
            path = ""


        def setScale(x:double, y:double)
            scale.x = x
            scale.y = y

        def setColor(r:int, g:int, b:int)
            _r = r
            _g = g
            _b = b

        /**
         *  Change the text value of a Sprite.fromRenderedText
         *
         * @param text string of text to generate
         * @param font used to generate text
         * @param color foregound text color (background transparent)
         */
        def setText(text : string, font : Font, color : sdx.graphics.Color)
            var surface = font.render(text, color)

            texture = Video.Texture.create_from_surface(Sdx.app.renderer, surface)
            sdlFailIf(texture == null, "Unable to load image texture Sprite.setText!")

            texture.set_blend_mode(Video.BlendMode.BLEND)
            width = surface.w
            height = surface.h
            path = ""

        /**
         *  Render the sprite on the Video.Renderer context
         *
         * @param renderer video context
         * @param x display coordinate
         * @param y display coordinate
         * @param clip optional clipping rectangle
         */
        def render(renderer: Video.Renderer, x : int, y : int, clip : Video.Rect? = null)
            if texture == null do return
            /* do clipping? */
            var w = (int)((clip == null ? width : clip.w) * scale.x)
            var h = (int)((clip == null ? height : clip.h) * scale.y)

            /* center in display? */
            x = centered ? x-(w/2) : x
            y = centered ? y-(h/2) : y

            /* apply current tint */
            //texture.set_color_mod(color.r, color.g, color.b)
            texture.set_color_mod((uint8)_r, (uint8)_g, (uint8)_b)
            /* copy to the rendering context */
            renderer.copy(texture, null, {x, y, w, h})


