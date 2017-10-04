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

export class DestroySystem implements IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group

  public execute() {
    let entities = this.group.getEntities()
    for (let e of entities) {
      Sdx.app.removeSprite(<Sprite>e.sprite.object)
      this.pool.destroyEntity(e)
    }
  }
  
  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.Destroy))
  }
  


}
