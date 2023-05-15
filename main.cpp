#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_monster(Monsters::goblin());
    engine.create_monster(Monsters::demon_big());
    for (int i = 0; i < 20; ++i) {
        engine.create_monster(Monsters::skeleton());
    };

    for (int y{0}; y < engine.dungeon.tiles.height; ++y) {
        for (int x{0}; x < engine.dungeon.tiles.width; ++x) {
            Tile& tile = engine.dungeon.tiles(Vec{x, y});
            tile.weapon = std::make_shared<None>();
        }
    };

    engine.create_hero(Heros::nobody);
    engine.run();
}
