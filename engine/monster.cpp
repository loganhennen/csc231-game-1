#include "monster.h"

#include "engine.h"

constexpr int TEAM_MONSTER = 1;
constexpr double WEAPON_ANGLE = 20;

Monster::Monster(Engine& engine, MonsterType type, const Vec& position)
    : Actor{engine, position, type.max_health, TEAM_MONSTER, type.speed},
      type{type} {
    sprite = engine.graphics.get_animated_sprite(type.sprite_name, 1, true);
    this->weapon = type.weapon;
    type.weapon = nullptr;
    weapon->sprite = engine.graphics.get_sprite(weapon->name);
    weapon->sprite.shift.x = sprite.get_sprite().size.x / 8;
    weapon->sprite.angle = WEAPON_ANGLE;
    weapon->sprite.center = {weapon->sprite.size.x / 2, weapon->sprite.size.y};
}

void Monster::attack(Actor& defender) {
    weapon->use(engine, *this, defender);
}

void Monster::change_direction(const Vec& dir) {
    direction = dir;
    if (direction.x == 1) {
        sprite.flip(false);
        weapon->sprite.flip = false;
        weapon->sprite.shift.x = sprite.get_sprite().size.x / 8;
        weapon->sprite.angle = WEAPON_ANGLE;
    } else if (direction.x == -1) {
        sprite.flip(true);
        weapon->sprite.flip = true;
        weapon->sprite.shift.x = -sprite.get_sprite().size.x / 2;
        weapon->sprite.angle = -WEAPON_ANGLE;
    }
}

void Monster::update() {
    sprite.update();
}

std::unique_ptr<Action> Monster::take_turn() {
    return type.behavior(engine, *this);
}

std::vector<Sprite> Monster::get_sprites() const {
    auto s = sprite.get_sprite();
    return {weapon->sprite, s};
}
