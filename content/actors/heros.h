#pragma once

#include "herotype.h"
#include "none.h"

namespace Heros {

constexpr int default_speed{8};
const HeroType nobody{"dragon", default_speed, 1, std::make_shared<None>(), {}};

// namespace Heros

// Reaction = std::function<std::unique_ptr<Action>()>
// std:: unique_ptr do_stuff();
const std::unordered_map<std::string, Reaction> keybindings = {
    {"A", []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }}};  // namespace Heros
const HeroType nobody{"shy-guy", default_speed, 1, std::make_shared<None>(),
                      keybindings};
}  // namespace Heros
