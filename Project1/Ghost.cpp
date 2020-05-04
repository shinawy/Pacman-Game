#include "Ghost.h"

Ghost::Ghost() {
	mode = 'n';  // n->normal ; f->fright 
}

Ghost::Ghost(int x, int y, string name, string imageName) {
	Player(x,y,name,imageName);
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

