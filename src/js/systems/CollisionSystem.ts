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
import {HealthComponent} from 'components'
import {ScoreComponent} from 'components'
import {BoundsComponent} from 'components'
import {Effect} from 'extensions'


export class CollisionSystem implements IInitializeSystem, IExecuteSystem, ISetPool {

  protected pool: Pool
  protected group: Group
  protected bullets: Group
  protected enemies: Group
  private collisionPairs: Array<CollisionPair>

  public setPool(pool: Pool) {
    this.pool = pool
  }

  /**
   * Check for Collision
   */
  public execute() {
    let collisionPairs = this.collisionPairs
    for (let pair of collisionPairs)
      pair.checkForCollisions()
  }

  /**
   * Create collision handlers
   */
  public initialize() {
    this.pool.setScore(0)
    this.bullets = this.pool.getGroup(Matcher.Bullet)
    this.enemies = this.pool.getGroup(Matcher.Enemy)

    /** Check for bullets hitting enemy ship */
    this.collisionPairs = []
    this.collisionPairs.push(new CollisionPair(this, this.bullets, this.enemies, {

      handleCollision: (bullet: Entity, ship: Entity) => {
        let bp: PositionComponent = bullet.position
        let health: HealthComponent = ship.health
        let position: PositionComponent = ship.position
        let x = bp.x
        let y = bp.y

        this.pool.createSmallExplosion(x, y)
        let i = 3
        while (--i > 0) this.pool.createParticle(x, y)

        bullet.setDestroy(true)
        health.health -= 2
        if (health.health < 0) {
          let score: ScoreComponent = <ScoreComponent>(this.pool.score)
          this.pool.replaceScore(score.value + ship.health.maximumHealth)
          ship.setDestroy(true)
          this.pool.createBigExplosion(position.x, position.y)
        }
      }
    }))
  }
}


/**
 *
 */
class CollisionPair {
  private groupEntitiesA: Group
  private groupEntitiesB: Group
  private handler: CollisionHandler
  private cs: CollisionSystem

  constructor(cs: CollisionSystem, group1, group2, handler: CollisionHandler) {
    this.groupEntitiesA = group1
    this.groupEntitiesB = group2
    this.handler = handler
    this.cs = cs
  }

  public checkForCollisions() {
    let handler = this.handler
    let groupEntitiesA = this.groupEntitiesA.getEntities()
    let groupEntitiesB = this.groupEntitiesB.getEntities()
    let sizeA = groupEntitiesA.length
    let sizeB = groupEntitiesB.length

    for (let a = 0; sizeA > a; a++) {
      let entityA: Entity = groupEntitiesA[a]
      for (let b = 0; sizeB > b; b++) {
        let entityB: Entity = groupEntitiesB[b]
        if (this.collisionExists(entityA, entityB)) {
          handler.handleCollision(entityA, entityB)
        }
      }
    }
  }

  private collisionExists(e1: Entity, e2: Entity): boolean {

    if (e1 === null || e2 === null) return false

    let p1: PositionComponent = e1.position
    let p2: PositionComponent = e2.position

    let b1: BoundsComponent = e1.bounds
    let b2: BoundsComponent = e2.bounds

    let a = p1.x - p2.x
    let b = p1.y - p2.y
    return Math.sqrt(a * a + b * b) - (b1.radius) < (b2.radius)
  }
}

interface CollisionHandler {
  handleCollision(a: Entity, b: Entity)
}

