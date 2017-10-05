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

const T1:number = 2//1 //2
const T2:number = 6//5 //6
const T3:number = 12//7 //12


export class EntitySpawningTimerSystem implements IExecuteSystem, IInitializeSystem, ISetPool {

  protected pool:Pool
  protected enemyT1 = 0
  protected enemyT2 = 0
  protected enemyT3 = 0

  public initialize() {
    // this.enemyT1 = 2.0
    // this.enemyT2 = 6.0
    // this.enemyT3 = 12.0
  }

  public execute() {

    this.enemyT1 = this.spawn(this.pool, this.enemyT1, 1)
    this.enemyT2 = this.spawn(this.pool, this.enemyT2, 2)
    this.enemyT3 = this.spawn(this.pool, this.enemyT3, 3)

  }

  spawn(pool, t, enemy) {
      let deltaTime = Sdx.app.deltaTime
      const d1 = t-deltaTime
      if (d1<0) {
          switch(enemy) {
              case 1: pool.createEnemy1(); return 1
              case 2: pool.createEnemy2(); return 5
              case 3: pool.createEnemy3(); return 7
          }
      } else return d1
  }

  public setPool(pool:Pool) {
    this.pool = pool
  }

}
