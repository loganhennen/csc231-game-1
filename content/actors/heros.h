#pragma once

#include "attack.h"
#include "cleaver.h"
#include "closedoor.h"
#include "herotype.h"
#include "move.h"
#include "none.h"
#include "rest.h"
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
    {"R", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }}  // ,
    // {"Space", []() { return std::make_unique<Attack>(); }}
};

constexpr int default_speed{8};
const HeroType nobody{"dragon", default_speed, 1, std::make_shared<Cleaver>(1),
                      keybindings};

}  // namespace Heros
