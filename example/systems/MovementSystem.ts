import {Sdx} from 'Sdx'
import {Pool} from 'entitas'
import {Group} from 'entitas'
import {Entity} from 'entitas'
import {Matcher} from 'entitas'
import {Exception} from 'entitas'
import {TriggerOnEvent} from 'entitas'
import {IExecuteSystem} from 'entitas'
import {ISetPool} from 'entitas'

import sdx = require('Sdx')
import Sprite = sdx.graphics.s2d.Sprite


export class MovementSystem implements IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group

  public execute() {
    let entities = this.group.getEntities()
    for (let e of entities) {
      let delta = Sdx.app.deltaTime
      e.position.x += (e.velocity.x * delta)
      e.position.y -= (e.velocity.y * delta)
      let sprite:Sprite = <Sprite>e.sprite.object
      sprite.x = e.position.x
      sprite.y = e.position.y
    }
  }
  
  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.Position, Matcher.Velocity))
  }
}

