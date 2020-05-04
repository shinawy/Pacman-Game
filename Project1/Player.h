#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;
class Player
{
private:
	Sprite shape;
	Texture playerTexture;
	string name;
	

public:
	
	Player();
	Player(int,int,string,string);
	void setPosition(int, int);
	void setsize(int, int);
	void move(char, int** arr);
	void drawPlayer(RenderWindow& window);	
	int getRow();
	int getColumn();
	Vector2f getPlayerPosition();
};

