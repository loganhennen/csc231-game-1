#pragma once

#include "weapon.h"

class Hammer_big : public Weapon {
public:
    Hammer_big(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};