/**
 * Exception.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx

    exception Exception 
        IllegalArgumentException
        IllegalStateException
        SdxRuntimeException
        NullPointerException
        NoSuchElementException
        SDLException

    exception IOException 
        FileNotFound
        FileNoPermission
        FileIsLocked
        InvalidData
