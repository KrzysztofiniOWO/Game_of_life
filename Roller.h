#pragma once
#include "GameOfLife.h"

class Roller : public GameOfLife {
public:
    using GameOfLife::GameOfLife;

    int aliveNeighbours(int row, int col) override;

};