/**
 * Import router
 * 
 * uniform entry point to gjs imports
 */

var __libSdx = imports.gi.sdx
var __libEntitas = imports.entitas.entitas


imports.shim.sdx(__libSdx)

var exports = {
    'Lang':                  { id: 'Lang',                  exports: imports.lang },
    'Gio':                   { id: 'Gio',                   exports: imports.gi.Gio },
    'Atk':                   { id: 'Atk',                   exports: imports.gi.Atk },
    'Gdk':                   { id: 'Gdk',                   exports: imports.gi.Gdk },
    'Gtk':                   { id: 'Gtk',                   exports: imports.gi.Gtk },
    'GLib':                  { id: 'GLib',                  exports: imports.gi.GLib },
    'Pango':                 { id: 'Pango',                 exports: imports.gi.Pango },
    'GObject':               { id: 'GObject',               exports: imports.gi.GObject },
    'Sdx':                   { id: 'Sdx',                   exports: __libSdx },
    'entitas':               { id: 'entitas',               exports: __libEntitas },
    'entitas.utils' :        { id: 'entitas.utils',         exports: __libEntitas.utils },
    'entitas.exceptions':    { id: 'entitas.exceptions',    exports: __libEntitas.exceptions },

}
