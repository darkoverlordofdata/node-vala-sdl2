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


export class ExpiringSystem implements IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group

  public execute() {
    let pool = this.pool
    let entities = this.group.getEntities()
    for (let e of entities) {
      if ((e.expires.delay -= Sdx.app.deltaTime) <= 0) {
        e.isDestroy = true
      }
    }
  }
  
  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.Expires))
  }

}
