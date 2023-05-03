#pragma once

#include "action.h"
#include "actor.h"
#include "engine.h"
#include "hit.h"

class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};
