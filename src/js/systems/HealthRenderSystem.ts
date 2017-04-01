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
import {IComponent} from 'entitas'
import {HealthComponent} from 'components'
import {PositionComponent} from 'components'

// interface ILabelBMFont {
//   [key: string]: BitmapText
// }

export class HealthRenderSystem implements IExecuteSystem, ISetPool {
  // private texts:ILabelBMFont
  protected pool:Pool
  protected group:Group

  // constructor() {
  //   this.texts = {}
  // }

  public setPool(pool:Pool) {
    this.pool = pool
    this.group = pool.getGroup(Matcher.allOf(Matcher.Position, Matcher.Health))
    pool.getGroup(Matcher.Enemy).onEntityAdded.add(this.onEntityAdded)
    pool.getGroup(Matcher.Enemy).onEntityRemoved.add(this.onEntityRemoved)
  }

  public execute() {
    let entities = this.group.getEntities()
    for (let i = 0, l = entities.length; i < l; i++) {
      let e:Entity = entities[i]
      if (this.texts[e.id]) {
        let position:PositionComponent = e.position
        let health:HealthComponent = e.health
        let text:BitmapText = this.texts[e.id]

        let percentage:number = Math.round(health.health / health.maximumHealth * 100)
        text.position.set(position.x, position.y)
        text.text = `${percentage}%`
      }
    }
  }

  protected onEntityAdded = (group:Group, e:Entity, index:number, component:IComponent) => {
    // add a text element to the sprite
    let b:BitmapText = new BitmapText('100%', {font: '20px Radio Stars', align: 'left'})
    b.scale.set(0.5, 0.5)

    bosco['viewContainer'].addChild(b)
    this.texts[e.id] = b
  }

  protected onEntityRemoved = (group:Group, e:Entity, index:number, component:IComponent) => {
    // remove the text element from the sprite
    bosco['viewContainer'].removeChild(this.texts[e.id])
    this.texts[e.id] = null
    delete this.texts[e.id]
  }

}
