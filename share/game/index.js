/**
 * Libs
 * 
 * Load the nodejs libs
 * 
 */
const __libSdx = require('./lib/sdx')
const __libEntitas = require('./lib/entitas')

module.exports = {
    'Sdx':                  { id: 'Sdx',                    exports: __libSdx },
    'entitas':              { id: 'entitas',                exports: __libEntitas },
    'entitas.utils' :       { id: 'entitas.utils',          exports: __libEntitas.utils },
    'entitas.exceptions':   { id: 'entitas.exceptions',     exports: __libEntitas.exceptions },
}

