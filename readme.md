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



## todo
changes made to sdx vala code -

    some fields were elevated to properties
    mew class JsGame


These changes need to be rolled back into the main sdx project and regressed.

how do I intgrate this with Bosco?

