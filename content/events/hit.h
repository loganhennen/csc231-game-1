#pragma once

#include "action.h"
#include "actor.h"
#include "engine.h"
#include "weapon.h"

class Hit : public Event {
public:
    Hit(Actor& actor, int damage);
    void execute(Engine& enigne) override;

private:
    Actor& actor;
    int damage;
};