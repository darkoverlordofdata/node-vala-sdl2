/**
 * gjs.d.ts
 * 
 * Gjs basic declarations for typescript
 */

declare const DATADIR: string
/**
 * Command line args
 */
declare const ARGV: string[]
/**
 * print to console
 */
declare function print(...args: any[])
declare function printerr(...args: any[])
declare function log(message: any)
declare function logError(message: any)
/**
 * get module as value
 */
declare function require(name: string): any
/**
 * localization - imports.gettext.gettext
 */
declare function _(str:string): string

/** 
 * native imports
 * 
 * not very helpful, these 'import' values, not types
 */
// declare namespace imports {
//     var cairo: any
//     var dbus: any
//     var format: any
//     var gettext: any
//     var gi: any
//     var jsUnit: any
//     var lang: any
//     var promise: any
//     var misc: any
//     var signals: any
//     var ui: any
// }

/**
 * extend String with imports.format.format
 */
declare interface String  {
    printf(...args: any[]): string
}

/**
 * Gnome class polyfills
 */
declare module "Lang" {
    export function Class(properties: any)
}
