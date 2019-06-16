#include "Cell.h"

Cell::Cell(int posX, int posY, int size)
{
	this->posX = posX;
	this->posY = posY;
	this->size = size;

	this->rectangle.setSize(sf::Vector2f(size, size));
	this->rectangle.setFillColor(sf::Color::Black);  
	this->rectangle.setOutlineColor(sf::Color::Red);
	this->rectangle.setOutlineThickness(1);
}

Cell::~Cell() {}

int Cell::getPosX()
{
	return this->posX;
}

int Cell::getPosY()
{
	return this->posY;
}

bool Cell::getIsAlive()
{
	return this->isAlive;
}

void Cell::draw(sf::RenderWindow& window)
{
	this->rectangle.setPosition(posX*size, posY*size);
	window.draw(this->rectangle);
}

void Cell::born()
{
	this->isAlive = true;
	this->rectangle.setFillColor(sf::Color::White);
}

void Cell::kill()
{
	this->isAlive = false;
	this->rectangle.setFillColor(sf::Color::Black);
}
