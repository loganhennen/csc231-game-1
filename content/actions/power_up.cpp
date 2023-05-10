// #include "power_up.h"

// #include "action.h"
// #include "actor.h"
// #include "engine.h"
// #include "hit.h"
// #include "vec.h"

// PowerUp::PowerUp(Actor& defender) : defender{defender} {}

// Result PowerUp::perform(Engine& engine) {
//     // find direction of hero
//     Vec direction = actor->get_direction();

//     // press keybinding to activate powerup (see heros.h)

//     // throw weapon
//      weapons use ...
//     engine.events.add(Spin{sprite, direction, defender, damage});

//     Tile& tile = engine.dungeon.tiles();
//     for (  // each tile direction + 1
//     ) {
//         if (tile.is_door() || tile.is_wall()) {
//             // stop spinning, weapon stays on tile
//             break;
//         } else if (tile.actor) {
//             engine.events.add(Hit{defender, 100});

//         } else {
//             // continue
//         }
//     }
//     // rotate weapon about the center axis to make spin

//     // if weapon on tile ... weapon can be picked up
//     // if actor uses powerup then weapon<none>
//     //
// }