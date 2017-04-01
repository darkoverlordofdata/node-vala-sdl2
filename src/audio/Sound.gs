/**
 * Sound.gs
 *
 * Author: 
 *      bruce davidson
 */
[indent=4]
uses sdx.files

namespace sdx.audio

    class Sound : Object

        chunk : SDLMixer.Chunk

        construct(file: FileHandle)

            if Sdx.files.isResource && file.getType() == FileType.Resource
                var ptr = file.bytes()
                var rw = new SDL.RWops.from_mem((void*)ptr.get_data(), (int)ptr.get_size())
                chunk = new SDLMixer.Chunk.WAV_RW(rw)
            
            else
                chunk = new SDLMixer.Chunk.WAV(file.getPath())

        def play(loops: int = 0)            
            SDLMixer.play(-1, chunk, loops)
