#include "Donut.h"

int Donut::aliveNeighbours(int row, int col)
{
    int counter = 0;

    for(int i = row-1; i<=row+1; i++)
    {
        for(int j = col-1; j<=col+1; j++)
        {
            if((i==row && j==col))
            {
                continue;
            }
            if(board[(i + height) % height][(j + width) % width].isAlive)
            {
                counter++;
            }
        }
    }
    return counter;

}