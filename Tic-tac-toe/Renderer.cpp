#include "Renderer.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

void Renderer::clearScreen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Renderer::sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Renderer::showSplash() 
{
    clearScreen();
    std::cout << "=========================\n";
    std::cout << "     TIC-TAC-TOE\n";
    std::cout << "      by Silus\n";
    std::cout << "=========================\n\n";
    sleep(2500);
}

int Renderer::showMenu() 
{
    int choice;
    while (true) 
    {
        clearScreen();
        std::cout << "=== MENU ===\n";
        std::cout << "1. Play\n";
        std::cout << "2. Exit\n";
        std::cout << "  Choose: ";
        std::cin >> choice;
        
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if (choice == 1 || choice == 2) 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

void Renderer::drawBoard(const char grid[9]) 
{
    clearScreen();
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) 
    {
        std::cout << " " << grid[i] << " | " << grid[i+1] << " | " << grid[i+2] << "\n";
        if (i < 6) 
        {
            std::cout << "-----------\n";
        }
    }
}

void Renderer::showWin(char mark) 
{
    std::cout << "\n>>> Player " << mark << " wins! <<<\n";
    std::cout << "Press Enter to continue...";
    std::cin.get();
}

void Renderer::showDraw() 
{
    std::cout << "\n>>> It's a draw! <<<\n";
    std::cout << "Press Enter to continue...";
    std::cin.get();
}
