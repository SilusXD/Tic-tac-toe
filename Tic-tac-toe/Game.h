#pragma once

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Renderer.h"

class Game 
{
private:
    Board board;
    Renderer renderer;
    char currentPlayer;

    void gameLoop();
    int getInput();
    void switchPlayer();

public:
    Game();
    void run();
};

#endif
