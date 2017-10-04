/**
 * ApplicationListener.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses sdx.utils

namespace sdx.scenes.scene2d

    class abstract Action : Object implements Poolable

        prop pool: Pool
        prop target: Actor
        prop actor: Actor
            get 
                return _actor
            set 
                _actor = value
                if _target == null do _target = actor
                if _actor == null    
                    if pool != null
                        pool.free(this)
                        pool = null

        def abstract act(delta: double):bool

        def restart()
            pass

        def reset()
            actor = null
            target = null
            pool = null
            restart()            

        _actor: Actor

        