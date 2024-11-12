#include <iostream>
#include "Globals.h"
#include "Game.hpp"


int main()
{
    Globals globals{};

    globals.setCheat(true);
    globals.setClearOn(5);

    Game g{GameType::Addition, globals};
    g.startGame();
}