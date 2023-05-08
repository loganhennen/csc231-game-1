#pragma once

#include "event.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Swing : public Event {
public:
    Swing(Sprite& sprite, Vec direction, Actor& defender, int damage);

    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    Actor& defender;
    int damage;
    double starting_angle, delta_angle;
};