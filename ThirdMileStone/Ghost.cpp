#include "Ghost.h"

Ghost::Ghost() {
	Player();
	mode = 'n';  // n->normal ; f->fright 

	ghostindex = 0; pacindex = 0;

	grapharr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++) {
		grapharr[i] = new int[COLUMNS];
	}

	gamearr = new int* [GROWS];
	for (int i = 0; i < GROWS; i++) {
		gamearr[i] = new int[GCOLUMNS];
	}
	
	Fillarray();

}

Ghost::Ghost(int x, int y, string fname, string imageName) {
	Player(x, y, fname, imageName);
	if (!playerTexture.loadFromFile(imageName))
		cout << "Error loading from file\n";
	shape.setTexture(playerTexture);
	shape.setPosition(Vector2f(x, y));
	ghostindex = 0; pacindex = 0;
	
	grapharr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++) {
		
		grapharr[i] = new int[COLUMNS];
	}

	gamearr = new int* [GROWS];
	for (int i = 0; i < GROWS; i++) {
		gamearr[i] = new int[GCOLUMNS];
	}
	
	Fillarray();

	mode = 'n';
}

//Ghost::~Ghost() {
//	
//	for (int i = 0; i < ROWS; i++) {
//		delete[] grapharr[i];
//	}
//	delete[] grapharr;
//	
//	for (int i = 0; i < GROWS; i++) {
//		delete[] gamearr[i];
//	}
//	delete[] gamearr;
//
//}

void Ghost::Fillarray() {
	
	ifstream infile;
	infile.open("Graph.txt");
	
	while (!infile.eof()) {
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++)
				infile >> grapharr[i][j];
	}


	ifstream gamefile;
	gamefile.open("UpdatedGame2.txt");
	while (!gamefile.eof()) {
		for (int i = 0; i < GROWS; i++)
			for (int j = 0; j < GCOLUMNS; j++)
				gamefile >> gamearr[i][j];
	}

	infile.close();
	gamefile.close();
}

void Ghost::test() {
	

	for (int i = 0; i < NumOfNodes; i++)
	{
		for (int j = 0; j < result[i].size(); j--)
			cout << result[i][j] << " ";
		cout << endl;
	}
}

int Ghost::position_to_index(Vector2f position) {
	
	int i = ((position.y) - 50) / 10;  //390  640
	int j= ((position.x) - 50) / 10;
	return gamearr[i][j];

}

Vector2f Ghost::index_to_position(int index) {
	
	int x = 0; int y = 0; bool loopbreakflag=false;
	for (int i = 0; i < GROWS; i++) {
		for (int j = 0; j < GCOLUMNS; j++) 
			if (gamearr[i][j] == index+10) {
				x = i; y = j;
				loopbreakflag = true;
				break;
			}

		if (loopbreakflag)
			break;
		
	}

	//int x = 0; int y = 0; bool loopbreakflag = false;
	//
	//int r  = ((getPlayerPosition().y) - 50) / 10;  //390  640
	//int c = ((getPlayerPosition().x) - 50) / 10;

	//int i = ((getPlayerPosition().y) - 50) / 10;  //390  640
	//int j = ((getPlayerPosition().x) - 50) / 10;
	//
	//while (c > 0 && c > j - 4) {
	//	if (gamearr[r][c - 1] ==index) {
	//		x = r; y = c - 1;
	//		break;
	//	}
	//	c--;
	//}

	//r = i; c = j;
	//while (c < GCOLUMNS && c < j + 4) {
	//	if (gamearr[r][c + 1] == index) {
	//		x = r; y = c + 1;
	//		break;
	//	}
	//	c++;
	//}

	//r = i; c = j;
	//while (r > 0 && r > i - 4) {
	//	if (gamearr[r - 1][c] ==index) {
	//		x = r - 1; y = c;
	//		break;
	//	}
	//	r--;
	//}

	//r = i; c = j;
	//while (r < GROWS && r < i + 4) {
	//	if (gamearr[r + 1][c] ==index) {
	//		x = r + 1; y = c;
	//		break;
	//	}
	//	r++;
	//}

	Vector2f posreturned = Vector2f(x,y);
	x = 50 + 10 * x; y = 50 + 10 * y;
	return Vector2f(y,x);

}

vector<vector<int>> Ghost::dijkpath(int startNode) {
	int temp[325][325], costs[325], previous[325];
	bool visited[325];
	//temp
	for (int i = 0; i < NumOfNodes; i++)
		for (int j = 0; j < NumOfNodes; j++)
			if (grapharr[i][j] == 0)
				temp[i][j] = INFINITE;
			else
				temp[i][j] = grapharr[i][j];
	 //costs, previous, and visited
	for (int i = 0; i < NumOfNodes; i++)
	{
		costs[i] = temp[startNode][i];
		previous[i] = startNode;
		visited[i] = false;
	}
	 //startNode
	costs[startNode] = 0;
	visited[startNode] = true;

	int count = 1, nextNode, minimumCost;
	while (count < NumOfNodes)
	{
		 //Find the minimum cost in order to visit a node.
		minimumCost = INFINITE;
		for (int i = 0; i < NumOfNodes; i++)
			if ((costs[i] < minimumCost) && (visited[i] == false))
			{
				minimumCost = costs[i];
				nextNode = i;
			}
		 //Visit the node.
		visited[nextNode] = true;
		 //Update the costs of the children of the visited node.
		for (int i = 0; i < NumOfNodes; i++)
			if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
			{
				costs[i] = minimumCost + temp[nextNode][i];
				previous[i] = nextNode;
			}
		count++;
	}
	 //Fill the paths.
	int j;
	vector<vector<int>> paths;
	paths.resize(NumOfNodes);
	for (int i = 0; i < NumOfNodes; i++)
	{
		paths[i].push_back(i);
		if (i != startNode)
		{
			j = i;
			do
			{
				j = previous[j];
				paths[i].insert(paths[i].begin(), j);
			} while (j != startNode);
		}
	}
	return paths;

}

vector<int> Ghost::findthepath(vector<vector<int>> paths) {
	
	for (int i = 0; i < NumOfNodes; i++){

		int size = paths[i].size();
		if (paths[i][size - 1] == pacindex)
			return paths[i];

	}
	
	return paths[1];

}

void Ghost::moveGhost(Vector2f pacpos) {
	 
	 ghostindex = position_to_index(getPlayerPosition());
	 //cout << "ghostindex: " << ghostindex << endl;
	 pacindex = position_to_index(pacpos);
	 pacindex = pacindex - 10;
	 //cout << "posindex: " << pacindex << endl;

	 result = dijkpath(ghostindex-10);
	 vector<int> shortestpath = findthepath(result);

	 //cout << "Shortest next node: " << shortestpath[1]<<endl;
	 Vector2f newpos;

	 // to handle the case when it reaches its position
	 if (shortestpath.size() > 1) {
		 newpos = index_to_position(shortestpath[1]);
		 shape.setPosition(newpos);
	 }
	  // next node to move to 
	// cout << newpos.x << " " << newpos.y << endl;

	 

}



void Ghost::setMode(char emode) {
	
	if (emode == 'f' || emode == 'F')
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

void Ghost::destruct() {
	for (int i = 0; i < ROWS; i++) {
		delete[] grapharr[i];
	}
	delete[] grapharr;

	for (int i = 0; i < GROWS; i++) {
		delete[] gamearr[i];
	}
	delete[] gamearr;

}


