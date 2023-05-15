#include "spin.h"

#include <cmath>

#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "weapon.h"

Spin::Spin(Actor& actor, Vec direction, int damage, Vec start_position,
           Vec end_position)
    : Event{static_cast<int>(distance(end_position, start_position) * 10.0)},
      actor{actor},
      direction{direction},
      damage{damage},
      start_position{start_position},
      end_position{end_position} {
    actor.weapon->sprite.center = actor.weapon->sprite.size / 2;
    rotation = 30 * std::copysign(1, direction.x);
    this->direction.y *= -1;
}

void Spin::execute(Engine&) {
    actor.weapon->sprite.shift = direction * frame_count / 10.0 * 16;
    actor.weapon->sprite.angle += rotation;
}

void Spin::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(end_position);
    std::swap(actor.weapon, tile.weapon);
    Sprite none = engine.graphics.get_sprite("none");
    actor.weapon->sprite = none;
    tile.weapon->sprite.shift =
        Vec{-tile.weapon->sprite.size.x / 2, -tile.weapon->sprite.size.y};
}
