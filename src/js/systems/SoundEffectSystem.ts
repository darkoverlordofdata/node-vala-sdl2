import {Sdx} from 'Sdx'
import {Pool} from 'entitas'
import {Group} from 'entitas'
import {Entity} from 'entitas'
import {Matcher} from 'entitas'
import {Exception} from 'entitas'
import {TriggerOnEvent} from 'entitas'
import {IExecuteSystem} from 'entitas'
import {IInitializeSystem} from 'entitas'
import {ISetPool} from 'entitas'
import {SoundEffectComponent} from 'components'
import {Effect} from 'extensions'

import sdx = require('Sdx')

export class SoundEffectSystem implements IInitializeSystem, IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group
  private pew:sdx.audio.Sound
  private asplode:sdx.audio.Sound
  private smallasplode:sdx.audio.Sound

  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.SoundEffect))
  }

  public execute() {
    let entities = this.group.getEntities()
    for (let e of entities) {
      let soundEffect:SoundEffectComponent = e.soundEffect
      switch(soundEffect.effect) {
        case Effect.PEW:          this.pew.play(0); break
        case Effect.ASPLODE:      this.asplode.play(0); break
        case Effect.SMALLASPLODE: this.smallasplode.play(0); break
      }
      e.removeSoundEffect()
    }
  }

  public initialize() {

    this.pew = sdx.createSound("sounds/pew.wav")
    this.asplode = sdx.createSound("sounds/asplode.wav")
    this.smallasplode = sdx.createSound("sounds/smallasplode.wav")

  }
}
