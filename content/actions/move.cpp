#include "move.h"

#include <iostream>

#include "actor.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    actor->move_to(position + direction);
    return success();
}