#pragma once

#include "event.h"
#include "hero.h"
#include "sprite.h"
#include "vec.h"

class Actor;

class Spin : public Event {
public:
    Spin(HeroType& herotype, Vec direction, int damage, Vec start_position,
         Vec end_position);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    HeroType& herotype;
    Vec direction;
    int damage;
    Vec& start_position;
    Vec& end_position;
    int rotation;
};