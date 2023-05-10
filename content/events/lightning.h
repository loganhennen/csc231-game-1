#pragma once

#include "animatedsprite.h"
#include "event.h"

class Lightning : public Event {
public:
    Lightning(Vec position, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Vec position;
    int damage;
    AnimatedSprite sprite;  // load during execute
};