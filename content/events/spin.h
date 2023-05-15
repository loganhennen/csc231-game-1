#pragma once

#include "event.h"
#include "hero.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Spin : public Event {
public:
    Spin(Actor& actor, Vec direction, int damage, Vec start_position,
         Vec end_position);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Actor& actor;
    Vec direction;
    int damage;
    Vec start_position;
    Vec end_position;
    int rotation;
};