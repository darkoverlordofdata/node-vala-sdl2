import {Sdx} from 'Sdx'
import {Pool} from 'entitas'
import {Group} from 'entitas'
import {Entity} from 'entitas'
import {Matcher} from 'entitas'
import {ISetPool} from 'entitas'
import {Exception} from 'entitas'
import {IComponent} from 'entitas'
import {TriggerOnEvent} from 'entitas'
import {PositionComponent} from 'components'

import sdx = require('Sdx')
import Sprite = sdx.graphics.s2d.Sprite
import TextureAtlas = sdx.graphics.s2d.TextureAtlas

export class AddViewSystem implements ISetPool {
  protected pool:Pool
  protected group:Group
  protected atlas:TextureAtlas
  
  constructor() {
      this.atlas = sdx.createAtlas('pack.atlas')
  }

  /**
   * Watch for Resource Added
   *
   * @param pool
   */
  public setPool(pool:Pool) {
    this.pool = pool
    pool.getGroup(Matcher.Resource).onEntityAdded.add(this.onEntityAdded)
  }

  /**
   * OnEntityAdded - Resource component.
   *
   * Load & configure the sprite for this resource component
   *
   * @param group
   * @param e
   * @param index
   * @param component
   */
  protected onEntityAdded = (group:Group, e:Entity, index:number, component:IComponent) => {

    let sprite:Sprite = this.atlas.createSprite(e.resource.name, -1)
    let position = e.position

    sprite.x = position.x
    sprite.y = position.y
    if (e.hasScale) {
      let scale = e.scale
      sprite.setScale(scale.x, scale.y)
    }
    sprite.layer = e.layer.ordinal
    if (e.hasColorAnimation) {
        sprite.r = e.colorAnimation.redMin
        sprite.g = e.colorAnimation.greenMin
        sprite.b = e.colorAnimation.blueMin
        sprite.a = e.colorAnimation.alphaMin
    }

    Sdx.app.addSprite(sprite)
    e.addSprite(sprite.layer, sprite)
  }


}
