#include "hammer_big.h"

#include "die.h"
#include "engine.h"
#include "hit.h"

Hammer_big::Hammer_big(int damage) : Weapon{"hammer_big", damage} {}

void Hammer_big::use(Engine& engine, Actor& attacker, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}