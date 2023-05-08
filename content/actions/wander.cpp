#include "wander.h"

#include "actor.h"
#include "engine.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"
#include "vec.h"

Result Wander::perform(Engine& engine) {
    // get the current position and neighbors
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);

    // randomize neighbors
    shuffle(std::begin(neighbors), std::end(neighbors));

    //  for each one, find a non occupied tile or not wall
    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (!tile.is_wall() && !tile.actor) {
            //       direction=tile position-position
            Vec direction = neighbor - position;

            //       return alternative move
            return alternative(Move{direction});
        }
    }

    // if no good tiles
    // rest
    return alternative(Rest{});
}