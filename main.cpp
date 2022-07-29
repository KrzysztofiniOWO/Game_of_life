#include "AlwaysNextTurn.h"
#include "ManualTurns.h"
#include "GameOfLife.h"
#include "GameControl.h"
#include <fstream>
#include "Donut.h"
#include "Roller.h"
#include <memory>
#include <iostream>

std::unique_ptr<GameOfLife> select_shape(std::string shape, int width, int height)
{
    if (shape == "roller")
    {
        return std::make_unique<Roller>(width, height);

    }else if (shape == "donut")
    {
        return std::make_unique<Donut>(width, height);

    }else
    {
        return std::make_unique<GameOfLife>(width, height);
    }
}

std::unique_ptr<CommandSource> select_mode(std::string mode)
{
    if (mode == "auto")
    {
        return std::make_unique<AlwaysNextTurn>();

    }else
    {
        return std::make_unique<ManualTurns>();
    }
}

std::string player_select_mode ()
{
    std::string selected_mode;
    std::cout << "Select if you want to click button to continue or game will continue by itself [manual, auto]: " << std::endl;
    std::cin >> selected_mode;
    return selected_mode;

}

int main()
{

    std::fstream file;
    file.open("dane.txt", std::ios::in);

    std::string selected_shape;
    file >> selected_shape;

    int w;
    file >> w;

    int h;
    file >> h;

    std::string word;
    std::string words;

    for(int a = 0; a<h; a++)
    {
        file >> word;
        words = words + word;
    }

    std::unique_ptr<GameOfLife> shape = select_shape(selected_shape, w, h);
    std::unique_ptr<CommandSource> mode = select_mode(player_select_mode());

    GameControl ctrl(*shape, *mode, words);
    ctrl.play(*mode);

    return 0;
}