#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Grid {
public:
	T matrix[6][6];

	void printGrid() {
		for (unsigned i = 0; i < 6; ++i)
		{
			for (unsigned j = 0; j < 6; ++j)
				cout << boolalpha << setw(5) << matrix[i][j]  << " ";
			cout << endl;
		}
		cout << endl;
	}
};


int checkNeighbors(Grid<bool> &bombLocations, int xpos, int ypos) {
	int counter = 0;
	//check the 8+1 possible locations around the element for a true value
	for (int i = xpos - 1; i <= xpos + 1; ++i)
	{
		for (int j = ypos - 1; j <= ypos + 1; ++j)
		{
			// bounds check
			if  ( (i >=0 && j>=0) && (i < 6 && j < 6) )
			if (bombLocations.matrix[i][j] == true)
			{
				counter++;
			}
		}
	}
	return counter;
}

Grid<int> MakeGridOfCounts(Grid<bool> & bombLocations) {
	Grid<int> *resultGrid;
	resultGrid = new Grid<int>();
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			resultGrid->matrix[i][j] = checkNeighbors(bombLocations, i, j);
		}
	}
	return *resultGrid;
}



int main() {

	//Create game board
	Grid<bool> gameboard;

	//Populate the game board with testing values
	gameboard.matrix[0][0] = true; 	gameboard.matrix[0][1] = false; gameboard.matrix[0][2] = false;  gameboard.matrix[0][3] = false; gameboard.matrix[0][4] = false; gameboard.matrix[0][5] = true;
	gameboard.matrix[1][0] = false; gameboard.matrix[1][1] = false; gameboard.matrix[1][2] = false;  gameboard.matrix[1][3] = false; gameboard.matrix[1][4] = false; gameboard.matrix[1][5] = true;
	gameboard.matrix[2][0] = true; 	gameboard.matrix[2][1] = true;  gameboard.matrix[2][2] = false;  gameboard.matrix[2][3] = true;  gameboard.matrix[2][4] = false; gameboard.matrix[2][5] = true;
	gameboard.matrix[3][0] = true; 	gameboard.matrix[3][1] = false; gameboard.matrix[3][2] = false;  gameboard.matrix[3][3] = false; gameboard.matrix[3][4] = false; gameboard.matrix[3][5] = false;
	gameboard.matrix[4][0] = false; gameboard.matrix[4][1] = false; gameboard.matrix[4][2] = true;   gameboard.matrix[4][3] = false; gameboard.matrix[4][4] = false; gameboard.matrix[4][5] = false;
	gameboard.matrix[5][0] = false; gameboard.matrix[5][1] = false; gameboard.matrix[5][2] = false;  gameboard.matrix[5][3] = false; gameboard.matrix[5][4] = false; gameboard.matrix[5][5] = false;

	//Print the starting game state
	cout << "The starting game board is: " << endl;
	cout << "===========================================" << endl;
	gameboard.printGrid();
	cout << endl;

	//Perform the board analysis

	Grid<int> finalboard = MakeGridOfCounts(gameboard);

	//Print the final game state after calculations
	cout << "The final game board is: " << endl;
	cout << "===========================================" << endl;
	finalboard.printGrid();
	cout << endl;
	
	return 0;
}