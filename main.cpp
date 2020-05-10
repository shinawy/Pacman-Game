#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Help.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace sf;


int main()
{
	
	
	
	/*sf::err().rdbuf(NULL);
	Player mine;
	mine.print_bounds();
	*/
	
	/*int** arr; int** gamearr;
	fillgraph mine;
	mine.FillGraphfile(arr, gamearr); /// to build a graph text file*/
	
	cout << "Hello 1\n";
	sf::err().rdbuf(NULL);
	Game Pacman;
	Pacman.startGame("Pacman");	






	

	
	return 0;

}

