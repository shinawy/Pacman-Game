#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;
class Player
{
protected:
	Sprite shape;
	Texture playerTexture;
	string name;

	

public:
	
	Player();
	Player(int,int,string,string);
	void setPosition(int, int);
	void settexture(string imagename);
	void setsize(double,double);
	void move(char, int** arr);
	void rotatePlayer(char);
	void drawPlayer(RenderWindow& window);	
	void drawPlayer(RenderWindow& window, Transform& trans);
	int getRow();
	int getColumn();
	Sprite getshape();
	string getname();
	void print_bounds();
	
	Vector2f getPlayerPosition();
};




 