#include "hammer_big.h"

#include "die.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"

Hammer_big::Hammer_big(int damage) : Weapon{"hammer_big", damage} {}

void Hammer_big::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}