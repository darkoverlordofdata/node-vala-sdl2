[indent=4]
namespace sdx.utils

    class StringTokenizer

        currentPosition: private int
        newPosition: private int 
        maxPosition: private int 
        str: private string 
        delimiters: private string 
        retDelims: private bool
        delimsChanged: private bool
        maxDelimCodePoint: private int
        hasSurrogates: bool = false
        delimiterCodePoints: array of int

        construct(str: string, delim: string = " \t\n\r\f", returnDelims: bool = false)
            currentPosition = 0
            newPosition = -1
            delimsChanged = false
            this.str = str
            maxPosition = str.length
            delimiters = delim
            retDelims = returnDelims
            setMaxDelimCodePoint()
            
        def private setMaxDelimCodePoint()
            if delimiters == null
                maxDelimCodePoint = 0
                return

            var m = 0
            var c = 0
            var count = 0
            for var i=0 to (delimiters.length-1)
                c = delimiters[i]
                if m < c do m = c
                count++
            
            maxDelimCodePoint = m

        def skipDelimiters(startPos: int): int
            if delimiters == null
                raise new Exception.NullPointerException("delimiters")

            var position = startPos
            while !retDelims && position < maxPosition
                var c = str[position]
                if (c > maxDelimCodePoint) || isDelimiter(c) do break
                position += 1

            return position


        def scanToken(startPos: int): int
            var position = startPos
            while position < maxPosition
                var c = str[position]
                if (c <= maxDelimCodePoint) && isDelimiter(c) do break
                position += 1
                
            if retDelims && (startPos == position)
                var c = str[position]
                if (c <= maxDelimCodePoint) && isDelimiter(c) do position += 1

            return position


        def isDelimiter(c: char): bool
            for var i = 0 to (delimiters.length-1)
                if delimiters[i] == c do return true
            return false

        def hasMoreTokens(): bool
            newPosition = skipDelimiters(currentPosition)
            return newPosition < maxPosition

        def nextToken(delim:string = ""): string
            if delim > ""
                delimiters = delim
                delimsChanged = true

            currentPosition = newPosition >= 0 && !delimsChanged ? newPosition : skipDelimiters(currentPosition)

            delimsChanged = false
            newPosition = -1

            if currentPosition >= maxPosition do raise new Exception.NoSuchElementException("")
            var start = currentPosition
            currentPosition = scanToken(currentPosition)
            return str.substring(start, currentPosition)

        

        def hasMoreElements(): bool
            return hasMoreTokens()

        def nextElement(): Object
            return (Object)nextToken()

        def countTokens(): int
            var count = 0
            var currpos = currentPosition
            while currpos < maxPosition
                currpos = skipDelimiters(currpos)
                if currpos >= maxPosition do break
                currpos = scanToken(currpos)
                count++

            return count
