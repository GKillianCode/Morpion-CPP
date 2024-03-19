
#ifndef __PLAYER__
#define __PLAYER__

class Player
{
public:
	Player() = delete;
	Player(char symbol);
	char getSymbol() const;
private:
	char symbol;
};

#endif