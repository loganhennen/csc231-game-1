#include "monsters.h"

#include "action.h"
#include "engine.h"
#include "hammer_big.h"
#include "knife.h"
#include "monster.h"
#include "monstertype.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    if (me.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            me.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    if (probability(66)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 30;
    return {"goblin", default_speed, health, std::make_shared<Hammer_big>(10),
            default_behavior};
}

MonsterType demon_big() {
    int health = 50;
    return {"demon_big", 8, health, std::make_shared<Hammer_big>(30),
            default_behavior};
}

MonsterType skeleton() {
    int health = 20;
    return {"skeleton", 8, health, std::make_shared<Knife>(20),
            default_behavior};
}

}  // namespace Monsters