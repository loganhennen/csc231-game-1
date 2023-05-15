#include "rest_hero.h"

#include "actor.h"
#include "engine.h"

Result Rest_Hero::perform(Engine& engine) {
    if (engine.hero->health < engine.hero->max_health) {
        engine.hero->health += 5;
    }
    return success();
}