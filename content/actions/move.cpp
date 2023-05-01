#include "move.h"

#include <iostream>

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "opendoor.h"
#include "rest.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    actor->change_direction(direction);

    // bool is_even = (position.x + position.y) % 2 == 0;
    // for (auto& [p, door] : engine.dungeon.doors) {
    //     // for each position p and door
    //     if (is_even) {
    //         door.open();
    //     } else {
    //         door.close();
    //     }
    // }

    // for (auto& [pos, door] : engine.dungeon.doors) {
    //     door.open();
    // }

    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_wall()) {
        return failure();
    }
    if (tile.is_door()) {
        actor->move_to(position);
        return alternative(OpenDoor(position));
    }

    // attack if (tile.actor)
    if (tile.actor) {
        return alternative(Attack{*tile.actor});
    }

    actor->move_to(position);
    return success();
}