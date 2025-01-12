#pragma once

#include "attack.h"
#include "cleaver.h"
#include "closedoor.h"
#include "engine.h"
#include "herotype.h"
#include "knife.h"
#include "move.h"
#include "none.h"
#include "pickup.h"
#include "power_up.h"
#include "rest.h"
#include "rest_hero.h"
#include "vec.h"
#include "weapon.h"

namespace Heros {
// Reaction = std::function<std::unique_ptr<Action>()>
// std:: unique_ptr do_stuff();
const std::unordered_map<std::string, Reaction> keybindings = {
    {"A",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"D",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"W",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"S",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"R", []() { return std::make_unique<Rest_Hero>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }},
    {"Space", []() { return std::make_unique<PowerUp>(); }},
    {"E", []() { return std::make_unique<Pickup>(); }}};

constexpr int default_speed{8};
const HeroType nobody{"dragon", default_speed, 210,
                      std::make_shared<Cleaver>(30), keybindings};

}  // namespace Heros
