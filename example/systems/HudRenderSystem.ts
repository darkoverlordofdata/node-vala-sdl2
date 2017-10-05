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

export class HudRenderSystem implements IInitializeSystem, IExecuteSystem, ISetPool {

  protected pool:Pool
  protected group:Group
  private activeEntities:BitmapText
  private totalCreated:BitmapText
  private totalDeleted:BitmapText

  public initialize() {
    let font = {font: '36px Radio Stars', align: 'left'}
    this.activeEntities = new BitmapText("Active entitiez:           ", font)
    this.totalCreated = new BitmapText("Total created:          ", font)
    this.totalDeleted = new BitmapText("Total deleted:          ", font)

    this.activeEntities.scale.set(0.5)
    this.totalCreated.scale.set(0.5)
    this.totalDeleted.scale.set(0.5)

    this.activeEntities.position.set(0, 20)
    this.totalCreated.position.set(0, 40)
    this.totalDeleted.position.set(0, 60)

    bosco['viewContainer'].addChild(this.activeEntities)
    bosco['viewContainer'].addChild(this.totalCreated)
    bosco['viewContainer'].addChild(this.totalDeleted)

  }

  public execute() {
    let pool:Pool = this.pool
    let size:number = pool.count
    this.activeEntities.text = "Active entities: " + size
    this.totalCreated.text = "Total created: " + pool.reusableEntitiesCount
    this.totalDeleted.text = "Total deleted: " + (pool._creationIndex-size)
  }

  public setPool(pool:Pool) {
    this.pool = pool
  }



}
