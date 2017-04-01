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
import {ScaleComponent} from 'components'
import {ScaleAnimationComponent} from 'components'

import sdx = require('Sdx')
import Sprite = sdx.graphics.s2d.Sprite

export class ScaleAnimationSystem implements IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group

  public execute() {
    let delta = Sdx.app.deltaTime
    let entities = this.group.getEntities()
    for (let e of entities) {

      let scaleAnimation:ScaleAnimationComponent = e.scaleAnimation

      if (scaleAnimation.active) {
        let scale:ScaleComponent = e.scale

        scale.x += scaleAnimation.speed * delta
        scale.y = scale.x

        if (scale.x > scaleAnimation.max) {
          scale.x = scaleAnimation.max
          scale.y = scale.x
          scaleAnimation.active = false
        } else if (scale.x < scaleAnimation.min) {
          scale.x = scaleAnimation.min
          scale.y = scale.x
          scaleAnimation.active = false
        }
        let sprite:Sprite = <Sprite>(e.sprite.object)
        sprite.setScale(scale.x, scale.y)

      }
    }
  }
  
  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.ScaleAnimation))
  }
  


}
