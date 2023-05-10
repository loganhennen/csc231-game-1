#pragma once

#include "event.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Spin : public Event {
public:
    Spin(Sprite& sprite, Vec direction, Actor& defender, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    Vec direction;
    Actor& defender;
    int damage;
};