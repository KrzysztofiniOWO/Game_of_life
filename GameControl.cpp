#include "GameOfLife.h"
#include "CommandSource.h"
#include "GameControl.h"
#include <string>

GameControl::GameControl(GameOfLife& game, CommandSource& command_source, std::string words):
        game(game),
        command_source(command_source),
        words(words)
{
}

void GameControl::play(CommandSource& command_source)
{

    for (int i = 1; i<(game.getGameWidth()*game.getGameHeight()); i++)
    {
        if (words[i] == '+')
        {
            div_t res_1 = div(i, game.getGameWidth());
            game.makeAlive(res_1.quot, (i%game.getGameWidth()));
        }
    }

    while(true)
    {
        std::string command = command_source.next_command();

        if (command == "quit") return;

        if (command == "next")
        {
            game.display();
            game.updateStateOfCells();
            game.holderToBoard();
        }
    }
}