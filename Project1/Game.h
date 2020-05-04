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

	void createWindow(int, int);
	void displayScore();
	void displayLives();
	void gameover();
	bool increaseScore(Player pacman); // returns true if the ghosts have entered the fright mode
	void createrandom(int &num);

public:
	Game();
	~Game();
	void setWindow(RenderWindow&);
	void setScore(int);
	void setlives(int);
	void loop();
	void startGame(string name);	

	int getScore();
	int getlives();
	RenderWindow getWindow();

};

