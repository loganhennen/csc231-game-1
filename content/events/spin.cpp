#include "spin.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 10;

Spin::Spin(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{3},
      sprite{sprite},
      copy{sprite},
      defender{defender},
      damage{damage},
      starting_angle{sprite.angle} {
    sprite.center = 360 / ;

    if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta_angle = 180 / ((duration / 2) - 1);
        delta_angle = 360 / ((duration / 2) - 1);

    } else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta_angle = -180 / ((duration / 2) - 1);
        delta_angle = -360 / ((duration / 2) - 1);
    } else if (direction == Vec{0, 1}) {
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = -75 * sign;
        delta_angle = 90.0 / ((duration / 2) - 1) * sign;
        delta_angle = -75 / ((duration / 2) - 1) * sign;
        sprite.shift.y -= 12;
    } else {
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 135 * sign;
        delta_angle = 270 / ((duration / 2) - 1) * sign;
        delta_angle = 135 / ((duration / 2) - 1) * sign;
    }
}

void Spin::execute(Engine&) {
    sprite.angle = starting_angle + delta_angle * frame_count;
}

void Spin::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, 100});
}