/**
 * Screen.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx

    interface Screen : Object

        def abstract show()
        def abstract render()
        def abstract resize(width: int, height: int)
        def abstract pause()
        def abstract resume()
        def abstract hide()
        def abstract dispose()
        