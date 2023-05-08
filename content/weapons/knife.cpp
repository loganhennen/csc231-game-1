#include "knife.h"

#include "die.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "vec.h"

Knife::Knife(int damage) : Weapon{"knife", damage} {}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender) {
        Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Thrust{sprite, direction, defender, damage});
}