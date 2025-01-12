#pragma once

#include "action.h"
#include "monstertype.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me);

MonsterType goblin();

MonsterType demon_big();

MonsterType skeleton();

}  // namespace Monsters
