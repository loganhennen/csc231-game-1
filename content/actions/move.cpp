#include "move.h"

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    actor->move_to(position + direction);
    return success();
}

Move::Move(Vec direction) : direction{direction} {}
