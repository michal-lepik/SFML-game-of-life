#include "Board.h"

Board::Board(int width, int height, int cellSize)
{
	this->width = width;
	this->height = height;
	this->cellSize = cellSize;

	window.create(sf::VideoMode(width*cellSize, height*cellSize), "Conway's Game of Life", sf::Style::Titlebar | sf::Style::Close);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Cell newCell(x, y, cellSize);
			this->gameBoard.push_back(newCell);
		}
	}
}

Board::~Board() {}

int Board::countNeighbours(int row, int col)
{
	int count = 0;

	for (int y = max(0, col - 1); y <= min(this->height - 1, col + 1); y++)
	{
		for (int x = max(0, row - 1); x <= min(this->width - 1, row + 1); x++)
		{
			if ((x != row || y != col) && this->gameBoard[x + y * width].getIsAlive())
			{
				count++;
			}
		}
	}

	return count;
}

vector<Cell> Board::generateEmptyBoard()
{
	vector<Cell> newBoard = gameBoard;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{

			newBoard[x + y * width].kill();

		}
	}

	return newBoard;
}

vector<Cell> Board::generateNewBoard()
{
	vector<Cell> newBoard = gameBoard;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int neighbours = countNeighbours(x, y);

			if (neighbours < 2 || neighbours > 3)
			{
				newBoard[x + y * width].kill();
			}
			else if (neighbours == 3)
			{
				newBoard[x + y * width].born();
			}
		}
	}

	return newBoard;
}

vector<Cell> Board::generateRandomBoard()
{
	vector<Cell> newBoard = generateEmptyBoard();

	srand(time(NULL));

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if ((rand() % 100) < 20)
			{
				newBoard[x + y * width].born();
			}
		}
	}

	return newBoard;
}

void Board::play()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
				{
					isPlaying = !isPlaying;
				}
				else if (event.key.code == sf::Keyboard::C)
				{
					isPlaying = false;
					gameBoard = generateEmptyBoard();
				}
				else if (event.key.code == sf::Keyboard::R)
				{
					isPlaying = false;
					gameBoard = generateRandomBoard();
				}


			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left && !isPlaying)
				{
					int x = event.mouseButton.x / cellSize;
					int y = event.mouseButton.y / cellSize;

					gameBoard[x + y * width].getIsAlive() ? gameBoard[x + y * width].kill() : gameBoard[x + y * width].born();
				}
				break;
			}
		}

		window.clear();

		if (isPlaying)
		{
			gameBoard = generateNewBoard();
			sf::sleep(sf::milliseconds(200));
		}

		for (int i = 0; i < gameBoard.size(); i++) {
			gameBoard[i].draw(window);
		}

		window.display();
	}
}
