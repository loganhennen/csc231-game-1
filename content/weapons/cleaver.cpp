#include "cleaver.h"

#include "action.h"
#include "die.h"
#include "engine.h"
#include "hero.h"
#include "hit.h"
#include "lightning.h"
#include "spin.h"
#include "swing.h"
#include "thrust.h"

Cleaver::Cleaver(int damage) : Weapon{"cleaver", damage} {}

void Cleaver::use(Engine& engine, Actor& attacker, Actor& defender) {
    // engine.events.add(Lightning{defender.get_position(), damage});
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Thrust{sprite, direction, defender, damage});
}
