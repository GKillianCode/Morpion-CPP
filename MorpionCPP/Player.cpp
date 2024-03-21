#include <iostream>
#include "player.hpp"

Player::Player(char symbol) : symbol(symbol)
{}

char Player::getSymbol() const
{
	return symbol;
}