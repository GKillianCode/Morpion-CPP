/*
  --- --- ---
 |   |   |   |
  --- --- ---
 |   |   |   |
  --- --- ---
 |   |   |   |
  --- --- ---
*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include "player.hpp"

void displayGame();
char getSymbol(int rawSymbol);
void reset();
void getUserInput();
bool checkResult(int currentPlayer);
bool isFullGrid();
void displayPlayerWin(int playerId);
void displayGameLoose();

std::vector<Player> players;
std::map<std::string, int> grid;
int currentPlayer{ 0 };

int main()
{    
    reset();
    getUserInput();

    return 0;
}

bool checkResult(int currentPlayer)
{
    bool isVictory{ false };

    if (grid["A1"] == currentPlayer && grid["A2"] == currentPlayer && grid["A3"] == currentPlayer)
    {
        isVictory = true;
    }
    else if (grid["B1"] == currentPlayer && grid["B2"] == currentPlayer && grid["B3"] == currentPlayer)
    {
        isVictory = true;
    }
    else if (grid["C1"] == currentPlayer && grid["C2"] == currentPlayer && grid["C3"] == currentPlayer)
    {
        isVictory = true;
    }


    else if (grid["A1"] == currentPlayer && grid["B1"] == currentPlayer && grid["C1"] == currentPlayer)
    {
        isVictory = true;
    }

    else if (grid["A2"] == currentPlayer && grid["B2"] == currentPlayer && grid["C2"] == currentPlayer)
    {
        isVictory = true;
    }

    else if (grid["A3"] == currentPlayer && grid["B3"] == currentPlayer && grid["C3"] == currentPlayer)
    {
        isVictory = true;
    }


    else if (grid["A1"] == currentPlayer && grid["B2"] == currentPlayer && grid["C3"] == currentPlayer)
    {
        isVictory = true;
    }

    else if (grid["A3"] == currentPlayer && grid["B2"] == currentPlayer && grid["C1"] == currentPlayer)
    {
        isVictory = true;
    }

    return isVictory;
}

bool isFullGrid()
{
    if (grid["A1"] != 2 && grid["A2"] != 2 && grid["A3"] != 2 &&
        grid["B1"] != 2 && grid["B2"] != 2 && grid["B3"] != 2 &&
        grid["C1"] != 2 && grid["C2"] != 2 && grid["C3"] != 2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void getUserInput() 
{
    bool gameStart{ true };

    while (gameStart)
    {
        displayGame();
        std::cout << "\nJoueur " << currentPlayer + 1 << " [" << getSymbol(currentPlayer) << "] - Donner votre position : ";
        std::string rawPos;
        std::cin >> rawPos;

        for (char& c : rawPos)
        {
            c = std::toupper(c);
        }

        if ((rawPos == "A1" || rawPos == "A2" || rawPos == "A3" ||
            rawPos == "B1" || rawPos == "B2" || rawPos == "B3" ||
            rawPos == "C1" || rawPos == "C2" || rawPos == "C3") && grid[rawPos] == 2)
        {
            grid[rawPos] = currentPlayer;
            bool isUserVictory = checkResult(currentPlayer);

            if (isUserVictory) 
            {
                displayGame();
                displayPlayerWin(currentPlayer);

                gameStart = false;
            }
            else 
            {
                bool gridIsFull = isFullGrid();

                if (gridIsFull)
                {
                    displayGame();
                    displayGameLoose();

                    gameStart = false;
                }
                else
                {
                    currentPlayer = currentPlayer == 1 ? 0 : 1;
                }
            }

        }
        else {
            std::cout << "Position incorrect !";
        }
    }
}

void displayGameLoose()
{
    std::cout << "\n\n================================================================== \n";
    std::cout << "  .d88b     db    8b   d8 8888    8    .d88b. .d88b. .d88b. 8888 \n";
    std::cout << "  8P www   dPYb   8YbmdP8 8www    8    8P  Y8 8P  Y8 YPwww. 8www \n";
    std::cout << "  8b  d8  dPwwYb  8  \"  8 8       8    8b  d8 8b  d8     d8 8    \n";
    std::cout << "  `Y88P' dP    Yb 8     8 8888    8888 `Y88P' `Y88P' `Y88P' 8888 \n";
    std::cout << "================================================================== " << std::endl;
}

void displayPlayerWin(int playerId)
{
    if (playerId == 0) 
    {
        std::cout << "\n\n========================================================================= \n";
        std::cout << "  888b. 8       db    Yb  dP 8888 888b.    d8    Yb        dP 888 8b  8 \n";
        std::cout << "  8  .8 8      dPYb    YbdP  8www 8  .8     8     Yb  db  dP   8  8Ybm8 \n";
        std::cout << "  8wwP' 8     dPwwYb    YP   8    8wwK'     8      YbdPYbdP    8  8  \"8 \n"; 
        std::cout << "  8     8888 dP    Yb   88   8888 8  Yb     8       YP  YP    888 8   8 \n";
        std::cout << "========================================================================= " << std::endl;
    }
    else
    {
        std::cout << "\n\n============================================================================ \n";
        std::cout << "  888b. 8       db    Yb  dP 8888 888b.    d88b    Yb        dP 888 8b  8 \n";
        std::cout << "  8  .8 8      dPYb    YbdP  8www 8  .8    \" dP     Yb  db  dP   8  8Ybm8 \n"; 
        std::cout << "  8wwP' 8     dPwwYb    YP   8    8wwK'     dP       YbdPYbdP    8  8  \"8 \n"; 
        std::cout << "  8     8888 dP    Yb   88   8888 8  Yb    d888       YP  YP    888 8   8 \n";
        std::cout << "============================================================================" << std::endl;
    }
}

void reset() 
{
    players = {};
    players.push_back(Player{ 'O' });
    players.push_back(Player{ 'X' });

    grid = {
        {"A1", 2}, {"B1", 2}, {"C1", 2},
        {"A2", 2}, {"B2", 2}, {"C2", 2},
        {"A3", 2}, {"B3", 2}, {"C3", 2},
    };
}

char getSymbol(int rawSymbol) 
{
    assert(rawSymbol < 3 && "Error with ID ");

    if (rawSymbol == 0 || rawSymbol == 1) {
        return players[rawSymbol].getSymbol();
    }
    else {
        return ' ';
    }
}

void displayGame() 
{
    std::cout << "\n\n     A   B   C \n";
    std::cout << "    --- --- --- \n";
    std::cout << " 1 | " << getSymbol(grid["A1"]) << " | " << getSymbol(grid["B1"]) << " | " << getSymbol(grid["C1"]) << " | \n";
    std::cout << "    --- --- --- \n";
    std::cout << " 2 | " << getSymbol(grid["A2"]) << " | " << getSymbol(grid["B2"]) << " | " << getSymbol(grid["C2"]) << " | \n";
    std::cout << "    --- --- --- \n";
    std::cout << " 3 | " << getSymbol(grid["A3"]) << " | " << getSymbol(grid["B3"]) << " | " << getSymbol(grid["C3"]) << " | \n";
    std::cout << "    --- --- --- " << std::endl;
}

