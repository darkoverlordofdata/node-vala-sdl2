/**
 * Libs
 * 
 * seed the module loader with connonjs libs
 * 
 */
//require('coffeescript/register')
const __libSdx = require('./sdx')
const __libEntitas = require('./entitas')

module.exports = {
    'Sdx':                  { id: 'Sdx',                    exports: __libSdx },
    'entitas':              { id: 'entitas',                exports: __libEntitas },
    'entitas.utils' :       { id: 'entitas.utils',          exports: __libEntitas.utils },
    'entitas.exceptions':   { id: 'entitas.exceptions',     exports: __libEntitas.exceptions },
}

//Sdx - export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/home/bruce/.local/lib/"
