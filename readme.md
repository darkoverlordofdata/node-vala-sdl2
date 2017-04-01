# sdx

node-vala-sdl2

sdx is writtem in vala/genie and is inspired by libGDX, but wraps SDL2 rather than OpenGL

this is a companion project to 
https://github.com/darkoverlordofdata/gjs-vala-sdl2

I want to ensure that what I am doing on the gnome js side still works on the node js side.
so in this project, I use node ffi to replace gnome gir.

Both projects will use the same vala copiled share library.

## install

```
$ git clone git@github.com:darkoverlordofdata/node-vala-sdl2.git
$ cd node-vala-sdl2
$ npm install
$ ./build
$ ./run
```

## todo
this version and the gjs version have made some tweaks to the sdx share library interface.
These changes need to be rolled back into the main sdx project and regressed.

