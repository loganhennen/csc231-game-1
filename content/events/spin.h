#pragma once

#include "event.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Spin : public Event {
public:
    Spin(Sprite& sprite, Vec direction, int damage, Vec start_position,
         Vec end_position);
    void execute(Engine& engine) override;
    // void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Vec direction;
    int damage;
    Vec& start_position;
    Vec& end_position;
};