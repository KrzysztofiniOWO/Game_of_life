#pragma once
#include "CommandSource.h"
#include <vector>

struct Field
{
    bool isAlive = false;
};

class GameOfLife {

private:
    Field field;

protected:
    std::vector<std::vector<Field> > board;
    std::vector<std::vector<Field> > board_holder;
    int width;
    int height;

public:
    GameOfLife(int width, int height);


    void display() const;
    //Shows our board

    void createBoard(Field field);
    //Function that creates board for our life game

    virtual int aliveNeighbours(int row, int col);
    //Checks how many neighbour cells are alive atm

    void updateStateOfCells();
    //Checks what happens to a cell on next state of game and updates it

    void holderToBoard();
    //Transports state of game from holder to board

    int getGameWidth();
    //Width

    int getGameHeight();
    //Height

    void makeAlive(int row, int col);
    //Make a cell alive


    //Functions that place fixed structures on board

    void placeBlock(int row, int col);
    //Places block on given position on board

    void placeTub(int row, int col);
    //Places tub on given position on board

    void placeBlinker(int row, int col);
    //Places blinker on given position on board

    void placeBeacon(int row, int col);
    //Places beacon on given position on board

    void placeGlider(int row, int col);
    //Places glider on given position on board


};