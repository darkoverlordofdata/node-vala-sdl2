
## notes

## performance

using gir/gjs, performance is about 20% slower
using node/ffi, performance is picks back up, about the same as pure vala.



## node or gjs?

this project started out for gjs using gir. I've swithced it over to use node.js using ffi.`

It's a no brainer:

* node has monumentally more resources than gjs
* node has es6
* node has better performance
* node-ffi is ad-hoc, gir requires alot of setup (g-ir-compiler, gir2dts)
* node works on windows, gjs does not



