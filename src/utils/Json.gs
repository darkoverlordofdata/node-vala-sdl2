/**
 * Json.gs
 *
 * 
 *
 */
[indent=4]
namespace sdx.utils

    class JSON : Object

        def static parse(stream: InputStream): Json.Object
            var st = new BufferedInputStream(stream)
            var sb = new StringBuilder()
            buffer: array of uint8 = new array of uint8[100]
            size: ssize_t

            var ready = true
            while ready
                size = st.read(buffer)
                if size > 0
                    sb.append_len((string) buffer, size)
                else
                    ready = false

            var parser = new Json.Parser()
            parser.load_from_data(sb.str, -1)
            return parser.get_root().get_object()
