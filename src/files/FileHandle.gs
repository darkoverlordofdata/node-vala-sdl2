[indent=4]
uses sdx

namespace sdx.files


    class FileHandle : Object
        prop readonly file: File
        prop readonly path: string
        _type: FileType
    
        construct(fileName: string, type: FileType)
            _type = type
            _path = fileName
            if Sdx.files.isResource && type == FileType.Resource && fileName.substring(0,1) != "/"
                _file = File.new_for_path(Sdx.files.resourcePath + Sdx.files.separator + fileName)
            else
                if fileName.substring(0, 1) == "/"
                    _file = File.new_for_path(fileName)
                else
                    _file = File.new_for_path(Sdx.files.resourcePath + Sdx.files.separator + fileName)

        /**
         * getRWops
         *
         * get the raw memory content of the underlying file
         */
        def getRWops(): SDL.RWops
            if Sdx.files.isResource //&& file.getType() == FileType.Resource
                var ptr = GLib.resources_lookup_data(getPath(), 0)
                var raw = new SDL.RWops.from_mem((void*)ptr.get_data(), (int)ptr.get_size())
                sdlFailIf(raw == null, "Unable to get resource "+getPath())
                return raw
            
            else 
                var raw = new SDL.RWops.from_file(getPath(), "rb")
                sdlFailIf(raw == null, "Unable to get file "+getPath())
                return raw
            

        def getType(): FileType
            return _type

        def getName(): string
            return file.get_basename()
            
        def getExt(): string
            var name = getName()
            var i = name.last_index_of(".")
            if i < 0 do return ""
            return name.substring(i)

        def getPath(): string
            return file.get_path()

        def getParent(): FileHandle
            return new FileHandle(file.get_parent().get_path(), _type)

        def exists(): bool
            if Sdx.files.isResource && _type == FileType.Resource
                return true // we must assume that the resource is there
            else
                return file.query_exists()

        def child(name: string): FileHandle
            return new FileHandle(file.get_path() + Sdx.files.separator + name, _type)
        

        def read(): InputStream
            
            if Sdx.files.isResource && _type == FileType.Resource
                return GLib.resources_open_stream(file.get_path(), 0)
            else
                var project = File.new_for_path(file.get_path())
                if project.query_exists()
                    return project.read()
                else
                    print "file %s not found", file.get_path()
                    return null
        


        def bytes(): GLib.Bytes
            return GLib.resources_lookup_data(getPath(), 0)
