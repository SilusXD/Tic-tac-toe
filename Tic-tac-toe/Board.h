#pragma once

#ifndef BOARD_H
#define BOARD_H

class Board 
{
private:
    char grid[9];

public:
    Board();

    void reset();
    void preview();
    bool placeMark(int pos, char mark);
    bool isFull();
    bool checkWin(char mark);

    const char* getGrid() const;
};

#endif


