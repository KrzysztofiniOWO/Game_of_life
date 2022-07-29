#include "GameOfLife.h"
#include "CommandSource.h"
#include <iostream>

GameOfLife::GameOfLife(int width, int height): width(width), height(height)
{
    Field field;
    createBoard(field);
};


void GameOfLife::createBoard(Field field)
{
    for(int i = 0; i<width; i++)
    {
        std::vector<Field> wektor;

        for (int j = 0; j<height; j++)
        {
            wektor.push_back(field);
        }

        board.push_back(wektor);
    }

    for(int i = 0; i<width; i++)
    {
        std::vector<Field> wektor;

        for (int j = 0; j<height; j++)
        {
            wektor.push_back(field);
        }

        board_holder.push_back(wektor);
    }
}

void GameOfLife::display() const
{
    for(size_t i = 0; i<board.size(); i++)
    {
        std::cout << std::endl;
        for(size_t j = 0; j<board[i].size(); j++)
        {
            std::cout << "[";
            if (!board[i][j].isAlive)
            {
                std::cout << " ";
            }else
            {
                std::cout << "O";
            }
            std::cout << "]";
        }
    }
    std::cout << std::endl;

}

void GameOfLife::makeAlive(int row, int col)
{
    board[row][col].isAlive = true;
}

int GameOfLife::getGameWidth()
{
    return width;
}

int GameOfLife::getGameHeight()
{
    return height;
}

int GameOfLife::aliveNeighbours(int row, int col)
{
    int counter = 0;
    for(int i = row-1; i<=row+1; i++)
    {
        for(int j = col-1; j<=col+1; j++)
        {
            if((i<0 || j<0) || (i>=width || j>=height) || (i==row && j==col))
            {
                continue;
            }
            if(board[i][j].isAlive)
            {
                counter++;
            }
        }
    }
    return counter;
}

void GameOfLife::updateStateOfCells()
{
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            if(board[i][j].isAlive && (aliveNeighbours(i, j) == 2 || aliveNeighbours(i, j) == 3))
            {
                board_holder[i][j].isAlive = true;
            }else if(!board[i][j].isAlive && (aliveNeighbours(i, j) == 3))
            {
                board_holder[i][j].isAlive = true;
            }else
            {
                board_holder[i][j].isAlive = false;
            }
        }
    }
}

void GameOfLife::holderToBoard()
{
    for(int i = 0; i<width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            board[i][j].isAlive = board_holder[i][j].isAlive;
        }
    }
}

void GameOfLife::placeBlock(int row, int col)
{
    if((row-1>0 && col-1>0) && ((row<width) && (col<height)))
    {
        board[row-1][col-1].isAlive = true;
        board[row][col-1].isAlive = true;
        board[row-1][col].isAlive = true;
        board[row][col].isAlive = true;
    }
}

void GameOfLife::placeTub(int row, int col)
{
    if((row-1>0 && col-1>0) && ((row+1<width) && (col+1<height)))
    {
        board[row+1][col].isAlive = true;
        board[row-1][col].isAlive = true;
        board[row][col+1].isAlive = true;
        board[row][col-1].isAlive = true;
    }
}

void GameOfLife::placeBlinker(int row, int col)
{
    if(row-1>0 && row+1<width)
    {
        board[row+1][col].isAlive = true;
        board[row][col].isAlive = true;
        board[row-1][col].isAlive = true;
    }
}

void GameOfLife::placeBeacon(int row, int col)
{
    if((row-2>0 && col-2>0) && ((row+1<width) && (col+1<height)))
    {
        board[row+1][col+1].isAlive = true;
        board[row+1][col].isAlive = true;
        board[row][col+1].isAlive = true;
        board[row-2][col-1].isAlive = true;
        board[row-2][col-2].isAlive = true;
        board[row-1][col-2].isAlive = true;
    }
}

void GameOfLife::placeGlider(int row, int col)
{
    if((row-1>0 && col-1>0) && ((row+1<width) && (col+1<height)))
    {
        board[row-1][col].isAlive = true;
        board[row-1][col-1].isAlive = true;
        board[row-1][col+1].isAlive = true;
        board[row][col-1].isAlive = true;
        board[row+1][col].isAlive = true;
    }
}