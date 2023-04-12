#pragma once

#include "action.h"

class Move : public Action {
public:
    Result perform(Engine& engine) override;
};