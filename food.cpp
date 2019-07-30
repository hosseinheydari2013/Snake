#include "food.h"

// member functions
sf::RectangleShape food::feedSnake(float randX, float randY)
{
	sf::RectangleShape snakefood_(sf::Vector2f(5.0, 5.0));
	snakefood_.setPosition(randX, randY);
	//std::chrono::seconds duration(7);
	//std::this_thread::sleep_for(duration);
	return snakefood_;
}

sf::RectangleShape food::multiThread(float randX, float randY)
{
	/*
	std::thread t1(&food::feedSnake, this, randX, randY);
	t1.detach();
	*/
	auto f1 = std::async(&food::feedSnake, this, randX, randY);
	return f1.get();
}

void food::drawFood(sf::RectangleShape& snakeFood_, sf::RenderWindow& window_)
{
	window_.draw(snakeFood_);
}

// constructors
food::food()
{

}


// destructor
food::~food()
{

}