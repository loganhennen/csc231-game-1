#include "power_up.h"

#include "action.h"
#include "actor.h"
#include "animatedsprite.h"
#include "die.h"
#include "engine.h"
#include "event.h"
#include "hero.h"
#include "herotype.h"
#include "hit.h"
#include "monster.h"
#include "spin.h"
#include "vec.h"
#include "weapon.h"

PowerUp::PowerUp(Actor& defender) : defender{defender} {}

Result PowerUp::perform(Engine& engine) {
    engine.events.add(Spin{tile.weapon, direction, defender, attacker, 100,
                           start_position, end_position});
    return success();
}