#include "thrust.h"

#include "engine.h"
#include "hit.h"

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{3},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {
    sprite.shift.y -= sprite.size.y / 4;
    sprite.center.x -= sprite.size.x / 2;

    if (direction == Vec{1, 0}) {
        sprite.angle = 90;
    } else if (direction == Vec{-1, 0}) {
        sprite.angle = -90;
    } else if (direction == Vec{0, 1}) {
        sprite.angle = 0;
        this->direction = direction * -1;
    } else if (direction == Vec{0, -1}) {
        sprite.angle = 180;
        this->direction = direction * -1;
    }
}

void Thrust::execute(Engine&) {
    sprite.shift += direction * 1;
}

void Thrust::when_done(Engine& engine) {
    sprite = original;

    engine.events.add(Hit{defender, damage});
}