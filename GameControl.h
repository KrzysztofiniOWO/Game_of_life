#pragma once
#include <string>
#include <vector>
#include "GameOfLife.h"
#include "CommandSource.h"
#include <cstdlib>
#include <iostream>


class GameControl{

    GameOfLife& game;
    CommandSource& command_source;
    std::string words;

public:
    GameControl(GameOfLife& game, CommandSource& command_source, std::string words);

    void play();
    //Play our game

};