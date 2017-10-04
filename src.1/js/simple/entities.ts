/**
 * Entity Factory
 */
import * as sdx from 'Sdx'
import {Sdx} from 'Sdx'

const Tau = 6.28318
const BULLETS = 20
const ENEMY1 = 18
const ENEMY2 = 7
const ENEMY3 = 5
const ENEMIES = ENEMY1+ENEMY2+ENEMY3
const EXPLOSIONS = 8
const BANGS = 16
const PARTICLES = 80
const bangQ = []
const enemy1Q = []
const enemy2Q = []
const enemy3Q = []
const bulletQ = []
const particleQ = []
const explosionQ = []
export const active = []
export const pool = new Array(2+BULLETS+ENEMIES+EXPLOSIONS+BANGS+PARTICLES)

let uniqueId = 0


export function createPool(game) {
    let z = 0 
    active.push(pool[z++] = createPlayer())
    active.push(pool[z++] = createBackground())
    for (let i=0; i<BULLETS; i++)    bulletQ.push(pool[z++] = createBullet())
    for (let i=0; i<ENEMY1; i++)     enemy1Q.push(pool[z++] = createEnemy1())
    for (let i=0; i<ENEMY2; i++)     enemy2Q.push(pool[z++] = createEnemy2())
    for (let i=0; i<ENEMY3; i++)     enemy3Q.push(pool[z++] = createEnemy3())
    for (let i=0; i<EXPLOSIONS; i++) explosionQ.push(pool[z++] = createExplosion())
    for (let i=0; i<BANGS; i++)      bangQ.push(pool[z++] = createBang())
    for (let i=0; i<PARTICLES; i++)  particleQ.push(pool[z++] = createParticle())
    game.addSprite(active[0].sprite)
    game.addSprite(active[1].sprite)
    Object.freeze(pool)
}

function removeEntity(a, e) {
    let i = a.indexOf(e)
    if (i > -1) {
        if (a[i].id !== e.id) throw new Error("Invalid remove id")
        return a.splice(i,1)[0]
    }
}

export function deactivate(game, e) {
    if (!e.active) {
        print("already deactivated")
        return
    }
    e.active = false
    let z = removeEntity(active, e)
    if (!z) {
        print("z undefined")
        if (!e.active) {
            print("and already deactivated")
        }
        return
    }
    if (z.id !== e.id) {
        throw new Error("removed wrong entity")
    }
    game.removeSprite(e.sprite)
    if (e.bang) bangQ.push(e)
    else if (e.particle) particleQ.push(e)
    else if (e.explosion) explosionQ.push(e)
    else if (e.bullet) bulletQ.push(e)
    else if (e.enemy) switch(e.model) {
        case 1: enemy1Q.push(e); break
        case 2: enemy2Q.push(e); break
        case 3: enemy3Q.push(e); break
    }
}

export function bang(game, x, y) {
    if (bangQ.length) {
        const e = bangQ.pop()
        e.active = true
        e.position.x = x
        e.position.y = y
        e.scale.x = 0.2
        e.scale.y = 0.2
        e.tween.active = true
        e.expires = 0.2
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate bang")
    }
}

export function particle(game, x, y) {
    if (particleQ.length) {
        const e = particleQ.pop()
        e.active = true
        e.position.x = x
        e.position.y = y
        e.expires = 0.5
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate particle")
    }
}

export function explosion(game, x, y) {
    if (explosionQ.length) {
        const e = explosionQ.pop()
        e.active = true
        e.position.x = x
        e.position.y = y
        e.tween.active = true
        e.scale.x = 0.5
        e.scale.y = 0.5
        e.expires = 0.2
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate explosion")
    }
}

export function bullet(game, x, y) {
    if (bulletQ.length) {
        const e = bulletQ.pop()
        e.active = true
        e.position.x = x
        e.position.y = y
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate bullet")
    }
}

export function enemy1(game) {
    if (enemy1Q.length) {
        const e = enemy1Q.pop()
        e.position.x = Math.random()*(game.width - e.bounds.w) + e.bounds.w/2
        e.position.y = e.bounds.h
        e.health.current = e.health.maximum
        e.active = true
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate enemy1")
    }
}

export function enemy2(game) {
    if (enemy2Q.length) {
        const e = enemy2Q.pop()
        e.position.x = Math.random()*(game.width - e.bounds.w) + e.bounds.w/2
        e.position.y = e.bounds.h
        e.health.current = e.health.maximum
        e.active = true
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate enemy2")
    }
}

export function enemy3(game) {
    if (enemy3Q.length) {
        const e = enemy3Q.pop()
        e.position.x = Math.random()*(game.width - e.bounds.w) + e.bounds.w/2
        e.position.y = e.bounds.h
        e.health.current = e.health.maximum
        e.active = true
        game.addSprite(e.sprite)
        active.push(e)
    } else {
        throw new Error("Unable to allocate enemy3")
    }
}

function createBackground() {
    // sprite defaults to layer 0
    const sprite = sdx.createSprite('images/BackdropBlackLittleSparkBlack.png')
    sprite.centered = false
    return {
        id: uniqueId++,
        active: true,
        scale: {x: 3, y: 3},
        position: {x: 0, y: 0},
        velocity: {x: 0, y: 0},
        sprite: sprite        
    }
}

function createPlayer() {
    const sprite = sdx.createSprite('images/spaceshipspr.png')
    sprite.layer = 8
    return {
        id: uniqueId++,
        player: true,
        active: true,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        velocity: {x: 0, y: 0},
        sprite: sprite
    }
}

function createBullet() {
    const sprite = sdx.createSprite('images/bullet.png')
    sprite.layer = 9
    return {
        id: uniqueId++,
        bullet: true,
        active: false,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        velocity: {x: 0, y: -800},
        tint: {r:0xd2, g:0xfa, b:0, a:0xff},
        sound: sdx.createSound("sounds/pew.wav"),
        sprite: sprite
    }
}

function createEnemy1() {
    const text = sdx.createText("100%", Sdx.app.font, sdx.graphics.Color.CHARTREUSE)
    const sprite = sdx.createSprite('images/enemy1.png')
    sprite.layer = 5
    return {
        id: uniqueId++,
        enemy: true,
        active: false,
        model: 1,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        velocity: {x: 0, y: 40},
        health: {current: 10, maximum: 10},
        text: text,
        sprite: sprite
    }
}

function createEnemy2() {
    const text = sdx.createText("100%", Sdx.app.font, sdx.graphics.Color.CHARTREUSE)
    const sprite = sdx.createSprite('images/enemy2.png')
    sprite.layer = 6
    return {
        id: uniqueId++,
        enemy: true,
        active: false,
        model: 2,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        velocity: {x: 0, y: 30},
        health: {current: 20, maximum: 20},
        text: text,
        sprite: sprite
    }
}

function createEnemy3() {
    const text = sdx.createText("100%", Sdx.app.font, sdx.graphics.Color.CHARTREUSE)
    const sprite = sdx.createSprite('images/enemy3.png')
    sprite.layer = 7
    return {
        id: uniqueId++,
        enemy: true,
        active: false,
        model: 3,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        velocity: {x: 0, y: 20},
        health: {current: 60, maximum: 60},
        text: text,
        sprite: sprite
    }
}

function createExplosion() {
    const sprite = sdx.createSprite('images/explosion.png')
    sprite.layer = 10
    return {
        id: uniqueId++,
        explosion: true,
        active: false,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        scale: {x: 0.5, y: 0.5},
        tween: {min: 0.5/100, max: 0.5, speed:-3, repeat:false, active:true},
        tint: {r:0xd2, g:0xfa, b:0xd2, a:0xfa},
        sound: sdx.createSound("sounds/asplode.wav"),
        expires: 0.2,
        sprite: sprite
    }
}

function createBang() {
    const sprite = sdx.createSprite('images/explosion.png')
    sprite.layer = 10
    return {
        id: uniqueId++,
        bang: true,
        active: false,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        scale: {x: 0.2, y: 0.2},
        tween: {min: 0.2/100, max: 0.2, speed:-3, repeat:false, active:true},
        tint: {r:0xd2, g:0xfa, b:0xd2, a:0xfa},
        sound: sdx.createSound("sounds/smallasplode.wav"),
        expires: 0.2,
        sprite: sprite
    }
}

function createParticle() {
    const radians = Math.random() * Tau
    const magnitude = Math.ceil(Math.random()*200)
    const velocityX = magnitude * Math.cos(radians)
    const velocityY = magnitude * Math.sin(radians)
    const scale = Math.random()
    const sprite = sdx.createSprite('images/star.png')
    sprite.layer = 10
    return {
        id: uniqueId++,
        particle: true,
        active: false,
        bounds: {x: 0, y: 0, w: sprite.width, h: sprite.height},
        position: {x: 0, y: 0},
        scale: {x: scale, y: scale},
        velocity: {x: velocityX, y: velocityY},
        tint: {r:0xfa, g:0xfa, b:0xd2, a:0xff},
        expires: 0.5,
        sprite: sprite
    }
}
