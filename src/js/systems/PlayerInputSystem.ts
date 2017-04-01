import {Sdx} from 'Sdx'
import {Input} from 'Sdx'
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

export class PlayerInputSystem implements IExecuteSystem, IInitializeSystem, ISetPool {
  protected pool:Pool
  protected group:Group
  private static FireRate = .1
  protected timeToFire:number=0

  public execute() {
    let entities = this.group.getEntities()
    if (entities.length === 0) return

    let e = entities[0]

    let position:PositionComponent = e.position
    position.x = Sdx.app.mouseX
    position.y = Sdx.app.mouseY

    if (Sdx.app.mouseDown || Sdx.app.getKey(Input.Keys.z)) {
      if (this.timeToFire <= 0) {
        this.pool.createBullet(position.x - 27, position.y + 2)
        this.pool.createBullet(position.x + 27, position.y + 2)
        this.timeToFire = PlayerInputSystem.FireRate
      }
    }
    if (this.timeToFire > 0) {
      this.timeToFire -= Sdx.app.deltaTime
      if (this.timeToFire < 0) {
        this.timeToFire = 0
      }
    }
  }

  public initialize() {
    this.pool.createPlayer()
  }
  
  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.Player))
  }



}
