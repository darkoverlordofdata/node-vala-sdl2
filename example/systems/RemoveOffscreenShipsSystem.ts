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
import {PositionComponent} from 'components'

import sdx = require('Sdx')
import Sprite = sdx.graphics.s2d.Sprite

export class RemoveOffscreenShipsSystem implements IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group

  public execute() {
    let height = Sdx.app.height
    let pool = this.pool
    let entities = this.group.getEntities()
    for (let e of entities) {
      if (e.position.y > height - e.bounds.radius) {
        e.isDestroy = true
        Sdx.app.removeSprite(<Sprite>e.sprite.object)
      }
    }
  }
  
  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.Velocity, Matcher.Position, Matcher.Health, Matcher.Bounds))
  }
  


}
