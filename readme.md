# node-vala-sdl2

sdx is writtem in vala/genie and is inspired by libGDX, but wraps SDL2 rather than OpenGL

sdx can be used from vala or javascript.

runs on gnode (either gjs or node)


## install

```
$ git clone git@github.com:darkoverlordofdata/node-vala-sdl2.git
$ cd node-vala-sdl2
$ npm install
$ ./build
$ tsc
$ gjs bin/game
$ node bin/game
```

## performance

shmupwarz avg ms per frame over 10k frames

    gjs	        node	    vala
0.005094	0.004424	0.004566

## the winner

is node.js
* slightly faster performance
* windows compatible
* es6




## todo

merge this into zerog

### notes
* use zerog Sdx as the core api
* make a scripting wrapper using genie
* genie's prop keyword exposes field access, cleaner script api 