#include "pickup.h"

#include "actor.h"
#include "engine.h"
#include "hero.h"

Result Pickup::perform(Engine& engine) {
    Vec position = actor->get_position();
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.weapon->name == "none") {
        return failure();
    } else {
        std::swap(actor->weapon, tile.weapon);
        return success();
    }
}