#include "Board.h"

Board::Board() 
{
    reset();
}

void Board::reset() 
{
    for (int i = 0; i < 9; ++i) 
    {
        grid[i] = ' ';
    }
}

void Board::preview()
{
    for (int i = 0; i < 9; i++)
    {
        grid[i] = '1' + i;
    }
}

bool Board::placeMark(int pos, char mark) 
{
    if (pos < 0 || pos > 8) 
    {
        return false;
    }

    if (grid[pos] == 'X' || grid[pos] == 'O') 
    {
        return false;
    }

    grid[pos] = mark;
    return true;
}

bool Board::isFull() 
{
    for (int i = 0; i < 9; ++i) 
    {
        if (grid[i] != 'X' && grid[i] != 'O') 
        {
            return false;
        }
    }
    return true;
}

bool Board::checkWin(char mark) 
{
    const int winCombos[8][3] = 
    {
        {0,1,2}, {3,4,5}, {6,7,8}, // строки
        {0,3,6}, {1,4,7}, {2,5,8}, // столбцы
        {0,4,8}, {2,4,6}           // диагонали
    };

    for (int i = 0; i < 8; ++i) 
    {
        if (grid[winCombos[i][0]] == mark &&
            grid[winCombos[i][1]] == mark &&
            grid[winCombos[i][2]] == mark) 
        {
            return true;
        }
    }
    return false;
}

const char* Board::getGrid() const 
{
    return grid;
}