#ifndef FOOD_H
#define FOOD_H

#include<SFML/Graphics.hpp>
#include<chrono>
#include<thread>
#include<future>

class food
{

private:
	// no member
public:

	// member functions
	sf::RectangleShape feedSnake(float randX, float randY);
	sf::RectangleShape multiThread(float randX, float randY);
	void drawFood(sf::RectangleShape& snakeFood_, sf::RenderWindow& window_);
	

	// constructors
	food();

	// destructor
	~food();

};

#endif // !1
