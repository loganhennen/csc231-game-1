#include "cleaver.h"

#include "die.h"
#include "engine.h"
#include "hit.h"
#include "lightning.h"
#include "swing.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    engine.events.add(Lightning{defender.get_position(), damage});
    // Vec direction = defender.get_position() - attacker.get_position();
    // engine.events.add(Swing{sprite, direction, defender, damage});
}
