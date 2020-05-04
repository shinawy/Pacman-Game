#include "Player.h"

Player::Player() {
	name = " ";
}

Player::Player(int x,int y, string name, string imageName) {
	if (!playerTexture.loadFromFile(imageName))
		cout<<"Error loading from file\n";
	shape.setTexture(playerTexture);
	shape.setPosition(Vector2f(x, y));
}


void Player::setPosition(int x, int y) {
	shape.setPosition(Vector2f(x, y));

}

void Player::setsize(int a, int b) {
	shape.setScale(Vector2f(50,50));

}

void Player::move(char direction, int** arr) {
	int currentRow = ((shape.getPosition().x) / 10);
	int currentColumn = ((shape.getPosition().y) / 10);

	if (direction == 'U' || direction == 'u')
	{
		if (arr[currentRow - 1][currentColumn] != -1)
		{
			//currentRow--;
			shape.move(0, -70);
		}
	}
	else if (direction == 'D' || direction == 'd')
	{
		if (arr[currentRow + 1][currentColumn] != -1)
		{
			//currentRow++;
			shape.move(0, 70);
		}
	}
	else if (direction == 'R' || direction == 'r')
	{
		if (arr[currentRow][currentColumn + 1] != -1)
		{
			//currentColumn++;
			shape.move(70, 0);
		}
	}
	else if (direction == 'L' || direction == 'l')
	{
		if (arr[currentRow][currentColumn - 1] != -1)
		{
			//currentColumn--;
			shape.move(-70, 0);
		}
	}

}

void Player::drawPlayer(RenderWindow& window) {
	window.draw(shape);
}

int Player::getRow() {
	return (shape.getPosition().x);

}

int Player::getColumn() {
	return (shape.getPosition().y);
}
Vector2f Player::getPlayerPosition() {
	return (shape.getPosition());
}
