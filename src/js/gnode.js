/**
 *  Copyright 2017 darkoverlordofdata
 * 
 * gnode is a cross-browserish
 * simple module loader for the desktop
 * 
 */
;(function(scope){
    /**
     * define amd loader
     */
    Object.defineProperties(scope, {
        define: { value: (function (modules) {
            return (name, deps, callback) => {
                if (typeof name !== 'string') { /* browserify bundle */
                    const bundle = deps()
                    for (name in bundle) 
                        modules[name] = { id: name, exports: bundle[name] }

                } else { /* amd module */
                    modules[name] = { id: name, exports: {} }
                    const args = [(name) => modules[name] ? modules[name].exports : imports[name], 
                                modules[name].exports]
                    for (let i = 2; i < deps.length; i++)
                        args.push(modules[deps[i]].exports)
                    callback.apply(modules[name].exports, args)
                }
            }
        }(typeof imports === 'undefined' 
            ? require(DATADIR)
            : (function(){
                imports.searchPath.unshift(DATADIR); return imports.modules.exports }())
        ))}
    })
    Object.defineProperties(define, {
        amd:     { value: true },
        version: { value: '0.2.0' },
    }) 
    if (typeof console === 'undefined') {
        Object.defineProperties(scope, {
            console: {value: {      
                log()   { print.apply(null, arguments) },
                warn()  { print.apply(null, arguments) },
                error() { print.apply(null, arguments) },
                info()  { print.apply(null, arguments) }
            }},    
        })
    } else {
        Object.defineProperties(scope, {
            print:      { value: function() { console.log(arguments[0]) } },
            log:        { value: function() { console.info(arguments[0]) } },
            logError:   { value: function() { console.warn(arguments[0]) } },
            printerr:   { value: function() { console.error(arguments[0]) } },
        })
    }
})(typeof window === 'undefined' ? global : window)
