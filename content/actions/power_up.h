#pragma once

#include "action.h"

class PowerUp : public Action {
public:
    PowerUp(Actor& defender);
    Result perform(Engine& engine) override;

private:
    Actor& defender;
};