#include "spin.h"

#include <cmath>

#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "weapon.h"

constexpr int duration = 10;

Spin::Spin(Sprite& sprite, Vec direction,  // Actor& defender,  Actor& attacker,
           int damage, Vec start_position, Vec end_position)
    : Event{duration},
      sprite{sprite},
      direction{direction},
      //   defender{defender},
      //   attacker{attacker},
      damage{damage},
      start_position{start_position},
      end_position{end_position} {
    sprite.center = sprite.size / 2;

    if (direction == Vec{0, 1}) {
        direction = direction * -1;
    } else if (direction == Vec{0, -1}) {
        sprite.shift.y += 8;
    }
}

void Spin::execute(Engine& engine) {
    if (direction == Vec{0, 1} || direction == Vec{0, -1}) {
        sprite.shift += direction * -2;
        double num_tiles = ((end_position.y - start_position.y) / 16);
        sprite.angle = (sprite.angle + 360 / (duration - 1)) * num_tiles;
    } else {
        sprite.shift += direction * 2;
        double num_tiles = ((end_position.x - start_position.x) / 16);
        sprite.angle = (sprite.angle + 360 / (duration - 1)) * num_tiles;
    }
}

// void Spin::when_done(Engine& engine) {
//     engine.events.add(Hit{defender, 100});
// }
