#pragma once

#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    void showSplash();
    void sleep(int milliseconds);
    int showMenu();
    void drawBoard(const char grid[9]);
    void showWin(char mark);
    void showDraw();
    void clearScreen();
};

#endif

