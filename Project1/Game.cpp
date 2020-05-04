#include "Game.h"

void Game::displayScore() {
	RectangleShape score;
	Texture tscore;
	tscore.loadFromFile("score.png");
	score.setTexture(&tscore);
	score.setPosition(Vector2f(570, 830)); // to be displayed in the bottom of the game window
	window.draw(score);
	//line to printout teh real score
}


void Game::displayLives() {
	RectangleShape lives;
	Texture live;
	live.loadFromFile("lives.png");
	lives.setTexture(&live);
	lives.setPosition(Vector2f(570, 830)); // to be displayed in the bottom of the game window
	window.draw(lives);
	//line to printout the number of lives
}


void Game::gameover() {
	Sprite gameover;
	Texture tgameover;
	tgameover.loadFromFile("gameover.png");
	gameover.setTexture(tgameover);
	gameover.setPosition(Vector2f(420, 420));
	window.draw(gameover);
}

//void createrand(int& num) {
//
//	srand(time(0));
//	num = rand() % 4; // to move ghosts randomly 1 means up, 2 down, 3 right, 4 left. 
//}

//bool Game::increaseScore(Player pacman) {
//	int currentRow = ((pacman.getRow()) / 10);
//	int currentColumn = ((pacman.getColumn()) / 10);
//	if (arr[currentRow][currentColumn] == 5)
//		score += 10;
//	else if (arr[currentRow][currentColumn] == 6) {
//		score += 100;
//		return true;
//	}
//
//
//}


Game::Game() {

	score = 0; lives = 3;
	arr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++) {
		arr[i] = new int[COLUMNS];
	}
	board = new RectangleShape * [ROWS];
	for (int i = 0; i < ROWS; i++) {
		board[i] = new RectangleShape[COLUMNS];
	}
	circboard = new CircleShape * [ROWS];
	for (int i = 0; i < ROWS; i++) {
		circboard[i] = new CircleShape[COLUMNS];
	}
}

Game::~Game() {
	for (int i = 0; i < ROWS; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	for (int i = 0; i < ROWS; i++) {
		delete[] board[i];
	}
	delete[] board;

	for (int i = 0; i < ROWS; i++) {
		delete[] circboard[i];
	}
	delete[] circboard;


}

void Game::setWindow(RenderWindow& ewindow) {


}

void Game::setScore(int escore) {

	score = escore;

}

void Game::setlives(int elives) {
	lives = elives;

}

//void Game::loop(){
//	Event e;
//	
//	
//
//	while (window.isOpen())
//	{
//		
//		while (window.pollEvent(e))
//		{
//			if (e.type == Event::Closed)
//				window.close();
//			else if (e.type == Event::KeyPressed)
//			{
//				switch (e.key.code)
//				{
//				case Keyboard::Up:
//					player.move('U', arr);
//					if (increaseScore(player)) // check if the place he is going to contains bullets or not and accordingly increase the score or not.
//					{
//						Blinky.setMode('f');
//						Pinky.setMode('f');
//						Inky.setMode('f');
//						Clyde.setMode('f');
//					}
//					break;
//				
//				case Keyboard::Down:
//					player.move('D', arr);
//					if (increaseScore(player)) // check if the place he is going to contains bullets or not and accordingly increase the score or not.
//					{
//						Blinky.setMode('f');
//						Pinky.setMode('f');
//						Inky.setMode('f');
//						Clyde.setMode('f');
//					}
//					break;
//			
//				case Keyboard::Right:
//					player.move('R', arr);
//					if (increaseScore(player)) // check if the place he is going to contains bullets or not and accordingly increase the score or not.
//					{
//						Blinky.setMode('f');
//						Pinky.setMode('f');
//						Inky.setMode('f');
//						Clyde.setMode('f');
//					}
//					break;
//
//				case Keyboard::Left:
//					player.move('L', arr);
//					if (increaseScore(player)) // check if the place he is going to contains bullets or not and accordingly increase the score or not.
//					{
//						Blinky.setMode('f');
//						Pinky.setMode('f');
//						Inky.setMode('f');
//						Clyde.setMode('f');
//					}
//					break;
//				}
//			}
//		}
//		
//		if (player.getPlayerPosition() == Blinky.getPlayerPosition() || player.getPlayerPosition() == Pinky.getPlayerPosition()
//			|| player.getPlayerPosition() == Inky.getPlayerPosition()
//			|| player.getPlayerPosition() == Clyde.getPlayerPosition()) {
//			if (Blinky.getMode()=='n') {
//
//				if (lives != 0) {
//					lives--;
//					window.clear();
//					for (int i = 0; i < 82; i++)
//						for (int j = 0; j < 73; j++)
//							window.draw(board[i][j]);
//					player.drawPlayer(window);
//					Blinky.drawPlayer(window);
//						Pinky.drawPlayer(window);
//						Inky.drawPlayer(window);
//						Clyde.drawPlayer(window);
//					displayScore(); displayLives();
//					window.display();
//				}
//
//				else {
//					gameover();
//				}
//			
//			}
//			else {
//				score += 200;
//
//				if (player.getPlayerPosition() == Blinky.getPlayerPosition()) Blinky.setPosition(300,410);
//					if (player.getPlayerPosition() == Pinky.getPlayerPosition()) Pinky.setPosition(330,410);
//					if (player.getPlayerPosition() == Inky.getPlayerPosition()) Inky.setPosition(360,410);
//					if (player.getPlayerPosition() == Clyde.getPlayerPosition()) Clyde.setPosition(390,410);  // returns them to their initial position
//			
//					window.clear();
//					for (int i = 0; i < 82; i++)
//						for (int j = 0; j < 73; j++) {
//							window.draw(board[i][j]);
//							window.draw(circboard[i][j]);
//						}
//					player.drawPlayer(window);
//					Blinky.drawPlayer(window);
//					Pinky.drawPlayer(window);
//					Inky.drawPlayer(window);
//					Clyde.drawPlayer(window);
//					displayScore(); displayLives();
//					window.display();
//			}
//			}
//
//
//
//			
//		}
//		
//}



void Game::startGame(string name) {
	window.create(VideoMode(830, 870), "Pacman");

	Player player(350, 640, "pacman", "Pacman.png");
	player.setsize(50, 50);

	
	
	
	ifstream inputFile;
	inputFile.open("Game.txt");

	if (inputFile.is_open())
	{
		cout << "hello world\n";
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
				if (!inputFile.eof())
					inputFile >> arr[i][j];
	}

	inputFile.close();




	////Player player(1, 1, "CuteFace.png");
	Texture bricksTexture, grassTexture;
	bricksTexture.loadFromFile("Bricks.png");
	grassTexture.loadFromFile("Grass.png");

	
	
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j].setPosition(Vector2f (50 + 10 * j, 50 + 10 * i));
			board[i][j].setSize(Vector2f(10, 10));
			circboard[i][j].setRadius(10);
			circboard[i][j].setPosition(Vector2f(50 + 10 * j, 50 + 10 * i));

			if (arr[i][j] == 1)
			{
				board[i][j].setTexture(&bricksTexture);
				circboard[i][j].setFillColor(Color::Black);
			}
			else if (arr[i][j] == 3)
			{
				board[i][j].setTexture(&grassTexture);
				circboard[i][j].setFillColor(Color::Black);
			}
			else if (arr[i][j] == 2) {
				board[i][j].setFillColor(Color::Black);
				circboard[i][j].setFillColor(Color::Black);
			}

			else if (arr[i][j] == 5) {
				board[i][j].setFillColor(Color::Black);
				circboard[i][j].setRadius(2);
				
			}

			else if (arr[i][j] == 6) {
				board[i][j].setFillColor(Color::Black);
				circboard[i][j].setRadius(5);

			}

		}
	Event e;
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			/*else if (e.type == Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case Keyboard::Up:
				player.move('U', arr);
				break;
				case Keyboard::Down:
					player.move('D', arr);
					break;
				case Keyboard::Right:
					player.move('R', arr);
					break;
				case Keyboard::Left:
					player.move('L', arr);
					break;
				}
			}*/
		}
		window.clear();
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++) {
				window.draw(board[i][j]);
				window.draw(circboard[i][j]);
			}
		player.drawPlayer(window);
		window.display();
	}
	


}

//RenderWindow Game::getWindow() {
//	
//
//
//}

int Game::getScore() {
	return score;

	}

int Game::getlives() {
	return lives;
}