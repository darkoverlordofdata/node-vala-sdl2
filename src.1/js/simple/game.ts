import {createGame, Sdx, Input} from 'Sdx'

import * as entities from 'entities'
import * as systems from 'systems'


function main() {

    const game = createGame("ShmupWarz", 640, 640, DATADIR) 

    entities.createPool(game)
    game.profile = true
    game.start()
    while(game.running) {
        game.handleEvents()
        if (game.getKey(Input.Keys.Esc)) break
        else {
            systems.collisionSystem(game, entities)
            systems.expireSystem(game, entities)
            systems.removalSystem(game, entities)
            systems.spawnSystem(game, entities)
            systems.tweenSystem(game, entities)
            systems.inputSystem(game, entities)
            systems.physicsSystem(game, entities)
            systems.healthSystem(game, entities)
            systems.soundSystem(game, entities)
            game.draw()
        }
    }

}

main()