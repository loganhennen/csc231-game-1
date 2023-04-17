#pragma once

#include "action.h"
#include "vec.h"

class Move : public Action {
public:
    Result perform(Engine& engine) override;
    Move(Vec direction);

private:
    Vec direction;
};