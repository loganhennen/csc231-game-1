#pragma once

#include "action.h"
#include "vec.h"

class OpenDoor : public Action {
public:
    Result perform(Engine& engine) override;
    OpenDoor(Vec position);

private:
    Vec position;
};