#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    for (int i = 0; i < 15; ++i) {
        engine.create_monster(Monsters::goblin());
    }
    engine.create_hero(Heros::nobody);
    engine.run();
}
