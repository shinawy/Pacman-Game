#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include<ctime>
#include <cstdlib>
#include "Ghost.h"
using namespace sf;
using namespace std;

class Game
{
private:
	RenderWindow window;
	int score;
	int lives;
	int** arr;
	RectangleShape** board;
	CircleShape** circboard;
	const int ROWS = 82, COLUMNS =73 ;
	const int MaxScore = 7160; // 318 bullets (20 points each); 4 bullets for fright mode (200 points each); 
	Clock Gclock;
	Time Gtime;

	void createWindow(int, int);
	void displayScore();
	void displayLives();
	void gameover();
	void YouWonthegame();
	bool increaseScore(Player pacman, Ghost Blinky, Ghost Pinky, Ghost Inky, Ghost Clyde, int ); // returns true if the ghosts have entered the fright mode
	char createrandom();
	void moveRandomly(Ghost& Blinky, Ghost& Pinky, Ghost& Inky, Ghost& Clyde);
	//void checkforfrightMode(Player, Ghost,Ghost,Ghost,Ghost);
	void setInitialPositions(Player& player, Ghost& Blinky, Ghost& Pinky, Ghost& Inky, Ghost& Clyde);
	void setInitialPositions(Ghost&);
	void FrightMode(Ghost);


public:
	Game();
	~Game();
	void setWindow(RenderWindow&);
	void setScore(int);
	void setlives(int);
	void loop(Player, Ghost,Ghost,Ghost,Ghost);
	void startGame(string name);	

	int getScore();
	int getlives();
	RenderWindow getWindow();

};

