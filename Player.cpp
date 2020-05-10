#include "Player.h"

Player::Player() {
	name = " ";
}

Player::Player(int x,int y, string fname, string imageName) {
	name = fname;
	settexture(imageName);
	shape.setPosition(Vector2f(x, y));
}

void Player::settexture(string imageName) {
	if (!playerTexture.loadFromFile(imageName))
		cout << "Error loading from file\n";
	shape.setTexture(playerTexture);

}

void Player::setPosition(int x, int y) {
	shape.setPosition(Vector2f(x, y));
	

}

void Player::setsize(double a, double b) {
	shape.setScale(Vector2f(a,b));

}

void Player::move(char direction, int** arr) {

	
int currentRow = ((shape.getPosition().y)-50)/ 10; //640   59    
	int currentColumn = ((shape.getPosition().x)-50) / 10;  //390    35
 
	if (direction == 'U' || direction == 'u')
	{
		if (arr[currentRow - 1][currentColumn] != 1 && arr[currentRow - 1][currentColumn] != 3 &&
			arr[currentRow - 1][currentColumn + 1] != 1 && arr[currentRow - 1][currentColumn + 1] != 3 &&
			arr[currentRow - 1][currentColumn + 2] != 1 && arr[currentRow -1][currentColumn + 2] != 3 &&
			arr[currentRow - 1][currentColumn + 3] != 1 && arr[currentRow -1][currentColumn + 3] != 3 &&
			arr[currentRow - 1][currentColumn + 4] != 1 && arr[currentRow -1][currentColumn + 4] != 3
			)
		{
			//currentRow--;
			shape.move(0, -10);
		}
	}

	else if (direction == 'D' || direction == 'd')
	{
		if (arr[currentRow + 5][currentColumn] != 1 && arr[currentRow + 5][currentColumn] != 3 &&
			arr[currentRow + 4][currentColumn + 1] != 1 && arr[currentRow + 5][currentColumn + 1] != 3 &&
			arr[currentRow + 4][currentColumn + 2] != 1 && arr[currentRow + 5][currentColumn + 2] != 3 &&
			arr[currentRow + 4][currentColumn + 3] != 1 && arr[currentRow + 5][currentColumn + 3] != 3 &&
			arr[currentRow + 4][currentColumn + 4] != 1 && arr[currentRow + 5][currentColumn + 4] != 3)
		{
			//currentRow++;
			shape.move(0, 10);

		}
	}
	else if (direction == 'R' || direction == 'r')
	{

		if (arr[currentRow][currentColumn + 5] == 7)
			shape.move(Vector2f(-670,0));

		else if (arr[currentRow][currentColumn + 5] != 1 && arr[currentRow][currentColumn +5] != 3 &&
			arr[currentRow + 1][currentColumn +5] != 1 && arr[currentRow + 1][currentColumn +5] != 3 &&
			arr[currentRow + 2][currentColumn +5] != 1 && arr[currentRow + 2][currentColumn +5] != 3 &&
			arr[currentRow + 3][currentColumn +5] != 1 && arr[currentRow + 3][currentColumn +5] != 3 &&
			arr[currentRow + 4][currentColumn +5] != 1 && arr[currentRow + 4][currentColumn +5] != 3)
		{
			
			shape.move(10,0);
		}




	}
	else if (direction == 'L' || direction == 'l')
	{

		if (arr[currentRow][currentColumn - 1] == 8)
			shape.move(670,0);

		else if (arr[currentRow][currentColumn - 1] != 1 && arr[currentRow][currentColumn - 1] != 3 &&
			arr[currentRow + 1][currentColumn - 1] != 1 && arr[currentRow + 1][currentColumn - 1] != 3 &&
			arr[currentRow + 2][currentColumn - 1] != 1 && arr[currentRow + 2][currentColumn - 1] != 3 &&
			arr[currentRow +3][currentColumn - 1] != 1 && arr[currentRow + 3][currentColumn - 1] != 3 &&
			arr[currentRow + 4][currentColumn - 1] != 1 && arr[currentRow + 4][currentColumn - 1] != 3 )
		{
			//currentColumn--;
			shape.move(-10, 0);
		}
	}
	   		

}

void Player:: rotatePlayer(char dir) {
	if (dir == 'r' || dir == 'R')
		shape.rotate(90);
	else if(dir == 'l' || dir == 'L')
		shape.rotate(-90);
}

void Player::drawPlayer(RenderWindow& window) {
	window.draw(shape);
}

void Player:: drawPlayer(RenderWindow& window, Transform& trans) {
	
	window.draw(shape, trans);


}


int Player::getRow() {
	
	return (shape.getPosition().x);
	
}


Sprite Player::getshape() {
	return shape;
}

int Player::getColumn() {
	return (shape.getPosition().y);
}

string Player::getname() {
	return name;
}
void Player::print_bounds() {

	RenderWindow mywindow;
	mywindow.create(VideoMode(830, 870), "Pacman");
	sf::err().rdbuf(NULL);
	shape.setPosition(70, 100);
	playerTexture.loadFromFile("Pacman.png");
	shape.setTexture(playerTexture);

	Transform mytransform;
	mytransform.rotate(-90, Vector2f(75,125));
	mytransform.rotate(180, Vector2f(75, 125));
	mytransform.rotate(180, Vector2f(75, 125));
	cout<< shape.getPosition().x << endl<<shape.getPosition().y<<endl;
	
	while (mywindow.isOpen())
	{
		sf::Event event;
		while (mywindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mywindow.close();
		}
		mywindow.clear();
		mywindow.draw(shape, mytransform);
		mywindow.display();
	}


	
	
	
	

	
	
//	shape.setOrigin(Vector2f(25, 25));

	/*shape.rotate(90);
	shape.move(50, 0);
	shape.setPosition(Vector2f(shape.getPosition())+Vector2f(-50,0));*/
	//shape.rotate(90);
	/*cout << shape.getGlobalBounds().top << endl << shape.getGlobalBounds().left << endl << shape.getGlobalBounds().width << endl 
		<< shape.getGlobalBounds().height << endl;*/
	cout << ((shape.getPosition().y) ) << endl;
	cout << ((shape.getPosition().x))  << endl;

}

Vector2f Player::getPlayerPosition() {
	return (shape.getPosition());
}
