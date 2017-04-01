/**
 * api shim for gjs
 * normalizes the api for javascript
 */
import * as sdx from 'Sdx'

Object.defineProperties(sdx, {
    createGame: {value: function(t, h, w, b) {
        const g = sdx.createJsGame(t, h, w, b)

        // fix some camel case property names
        Object.defineProperties(g, {
            mouseX:         {get: () => g.get_mouse_x()},
            mouseY:         {get: () => g.get_mouse_y()},
            mouseDown:      {get: () => g.get_mouse_down()},
            showFps:        {get: () => g.get_show_fps()},
            deltaTime:      {get: () => g.get_delta_time()}
        })
        Object.defineProperties(sdx.Sdx.graphics, {
            deltaTime:      {get: () => sdx.Sdx.graphics.get_deltaTime()},
            pixelFactor:    {get: () => sdx.Sdx.graphics.get_pixelFactor()}
        })
        Object.defineProperties(sdx.Sdx.files, {
            isResource:     {get: () => sdx.Sdx.files.get_isResource()},
            resourcePath:   {get: () => sdx.Sdx.files.get_resourcePath()}
        })

        return g
    }}
})

// fix some static property names
Object.defineProperties(sdx.Sdx, {
    app:        {get: () => sdx.Sdx.get_app()},
    graphics:   {get: () => sdx.Sdx.get_graphics()},
    audio:      {get: () => sdx.Sdx.get_audio()},
    input:      {get: () => sdx.Sdx.get_input()},
    files:      {get: () => sdx.Sdx.get_files()}
})

// fix enums
Object.defineProperties(sdx, { graphics: { value: {}}})
Object.defineProperties(sdx.graphics, { Color: { value: {}}})
Object.defineProperties(sdx.graphics.Color, {
    CLEAR:      {get: () => sdx.graphicsColor.get_CLEAR()},
    BLACK:      {get: () => sdx.graphicsColor.get_BLACK()},
    WHITE:      {get: () => sdx.graphicsColor.get_WHITE()},
    LIGHT_GRAY: {get: () => sdx.graphicsColor.get_LIGHT_GRAY()},
    GRAY:       {get: () => sdx.graphicsColor.get_GRAY()},
    DARK_GRAY:  {get: () => sdx.graphicsColor.get_DARK_GRAY()},
    BLUE:       {get: () => sdx.graphicsColor.get_BLUE()},
    NAVY:       {get: () => sdx.graphicsColor.get_NAVY()},
    ROYAL:      {get: () => sdx.graphicsColor.get_ROYAL()},
    SLATE:      {get: () => sdx.graphicsColor.get_SLATE()},
    SKY:        {get: () => sdx.graphicsColor.get_SKY()},
    CYAN:       {get: () => sdx.graphicsColor.get_CYAN()},
    TEAL:       {get: () => sdx.graphicsColor.get_TEAL()},
    GREEN:      {get: () => sdx.graphicsColor.get_GREEN()},
    CHARTREUSE: {get: () => sdx.graphicsColor.get_CHARTREUSE()},
    LIME:       {get: () => sdx.graphicsColor.get_LIME()},
    FOREST:     {get: () => sdx.graphicsColor.get_FOREST()},
    OLIVE:      {get: () => sdx.graphicsColor.get_OLIVE()},
    YELLOW:     {get: () => sdx.graphicsColor.get_YELLOW()},
    GOLD:       {get: () => sdx.graphicsColor.get_GOLD()},
    GOLDENROD:  {get: () => sdx.graphicsColor.get_GOLDENROD()},
    ORANGE:     {get: () => sdx.graphicsColor.get_ORANGE()},
    BROWN:      {get: () => sdx.graphicsColor.get_BROWN()},
    TAN:        {get: () => sdx.graphicsColor.get_TAN()},
    FIREBRICK:  {get: () => sdx.graphicsColor.get_FIREBRICK()},
    RED:        {get: () => sdx.graphicsColor.get_RED()},
    SCARLET:    {get: () => sdx.graphicsColor.get_SCARLET()},
    SALMON:     {get: () => sdx.graphicsColor.get_SALMON()},
    PINK:       {get: () => sdx.graphicsColor.get_PINK()},
    MAGENTA:    {get: () => sdx.graphicsColor.get_MAGENTA()},
    PURPLE:     {get: () => sdx.graphicsColor.get_PURPLE()},
    VIOLET:     {get: () => sdx.graphicsColor.get_VIOLET()},
    MAROON:     {get: () => sdx.graphicsColor.get_MAROON()}
})

Object.defineProperties(sdx.Input, {
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
})



