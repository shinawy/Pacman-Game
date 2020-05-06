#pragma once
#include "Player.h"

class Ghost: public Player
{
private:
	char mode;
public:
	Ghost();
	Ghost(int, int, string, string);
	void setMode(char);
	void FrightMode();
	char getMode();

};

