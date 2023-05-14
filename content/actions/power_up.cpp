#include "power_up.h"

#include "action.h"
#include "actor.h"
#include "animatedsprite.h"
#include "attack.h"
#include "die.h"
#include "engine.h"
#include "event.h"
#include "hero.h"
#include "herotype.h"
#include "hit.h"
#include "monster.h"
#include "spin.h"
#include "vec.h"
#include "weapon.h"

Result PowerUp::perform(Engine& engine) {
    // this is just attached to the keybinding

    Vec direction = actor->get_direction();
    Vec start_position = actor->get_position();
    Vec end_position{actor->get_position()};

    while (true) {
        Tile& tile = engine.dungeon.tiles(end_position + direction);
        if (tile.is_door() || tile.is_wall()) {
            // stop spinning, weapon stays on tile
            break;
        } else if (tile.actor) {
            engine.events.add(Hit{*tile.actor, 100});
        }
        engine.events.add(Spin{tile.weapon->sprite, direction, 100,
                               start_position, end_position});
        end_position += direction;
    }
    if (direction == Vec{0, 1}) {
        Vec tiles2 = {end_position.x, end_position.y - 32};
        Tile& tile = engine.dungeon.tiles(end_position + direction - tiles2);
        std::swap(tile.weapon, engine.hero->type.weapon);
        // engine.events.add(Spin{tile.weapon->sprite, direction, 100,
        //                        start_position, end_position});
    } else if (direction == Vec{0, -1}) {
        Vec tiles2 = {end_position.x, end_position.y + 32};
        Tile& tile = engine.dungeon.tiles(end_position + direction - tiles2);
        std::swap(tile.weapon, engine.hero->type.weapon);
        // engine.events.add(Spin{tile.weapon->sprite, direction, 100,
        //                        start_position, end_position});
    } else if (direction == Vec{1, 0}) {
        Vec tiles2 = {end_position.x - 32, end_position.y};
        Tile& tile = engine.dungeon.tiles(end_position + direction - tiles2);
        std::swap(tile.weapon, engine.hero->type.weapon);
        // engine.events.add(Spin{tile.weapon->sprite, direction, 100,
        //                        start_position, end_position});
    } else {
        Vec tiles2 = {end_position.x + 32, end_position.y};
        Tile& tile = engine.dungeon.tiles(end_position + direction - tiles2);
        std::swap(tile.weapon, engine.hero->type.weapon);
        // engine.events.add(Spin{tile.weapon->sprite, direction, 100,
        //                        start_position, end_position});
    }
    return success();
}