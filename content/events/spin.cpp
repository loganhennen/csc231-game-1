#include "spin.h"

#include <cmath>

#include "actor.h"
#include "engine.h"
#include "hit.h"
#include "weapon.h"

Spin::Spin(HeroType& herotype, Vec direction, int damage, Vec start_position,
           Vec end_position)
    : Event{static_cast<int>(distance(end_position, start_position) * 5.0)},
      herotype{herotype},
      direction{direction},
      damage{damage},
      start_position{start_position},
      end_position{end_position} {
    herotype.weapon->sprite.center = herotype.weapon->sprite.size / 2;
    rotation = 30 * std::copysign(1, direction.x);
    direction.y *= -1;
}

void Spin::execute(Engine&) {
    herotype.weapon->sprite.shift += direction * 1;
    herotype.weapon->sprite.angle += rotation;
}

void Spin::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(end_position);
    std::swap(herotype.weapon, tile.weapon);
}
