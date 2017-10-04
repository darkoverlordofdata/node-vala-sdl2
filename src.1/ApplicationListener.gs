/**
 * ApplicationListener.gs
 *  port of libgdx.
 * 
 *
 */
[indent=4]
namespace sdx
    interface ApplicationListener : Object
        def abstract create()
        def abstract resize(width: int, height: int)
        def abstract render()
        def abstract pause()
        def abstract resume()
        def abstract dispose()
        