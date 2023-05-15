#include "pickup.h"

#include "actor.h"
#include "engine.h"
#include "hero.h"

Result Pickup::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec direction = actor->get_direction();
    Tile& tile = engine.dungeon.tiles(position + direction);
    if (tile.weapon) {
        std::swap(engine.hero->type.weapon, tile.weapon);
        return success();
    }
    return failure();
}