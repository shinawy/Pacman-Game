#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Game.h""
using namespace std;
using namespace sf;
const int ROWS = 82, COLUMNS = 73;



int main()
{
	cout << "Hello 1\n";
	sf::err().rdbuf(NULL);
	Game Pacman;
	Pacman.startGame("Pacman");
	
	
	

	//RenderWindow window;
	//window.create(VideoMode(830, 870), "Pacman");

	//




	//int arr[ROWS][COLUMNS];
	//int** arr = new int* [ROWS];
	//for (int i = 0; i < ROWS; i++) {
	//	arr [i] = new int [COLUMNS];
	//}

	//ifstream inputFile;
	//inputFile.open ("Game.txt");

	//if (inputFile.is_open())
	//{
	//	cout << "hello world\n";
	//	for (int i = 0; i < ROWS; i++)
	//		for (int j = 0; j < COLUMNS; j++)
	//			if (!inputFile.eof())
	//				inputFile >> arr[i][j];
	//}

	//inputFile.close();

	//


	////Player player(1, 1, "CuteFace.png");
	//Texture bricksTexture, grassTexture;
	//bricksTexture.loadFromFile("Bricks.png");
	//grassTexture.loadFromFile("Grass.png");

	//RectangleShape board[ROWS][COLUMNS];
	//RectangleShape** board = new RectangleShape* [ROWS];
	//for (int i = 0; i < ROWS; i++) {
	//	board[i] = new RectangleShape[COLUMNS];
	//}

	//for (int i = 0; i < ROWS; i++)
	//	for (int j = 0; j < COLUMNS; j++)
	//	{
	//		board[i][j].setPosition(50 + 10 * j, 50 + 10 * i);
	//		board[i][j].setSize(Vector2f(10, 10));
	//		if (arr[i][j] == 1)
	//		{
	//			board[i][j].setTexture(&bricksTexture);
	//			board[i][j].setFillColor(Color::Yellow);
	//		}
	//		else if (arr[i][j] == 3)
	//		{
	//			board[i][j].setTexture(&grassTexture);
	//			board[i][j].setFillColor(Color::Green);
	//		}
	//		else if (arr[i][j] == 2)
	//			board[i][j].setFillColor(Color::Black);


	//	}
	//Event e;
	//while (window.isOpen())
	//{
	//	while (window.pollEvent(e))
	//	{
	//		if (e.type == Event::Closed)
	//			window.close();
	//		/*else if (e.type == Event::KeyPressed)
	//		{
	//			switch (e.key.code)
	//			{
	//			case Keyboard::Up:
	//			player.move('U', arr);
	//			break;
	//			case Keyboard::Down:
	//				player.move('D', arr);
	//				break;
	//			case Keyboard::Right:
	//				player.move('R', arr);
	//				break;
	//			case Keyboard::Left:
	//				player.move('L', arr);
	//				break;
	//			}
	//		}*/
	//	}
	//	window.clear();
	//	for (int i = 0; i < ROWS; i++)
	//		for (int j = 0; j < COLUMNS; j++)
	//			window.draw(board[i][j]);
	//	player.drawOnWindow(window);
	//	window.display();
	//}

	//for (int i = 0; i < ROWS; i++) {
	//	delete [] arr[i];
	//}
	//delete [] arr;

	//for (int i = 0; i < ROWS; i++) {
	//	delete[] board[i];
	//}
	//delete[] board;
	
	return 0;

}

