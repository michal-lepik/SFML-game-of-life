#include "Cell.h"
#include <iostream>
#include <vector>

using namespace std;

class Board
{
	int width;
	int height;
	int cellSize;
	bool isPlaying = false;

	vector<Cell> gameBoard;

	sf::RenderWindow window;

	int countNeighbours(int row, int col);
	vector<Cell> generateEmptyBoard();
	vector<Cell> generateNewBoard();

public:
	Board(int width, int height, int cellSize);
	~Board();

	void play();
};
