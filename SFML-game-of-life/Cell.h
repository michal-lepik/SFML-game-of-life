#include "SFML/Graphics.hpp"

class Cell
{
	int posX;
	int posY;
	int size;
	bool isAlive = false;

	sf::RectangleShape rectangle;

public:
	Cell(int posX, int posY, int size);
	~Cell();
	
	int getPosX();
	int getPosY();
	bool getIsAlive();

	void draw(sf::RenderWindow& window);
	void born();
	void kill();
};
