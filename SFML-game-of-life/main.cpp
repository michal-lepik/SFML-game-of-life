#include "Board.h"

int main()
{
	int boardWidth = 30;
	int boardHeight = 30;
	int cellSize = 30;

	Board newGame(boardWidth, boardHeight, cellSize);
	newGame.play();

	return 0;
}
