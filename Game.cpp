#include "Game.h"

void Game::displayScore() {
	RectangleShape scoreshape;
	Texture tscore;
	tscore.loadFromFile("Score.png");
	scoreshape.setSize(Vector2f(200, 47));
	scoreshape.setTexture(&tscore);
	scoreshape.setPosition(Vector2f(50,0)); // to be displayed in the bottom of the game window
	
	Font scorefont;
	if (!scorefont.loadFromFile("Font.ttf"))
		cout << "Error loading\n";
	Text scoretext;
	scoretext.setFont(scorefont);
	scoretext.setString(to_string(score));
	scoretext.setLetterSpacing(5);
	scoretext.setFillColor(Color::Yellow);
	scoretext.setOrigin(Vector2f(-260,0));
	scoretext.setCharacterSize(40);

	window.draw(scoretext);
	window.draw(scoreshape);
	
}

void Game::setBoard() {
	 
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





	Texture bricksTexture, grassTexture;
	bricksTexture.loadFromFile("Bricks.png");
	grassTexture.loadFromFile("Grass.png");



	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j].setPosition(Vector2f(50 + 10 * j, 50 + 10 * i));
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
			else if (arr[i][j] == 2 || arr[i][j] == 7 || arr[i][j] == 8) {
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



}

void Game::displayLives() {
	RectangleShape livesshape;
	Texture live;
	live.loadFromFile("Lives.png");
	livesshape.setSize(Vector2f(50, 47));
	livesshape.setTexture(&live);
	livesshape.setPosition(Vector2f(450, 0));// to be displayed in the bottom of the game window
	
	Font livesfont;
	if (!livesfont.loadFromFile("Font.ttf"))
		cout << "Error loading\n";
	Text livestext;
	livestext.setFont(livesfont);
	livestext.setString(to_string(lives));
	livestext.setLetterSpacing(5);
	livestext.setFillColor(Color::Cyan);
	livestext.setOrigin(Vector2f(-550, 0));
	livestext.setCharacterSize(40);

	window.draw(livestext);
	window.draw(livesshape);


	
	
	window.draw(livesshape);
	//line to printout the number of lives
}


void Game::gameover() {
	RectangleShape Gameover;
	Texture gameovertexture;
	gameovertexture.loadFromFile("Gameover.jpg");
	Gameover.setTexture(&gameovertexture);
	Gameover.setSize(Vector2f(830, 870));
	Gameover.setPosition(Vector2f(0,0));
	window.clear();
	window.draw(Gameover);
	window.display();
	system("pause");
	
}

void Game::YouWonthegame() {
	RectangleShape Win;
	Texture wintexture;
	wintexture.loadFromFile("Win.png");
	Win.setTexture(&wintexture);
	Win.setSize(Vector2f(830, 870));
	Win.setPosition(Vector2f(0, 0));
	window.clear();
	window.draw(Win);
	window.display();
	system("pause");

}

void Game:: FrightMode(Ghost g) {
	g.setMode('F');
	new (&g) Ghost(g.getRow(),g.getColumn(),g.getname(),"Fright.png");
}


void setInitialPositions(Player& player, Ghost& Blinky , Ghost& Pinky, Ghost& Inky, Ghost& Clyde) {
 
	
player.setPosition(390, 645);
 Pinky.setPosition(395, 420);
 Inky.setPosition(350, 420);
 Clyde.setPosition(440, 420);
 Blinky.setPosition(390, 350);
 }

void setInitialPositions(Ghost& ghost) {
	if (ghost.getname()=="Blinky")
	ghost.setPosition(390, 350);
	else if (ghost.getname() == "Pinky")
		ghost.setPosition(395, 420);
	else if (ghost.getname() == "Inky")
		ghost.setPosition(350, 420);
	else if (ghost.getname() == "Clyde")
		ghost.setPosition(440, 420);
}

char Game:: createrandom() {
	int num;
	srand(time(0));
	num = rand() % 4; // to move ghosts randomly 1 means up, 2 down, 3 right, 4 left. 

	if (num == 1)
		return 'U';
	else if (num == 2)
		return 'D';
	else if (num == 3)
		return 'R';
	else if (num == 4)
		return 'L';
	
}


void Game::moveRandomly(Ghost &Blinky, Ghost& Pinky, Ghost& Inky, Ghost& Clyde) {
	Blinky.move(createrandom(),arr);
	Pinky.move(createrandom(), arr);
	Inky.move(createrandom(), arr);
	Clyde.move(createrandom(), arr);
}

bool Game::increaseScore(Player pacman, Ghost Blinky, Ghost Pinky, Ghost Inky, Ghost Clyde, int a) {

	score += a;
	if (a == 200) {
		/*FrightMode(Blinky);
		FrightMode(Pinky);
		FrightMode(Inky);
		FrightMode(Clyde);*/

		return true;
	}

	else
		return false;
	
	


}


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

//void Game::loop(Player player,Ghost Blinky,Ghost Pinky, Ghost Inky, Ghost Clyde){
//	
//	Event e;
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
//					checkforfrightMode(player, Blinky, Pinky, Inky, Clyde);
//					break;
//				
//				case Keyboard::Down:
//					player.move('D', arr);
//					checkforfrightMode(player,Blinky,Pinky,Inky,Clyde);
//					break;
//			
//				case Keyboard::Right:
//					player.move('R', arr);
//					checkforfrightMode(player, Blinky, Pinky, Inky, Clyde);
//					break;
//
//				case Keyboard::Left:
//					player.move('L', arr);
//					checkforfrightMode(player, Blinky, Pinky, Inky, Clyde);
//					break;
//				}
//			}
//		}
//		// Here comes Handling Collision-->
//		if ((player.getshape()).getGlobalBounds().intersects(Blinky.getshape().getGlobalBounds()) || 
//			(player.getshape()).getGlobalBounds().intersects(Pinky.getshape().getGlobalBounds()) ||
//			(player.getshape()).getGlobalBounds().intersects(Inky.getshape().getGlobalBounds()) ||
//			(player.getshape()).getGlobalBounds().intersects(Clyde.getshape().getGlobalBounds())){
//			 
//		
//			if (Blinky.getMode()=='n') {
//
//				if (lives != 0) {
//					lives--;
//					setInitialPositions(player, Blinky, Pinky, Inky, Clyde);
//				}
//
//				else {
//					gameover();
//					system("pause");
//				}
//			
//			}
//			else {
//				score += 200;
//
//				if ((player.getshape()).getGlobalBounds().intersects(Blinky.getshape().getGlobalBounds()))  setInitialPositions(Blinky); 
//
//				else if ((player.getshape()).getGlobalBounds().intersects(Pinky.getshape().getGlobalBounds())) setInitialPositions(Pinky);
//				else if ((player.getshape()).getGlobalBounds().intersects(Inky.getshape().getGlobalBounds()))  setInitialPositions(Inky);
//				else if ((player.getshape()).getGlobalBounds().intersects(Clyde.getshape().getGlobalBounds())) setInitialPositions(Clyde); 
//				// returns them to their initial position
//
//			}
//		}
//
//		else {
//		
//			if (score == MaxScore)
//				YouWonthegame();
//				
//		}			
//	}
//		
//}

Vector2f Game::sendpos(Vector2f pacposition) {
	int firstnode = 0, secondnode = 0;
	bool loopentry = true;
		

	int r  = ((pacposition.y) - 50) / 10;  //390  640 3  2
	int c = ((pacposition.x) - 50) / 10;

	cout << r << " " << c << endl;

	int j = c; int i = r;
				while (c > 0 && c > j - 4) {
					if (arr[r][c] > 9) {
						cout << "hello from inside1\n";
						firstnode = r; secondnode = c;
						loopentry = false;
						break;
					}
					c--;
				}

				cout << "R: " << firstnode << " " << "C: " << secondnode << " \n";

				if (loopentry) {
					r = i; c = j;
					
					while (c < COLUMNS && c < j + 4) {
						if (arr[r][c] > 9) {
							cout << "hello from inside2\n";
							firstnode = r; secondnode = c;
							loopentry = false;
							break;
						}
						c++;
					}
				}

				cout << "R: " << firstnode << " " << "C: " << secondnode << " \n";

				if (loopentry) {
					cout << "hello world mine\n";
					r = i; c = j;
					while (r > 0 && r > i - 4) {
						if (arr[r][c] > 9) {
							cout << "hello from inside3\n";
							firstnode = r; secondnode = c;
							loopentry = false;
							break;
						}
						r--;
					}
				}

				cout << "R: " << firstnode << " " << "C: " << secondnode << " \n";
				
				if (loopentry) {
					
					r = i; c = j;
					while (r < ROWS && r < i + 4) {
						if (arr[r][c] > 9) {
							cout << "hello from inside4\n";
							firstnode = r; secondnode = c;
							loopentry = false;
							break;
						}
						r++;
					}
				}

				cout << "R: " << firstnode << " " << "C: " <<secondnode<< " \n";


				Vector2f positionreturned = Vector2f((50+10*secondnode),(50+10*firstnode));


				return positionreturned;


}

void Game::startGame(string name) {
	window.create(VideoMode(830, 870), "Pacman");

	Player player(390, 640, "pacman", "Pacman.png");
	
	//player.setsize(0.25, 0.25);
	Ghost Pinky(395, 420, "Pinky", "Pinky.png");
	Ghost Inky(350, 420, "Inky", "Inky.png");
	Ghost Clyde(420, 420, "Clyde", "Clyde.png");
	Ghost Blinky(390, 350, "Blinky", "Blinky.png");
	
	// player.print_bounds() ;
	 
	

	
	
	

	ifstream inputFile;
	inputFile.open("UpdatedGame2.txt");


	while (!inputFile.eof()) {

		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
					inputFile >> arr[i][j];

	}

	inputFile.close();

	/*Vector2f mypos = sendpos(Vector2f(70, 80));
	cout << player.getColumn() << endl;
	cout << mypos.x << " " << mypos.y << endl;*/



	Texture bricksTexture, grassTexture;
	bricksTexture.loadFromFile("Bricks.png");
	grassTexture.loadFromFile("Grass.png");



	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
		{
			board[i][j].setPosition(Vector2f(50 + 10 * j, 50 + 10 * i));
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

			else if (arr[i][j] == 2 || arr[i][j]==7 || arr[i][j]==8||arr[i][j]>9) {
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
	
	int count = 0;

	Event e; char dir ='R';
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			else if (e.type == Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case Keyboard::Up:
					/*if (dir == 'D')
						Pacrotation.rotate(-180,Vector2f(player.getRow()+25,player.getColumn()+25));
					else if (dir=='R')
						Pacrotation.rotate(-90, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'L')
						Pacrotation.rotate(90, Vector2f(player.getRow() + 25, player.getColumn() + 25));*/
					dir = 'U';
					break;

				case Keyboard::Down:
					/*if (dir == 'U')
						Pacrotation.rotate(180, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'R')
						Pacrotation.rotate(90, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'L')
						Pacrotation.rotate(-90, Vector2f(player.getRow() + 25, player.getColumn() + 25));*/
					dir = 'D';
					break;

				case Keyboard::Right:
					/*if (dir == 'U')
						Pacrotation.rotate(90, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'D')
						Pacrotation.rotate(-90, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'L')
						Pacrotation.rotate(180, Vector2f(player.getRow() + 25, player.getColumn() + 25));*/
					dir = 'R';							
					break;

				case Keyboard::Left:
					/*if (dir == 'U')
						Pacrotation.rotate(-90, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'D')
						Pacrotation.rotate(90, Vector2f(player.getRow() + 25, player.getColumn() + 25));
					else if (dir == 'R')
						Pacrotation.rotate(-180, Vector2f(player.getRow() + 25, player.getColumn() + 25));*/
					dir = 'L';					
					break;
				}
			}

		}

		 
		player.move(dir, arr);
		
		player.move(dir, arr);
		player.move(dir, arr);
	
			Blinky.moveGhost(sendpos(player.getPlayerPosition()));
			Pinky.moveGhost(sendpos(player.getPlayerPosition()));
			Inky.moveGhost(sendpos(player.getPlayerPosition()));

			Clyde.moveGhost(sendpos(player.getPlayerPosition()));
		
		/*else {
			Blinky.moveGhost(sendpos(Vector2f(390,350)));
			Pinky.moveGhost(sendpos(Vector2f(395,420)));
			Inky.moveGhost(sendpos(Vector2f(350,320)));

			Clyde.moveGhost(sendpos(Vector2f(420,420)));
	

		}*/

		//Blinky.test();

		window.setFramerateLimit(1000);
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
				if ((player.getshape()).getGlobalBounds().intersects(circboard[i][j].getGlobalBounds()))
					
					if (circboard[i][j].getFillColor() == Color::White) {
						
						if (circboard[i][j].getRadius() == 2) {
							increaseScore(player, Blinky, Pinky, Inky, Clyde, 20);
							circboard[i][j].setFillColor(Color::Black);
						}
						
						else if (circboard[i][j].getRadius() == 5) {
							increaseScore(player, Blinky, Pinky, Inky, Clyde, 200);
							new (&Blinky) Ghost(Blinky.getRow(), Blinky.getColumn(), Blinky.getname(), "Fright.png");
							new (&Pinky) Ghost(Pinky.getRow(), Pinky.getColumn(), Pinky.getname(), "Fright.png");
							new (&Inky) Ghost(Inky.getRow(), Inky.getColumn(), Inky.getname(), "Fright.png");
							new (&Clyde) Ghost(Clyde.getRow(), Clyde.getColumn(), Clyde.getname(), "Fright.png");
							Blinky.setMode('F');
							Pinky.setMode('F');
							Inky.setMode('F');
							Clyde.setMode('F');
							Gclock.restart();
							circboard[i][j].setFillColor(Color::Black);
						}
					}


		Gtime = Gclock.getElapsedTime();
		if (Gtime.asSeconds() >= 6.0) {
			new (&Blinky) Ghost(Blinky.getRow(), Blinky.getColumn(), Blinky.getname(), "Blinky.png");
			new (&Pinky) Ghost(Pinky.getRow(), Pinky.getColumn(), Pinky.getname(), "Pinky.png");
			new (&Inky) Ghost(Inky.getRow(), Inky.getColumn(), Inky.getname(), "Inky.png");
			new (&Clyde) Ghost(Clyde.getRow(), Clyde.getColumn(), Clyde.getname(), "Clyde.png");
			Gclock.restart();
		}


		//	 Here comes Handling Collision-->
		if ((player.getshape()).getGlobalBounds().intersects(Blinky.getshape().getGlobalBounds()) ||
			(player.getshape()).getGlobalBounds().intersects(Pinky.getshape().getGlobalBounds()) ||
			(player.getshape()).getGlobalBounds().intersects(Inky.getshape().getGlobalBounds()) ||
			(player.getshape()).getGlobalBounds().intersects(Clyde.getshape().getGlobalBounds())) {



			if (Blinky.getMode() == 'n') {



				if (lives != 0) {
					lives--;
					player.setPosition(390, 645);
					Pinky.setPosition(395, 420);
					Inky.setPosition(350, 420);
					Clyde.setPosition(420, 420);
					Blinky.setPosition(390, 350);

				}

				else {
					gameover();
					system("pause");
				}

			}

			else {
				

			if ((player.getshape()).getGlobalBounds().intersects(Blinky.getshape().getGlobalBounds()))  Blinky.setPosition(390, 350);

				else if ((player.getshape()).getGlobalBounds().intersects(Pinky.getshape().getGlobalBounds()))Pinky.setPosition(395, 420);
				else if ((player.getshape()).getGlobalBounds().intersects(Inky.getshape().getGlobalBounds()))  Inky.setPosition(350, 420);
				else if ((player.getshape()).getGlobalBounds().intersects(Clyde.getshape().getGlobalBounds())) Clyde.setPosition(420, 420);
				 //returns them to their initial position

			}
		}

	else {

		if (score == MaxScore)
			YouWonthegame();

	}

		
	
		
		

		window.clear();
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++) {
				window.draw(board[i][j]);
				window.draw(circboard[i][j]);
			}
		
		player.drawPlayer(window);
		Pinky.drawPlayer(window);
		Blinky.drawPlayer(window);
		Clyde.drawPlayer(window);
		Inky.drawPlayer(window);
		
		displayScore();
		displayLives();
		
		window.display();
		
	}

	if (!window.isOpen()) {
		Blinky.destruct();
		Pinky.destruct();
		Inky.destruct();
		Clyde.destruct();
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