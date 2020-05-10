#include "Help.h"

void fillgraph::FillGraphfile(int**& arr, int**& gamearr) {

	ifstream infile;
	infile.open("Graph.txt");

	ifstream infile2;
	infile2.open("UpdatedGame2.txt");
	arr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++) {
		arr[i] = new int[COLUMNS];
	}


	gamearr = new int* [GROWS];
	for (int i = 0; i < GROWS; i++) {
		gamearr[i] = new int[GCOLUMNS];
	}

	ofstream mine;
	mine.open("Graph.txt");

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {

			mine << 0 << " ";
		}
		mine << endl;

	}


	while (!infile.eof()) {
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLUMNS; j++) {

				infile >> arr[i][j];

			}

	}

	/*for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLUMNS; j++) {

			cout<< arr[i][j]<<" ";

		}

	cout << endl;
}*/



	while (!infile2.eof()) {
		for (int i = 0; i < GROWS; i++)
			for (int j = 0; j < GCOLUMNS; j++) {

				infile2 >> gamearr[i][j];

			}

	}





	int firstnode = 0, secondnode = 0;
	for (int i = 0; i < GROWS; i++) {
		for (int j = 0; j < GCOLUMNS; j++) {
			firstnode = gamearr[i][j];
			if (gamearr[i][j] > 9) {

				int r = i; int c = j;
				while (c > 0 && c > j - 4) {
					if (gamearr[r][c - 1] > 9) {
						secondnode = gamearr[r][c - 1];
						arr[firstnode - 10][secondnode - 10] = 1;
						break;
					}
					c--;
				}

				r = i; c = j;
				while (c < GCOLUMNS && c < j + 4) {
					if (gamearr[r][c + 1] > 9) {
						secondnode = gamearr[r][c + 1];
						arr[firstnode - 10][secondnode - 10] = 1;
						break;
					}
					c++;
				}

				r = i; c = j;
				while (r > 0 && r > i - 4) {
					if (gamearr[r - 1][c] > 9) {
						secondnode = gamearr[r - 1][c];
						arr[firstnode - 10][secondnode - 10] = 1;
						break;
					}
					r--;
				}

				r = i; c = j;
				while (r < GROWS && r < i + 4) {
					if (gamearr[r + 1][c] > 9) {
						secondnode = gamearr[r + 1][c];
						arr[firstnode - 10][secondnode - 10] = 1;
						break;
					}
					r++;
				}

			}

		}
	}






	ofstream outfile;
	outfile.open("Graph.txt");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {

			outfile << arr[i][j] << " ";
		}
		outfile << endl;
	}

	for (int i = 0; i < ROWS; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	for (int i = 0; i < GROWS; i++) {
		delete[] gamearr[i];
	}
	delete[] gamearr;

	infile.close();
	outfile.close();


}