#include "none.h"

None::None() : Weapon("none", 10) {}

void None::use(Engine&, Actor&, Actor& defender) {
    defender.take_damage(damage);
}
