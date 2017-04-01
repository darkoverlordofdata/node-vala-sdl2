/**
 * Pool Extensions
 * 
 * this is the entity factory
 */

import {Sdx} from 'Sdx'
import {Pool} from 'entitas'
import {Entity} from 'entitas'

import sdx = require('Sdx')
import TextureAtlas = sdx.graphics.s2d.TextureAtlas


export enum Layer {
  BACKGROUND,
  ENEMY1,
  ENEMY2,
  ENEMY3,
  PLAYER,
  PARTICLES,
}
export enum Effect {
  PEW,
  ASPLODE,
  SMALLASPLODE
}



const Tau = Math.PI*2


/**
 * Create the player
 */
Pool.prototype.createPlayer = function() {
  this.createEntity('Player')
    .addBounds(43)
    .addVelocity(0, 0)
    .addPosition(~~(Sdx.app.width/4), ~~(Sdx.app.height-80))
    .addLayer(Layer.PLAYER)
    .addResource('spaceshipspr')
    .setPlayer(true)
}


/**
 * Create a bullet at (x,y)
 *
 * @param x
 * @param y
 */
Pool.prototype.createBullet = function (x: number, y: number) {
  this.createEntity('Bullet')
    .addPosition(~~x, ~~y)
    .addVelocity(0, 800)
    .addBounds(5)
    .addExpires(1)
    .addSoundEffect(Effect.PEW)
    .addLayer(Layer.PARTICLES)
    .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
    .addResource('bullet')
    .setBullet(true)

}

/**
 * Create a particle at (x,y)
 *
 * @param x
 * @param y
 */
Pool.prototype.createParticle = function (x: number, y: number) {
  const radians: number = Math.random() * Tau
  const magnitude: number = Math.random()*200
  const velocityX = magnitude * Math.cos(radians)
  const velocityY = magnitude * Math.sin(radians)
  const scale = Math.random()

  this.createEntity('Particle')
    .addExpires(1)
    .addPosition(~~x, ~~y)
    .addVelocity(velocityX, velocityY)
    .addScale(scale, scale)
    .addLayer(Layer.PARTICLES)
    .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
    .addResource('star')
}

/**
 * Create a small explosion at (x,y)
 *
 * @param x
 * @param y
 */
Pool.prototype.createSmallExplosion = function (x: number, y: number) {
//        tint: {r:0xd2, g:0xfa, b:0xd2, a:0xfa},
  
  const scale = .2
  this.createEntity('SmallExp')
    .addExpires(0.5)
    .addScaleAnimation(scale / 100, scale, -3, false, true)
    .addPosition(~~x, ~~y)
    .addScale(scale, scale)
    .addLayer(Layer.PARTICLES)
    .addSoundEffect(Effect.SMALLASPLODE)
    .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
    .addResource('explosion')
}

/**
 * Create a big explosion at (x,y)
 *
 * @param x
 * @param y
 */
Pool.prototype.createBigExplosion = function (x: number, y: number) {
  const scale = .5
  this.createEntity('BigExp')
    .addExpires(0.5)
    .addScaleAnimation(scale / 100, scale, -3, false, true)
    .addPosition(~~x, ~~y)
    .addScale(scale, scale)
    .addLayer(Layer.PARTICLES)
    .addSoundEffect(Effect.ASPLODE)
    .addColorAnimation(0xd2, 0xff, 1, 0xfa, 0xff, 1, 0xa0, 0xff, 1, 0xfa, 0xff, 1, false, false, false, false, false)
    .addResource('explosion')
}

/**
 * Create enemy ship #1
 *
 */
Pool.prototype.createEnemy1 = function() {
  const x = Math.random() * (Sdx.app.width-40)+20
  const y = Sdx.app.height/2 - 200
  this.createEntity("Enemy1")
    .addBounds(20)
    .addPosition(~~x, ~~y)
    .addVelocity(0, -40)
    .addLayer(Layer.ENEMY1)
    .addResource('enemy1')
    .addHealth(10, 10)
    .setEnemy(true)

}

/**
 * Create enemy ship #2
 */
Pool.prototype.createEnemy2 = function() {
  const x = Math.random() * (Sdx.app.width-80)+40
  const y = Sdx.app.height/2 - 100
  this.createEntity("Enemy2")
    .addBounds(40)
    .addPosition(~~x, ~~y)
    .addVelocity(0, -30)
    .addLayer(Layer.ENEMY2)
    .addResource('enemy2')
    .addHealth(20, 20)
    .setEnemy(true)
}

/**
 * Create enemy ship #3
 */
Pool.prototype.createEnemy3 = function() {
  const x = Math.random() * (Sdx.app.width-140)+70
  const y = Sdx.app.height/2 - 50
  this.createEntity("Enemy3")
    .addBounds(70)
    .addPosition(~~x, ~~y)
    .addVelocity(0, -20)
    .addLayer(Layer.ENEMY3)
    .addResource('enemy3')
    .addHealth(60, 60)
    .setEnemy(true)
}

