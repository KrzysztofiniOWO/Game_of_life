#pragma once
#include "GameOfLife.h"

class Donut: public GameOfLife{
public:

    using GameOfLife::GameOfLife;

    int aliveNeighbours(int row, int col) override;


};