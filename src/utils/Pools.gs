/**
 * Pools.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses GLib

namespace sdx.utils

    class Pools: Object

        prop private static typePools: dict of Type, Pool = new dict of Type, Pool

        def static @get(type: Type): Pool 
            var pool = typePools[type]
            if pool == null
                pool = (Pool)Object.new(type)
                typePools[type] = pool

            return pool
        
        def static @set(type: Type, pool: Pool)
            typePools[type] = pool
        

        def static obtain(type: Type): Pool
            return @get(type)


        def static free(object: Object)
            if object == null do raise new Exception.IllegalArgumentException("object cannot be null.")
            var type = object.get_type()
            var pool = typePools[type]
            if pool == null do return
            pool.free(object)


