/**
 * Pool.gs
 *
 * 
 *
 */
[indent=4]
uses sdx
uses GLib

namespace sdx.utils

    interface Poolable   
        def abstract reset()

    class abstract Pool : Object


        max : int = 0xffff
        peak: int

        freeObjects: Queue of Object

        def abstract newObject(): Object

        def obtain(): Object
            return freeObjects.get_length() == 0 ? newObject() : freeObjects.pop_head()
    
        def free(object: Object)
            if object == null do raise new Exception.IllegalArgumentException("object cannot be null.")
            if freeObjects.get_length() < max
                freeObjects.push_head(object)
                peak = (int)Math.fmax(peak, freeObjects.get_length())
            reset(object)

        def reset(object: Object)
            if object isa Poolable do ((Poolable)object).reset()

        def freeAll(objects: array of Object)
            if objects == null do raise new Exception.IllegalArgumentException("objects cannot be null.")
            
            for var i = 0 to (objects.length-1)
                var object = objects[i]
                if object == null do continue
                if freeObjects.get_length() < max do freeObjects.push_head(object)
                reset(object)
            peak = (int)Math.fmax(peak, freeObjects.get_length())
                
                
        def clear()
            freeObjects.clear()

        def getFree(): int  
            return (int)freeObjects.get_length()
