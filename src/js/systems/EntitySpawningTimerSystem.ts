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
  protected enemyT1 = 0//T1
  protected enemyT2 = T2/2
  protected enemyT3 = T3/2

  public execute() {

    let deltaTime = Sdx.app.deltaTime

    function spawn(pool, t, enemy) {
        const d1 = t-deltaTime
        if (d1<0) {
            switch(enemy) {
                case 1: pool.createEnemy1(); return T1
                case 2: pool.createEnemy2(); return T2
                case 3: pool.createEnemy3(); return T3
            }
        } else return d1
    }
    this.enemyT1 = spawn(this.pool, this.enemyT1, 1)
    this.enemyT2 = spawn(this.pool, this.enemyT2, 2)
    this.enemyT3 = spawn(this.pool, this.enemyT3, 3)

  }

  public initialize() {
  }

  public setPool(pool:Pool) {
    this.pool = pool
  }

}
