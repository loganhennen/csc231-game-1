#include "knife.h"

#include "die.h"
#include "engine.h"
#include "hit.h"

Knife::Knife(int damage) : Weapon{"knife", damage} {}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}