#pragma once

#include "action.h"
#include "vec.h"

class Pickup : public Action {
public:
    Result perform(Engine& engine) override;
};