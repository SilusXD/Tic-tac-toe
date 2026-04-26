#include "Game.h"
#include <iostream>
#include <limits>

Game::Game() : currentPlayer('X') {}

void Game::run() 
{
    renderer.showSplash();

    while (true) 
    {
        int choice = renderer.showMenu();

        if (choice == 2) 
        {
            renderer.clearScreen();
            std::cout << "Goodbye!\n";
            break;
        }

        board.preview(); 
        renderer.drawBoard(board.getGrid());
        renderer.sleep(1500);

        board.reset();
        currentPlayer = 'X';
        gameLoop();
    }
}

void Game::gameLoop() 
{
    while (true) 
    {
        renderer.drawBoard(board.getGrid());

        int pos = getInput();
        if (pos == -1)
        {
            renderer.sleep(1500);
            continue;
        }

        board.placeMark(pos, currentPlayer);

        if (board.checkWin(currentPlayer)) 
        {
            renderer.drawBoard(board.getGrid());
            renderer.showWin(currentPlayer);
            break;
        }

        if (board.isFull()) 
        {
            renderer.drawBoard(board.getGrid());
            renderer.showDraw();
            break;
        }

        switchPlayer();
    }
}

int Game::getInput()
{
    int pos;

    std::cout << "\nPlayer " << currentPlayer
        << ", enter position (1-9): ";
    std::cin >> pos;

    if (std::cin.fail() || pos < 1 || pos > 9)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Try again.\n";
        return -1;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!board.placeMark(pos - 1, currentPlayer))
    {
        std::cout << "Position already taken! Try again.\n";
        return -1;
    }

    return pos - 1;
}

void Game::switchPlayer() 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}