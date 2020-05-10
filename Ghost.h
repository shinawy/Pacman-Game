#pragma once
#include "Player.h"
#include <fstream>
#include <vector>

class Ghost: public Player
{
private:
	char mode;
	vector<vector<int>> result;
	int** grapharr;
	int** gamearr;
	int ghostindex;
	int pacindex;
	const int ROWS = 325, COLUMNS = 325;
    const int NumOfNodes = 325; const int INFINITE = 9999;
	const int GROWS = 82, GCOLUMNS = 73;

	int position_to_index(Vector2f position);
	vector<int> findthepath(vector<vector<int>>);
	Vector2f index_to_position(int);
	vector<vector<int>> dijkpath(int startNode);
	void Fillarray();

public:
	Ghost();
	//~Ghost();
	
	void test();
	
	void moveGhost(Vector2f pacpos);
	

	Ghost(int, int, string, string);
	void setMode(char);
	void FrightMode();
	char getMode();
	void destruct();

};

