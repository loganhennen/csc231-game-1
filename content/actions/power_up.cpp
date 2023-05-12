#include "power_up.h"

#include "action.h"
#include "actor.h"
#include "die.h"
#include "engine.h"
#include "event.h"
#include "hero.h"
#include "herotype.h"
#include "hit.h"
#include "spin.h"
#include "vec.h"
#include "weapon.h"

PowerUp::PowerUp(Actor& defender) : defender{defender} {}

Result PowerUp::perform(Engine& engine) {
    // find direction of hero
    Vec direction = actor->get_direction();
    Vec end_position{actor->get_position()};

    while (true) {
        Tile& tile = engine.dungeon.tiles(end_position + direction);
        if (tile.is_door() || tile.is_wall()) {
            // stop spinning, weapon stays on tile
            break;
        } else if (tile.actor) {
            engine.events.add(Hit{defender, 100});
        }
        end_position += direction;
    }
    Tile& tile = engine.dungeon.tiles(end_position + direction);
    std::swap(tile.weapon, engine.hero->type.weapon);
    Vec start_position = actor->get_position();
    engine.events.add(
        Spin{sprite, direction, defender, 100, start_position, end_position});
    return success();
}