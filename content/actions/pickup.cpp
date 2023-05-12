#include "pickup.h"

#include "actor.h"
#include "engine.h"
#include "hero.h"

Result Pickup::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(actor->get_position());
    if (tile.weapon) {
        std::swap(engine.hero->type.weapon, tile.weapon);
        return success();
    }
    return failure();
}