#include "Roller.h"

int Roller::aliveNeighbours(int row, int col)
{
    int counter = 0;

    for(int i = row-1; i<=row+1; i++)
    {
        for(int j = col-1; j<=col+1; j++)
        {

            if((i<0) || (i>=width) || (i==row && j==col))
            {
                continue;
            }
            if(board[i][(j+width) % width].isAlive == true)
            {
                counter++;
            }
        }
    }
    return counter;

}