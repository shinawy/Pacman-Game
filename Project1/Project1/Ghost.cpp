#include "Ghost.h"

Ghost::Ghost() {
	Player();
	mode = 'n';  // n->normal ; f->fright 
}

Ghost::Ghost(int x, int y, string name, string imageName) {
	//Player(x, y, name, imageName);
	if (!playerTexture.loadFromFile(imageName))
		cout << "Error loading from file\n";
	shape.setTexture(playerTexture);
	shape.setPosition(Vector2f(x, y));
	
		mode = 'n';
}

void Ghost::setMode(char emode) {
	
	if (emode == 'f' || emode == 'F' || emode == 'n' || emode == 'N')
		mode = 'f';
	
	else if (emode == 'n' || emode == 'N')
		mode = 'n';
	
	else {
		cout << "This is not a valid mode\n";
		mode = 'n';
	}
}



char Ghost::getMode() {
	return mode;
}

