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

std::vector<Player> players;
std::map<std::string, int> grid;

int main()
{
    players.push_back(Player{ 'O' });
    players.push_back(Player{ 'X' });

    grid = {
        {"A1", 2}, {"A2", 2}, {"A3", 2},
        {"B1", 2}, {"B2", 1}, {"B3", 2},
        {"C1", 2}, {"C2", 2}, {"C3", 2},
    };

    displayGame();
    return 0;
}

char getSymbol(int rawSymbol) {
    assert(rawSymbol < 3 && "Error with ID ");

    if (rawSymbol == 0 || rawSymbol == 1) {
        //return players[rawSymbol].getSymbol();
        return 'E';
    }
    else {
        return ' ';
    }
}

void displayGame() {
    std::cout << " --- --- --- \n";
    std::cout << "| " << getSymbol(grid["A1"]) << " | " << getSymbol(grid["A2"]) << " | " << getSymbol(grid["A3"]) << " | \n";
    std::cout << " --- --- --- \n";
    std::cout << "| " << getSymbol(grid["B1"]) << " | " << getSymbol(grid["B2"]) << " | " << getSymbol(grid["B3"]) << " | \n";
    std::cout << " --- --- --- \n";
    std::cout << "| " << getSymbol(grid["C1"]) << " | " << getSymbol(grid["C2"]) << " | " << getSymbol(grid["C3"]) << " | \n";
    std::cout << " --- --- --- " << std::endl;
}

