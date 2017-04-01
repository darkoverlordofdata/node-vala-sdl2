import {createGame, Sdx, Input} from 'Sdx'
import {Systems} from 'entitas'
import {Pools} from 'components'  
import {MovementSystem} from 'systems/MovementSystem'
import {PlayerInputSystem} from 'systems/PlayerInputSystem'
import {SoundEffectSystem} from 'systems/SoundEffectSystem'
import {CollisionSystem} from 'systems/CollisionSystem'
import {ExpiringSystem} from 'systems/ExpiringSystem'
import {EntitySpawningTimerSystem} from 'systems/EntitySpawningTimerSystem'
import {ScaleAnimationSystem} from 'systems/ScaleAnimationSystem'
import {RemoveOffscreenShipsSystem} from 'systems/RemoveOffscreenShipsSystem'
import {AddViewSystem} from 'systems/AddViewSystem'
// import {HealthRenderSystem} from 'systems/HealthRenderSystem'
// import {HudRenderSystem} from 'systems/HudRenderSystem'
import {DestroySystem} from 'systems/DestroySystem'
//0.001451
//0.002207
import * as sdx from 'Sdx'

module example {

  function main() {

      const game = sdx.createGame("ShmupWarz", 640, 720, DATADIR) 
      const shmupwarz = new Shmupwarz()

      shmupwarz.start()
      game.profile = true
      game.start()
      while(game.running) {
          game.handleEvents()
          if (game.getKey(Input.Keys.Esc)) break
          else {
              shmupwarz.update(game.deltaTime)
              game.draw()
          }
      }
  }

  export class Shmupwarz {

    systems:Systems

    start() {
      this.systems = this.createSystems(Pools.pool)
      this.systems.initialize()
    }

    createSystems(pool) {
      return new Systems()
        .add(pool.createSystem(MovementSystem))
        .add(pool.createSystem(PlayerInputSystem))
        .add(pool.createSystem(SoundEffectSystem))
        .add(pool.createSystem(CollisionSystem))
        .add(pool.createSystem(ExpiringSystem))
        .add(pool.createSystem(EntitySpawningTimerSystem))
        .add(pool.createSystem(ScaleAnimationSystem))
        .add(pool.createSystem(RemoveOffscreenShipsSystem))
        .add(pool.createSystem(AddViewSystem))
        // .add(pool.createSystem(HealthRenderSystem))
        // .add(pool.createSystem(HudRenderSystem))
        .add(pool.createSystem(DestroySystem))
    }

    update(delta:number) {
      this.systems.execute()
    }
  }


  main()
}