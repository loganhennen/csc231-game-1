#pragma once

#include "action.h"

class PowerUp : public Action {
public:
    Result perform(Engine& engine) override;
};