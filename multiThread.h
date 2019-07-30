#ifndef MULTITHREAD_H
#define MULTITHREAD_H

#include<SFML/Graphics.hpp>
#include "food.h"

void multiThreadWindowDraw(sf::RenderWindow* window_, food* snakeFood_, int* randX_, int* randY_)
{
	sf::RectangleShape shape = snakeFood_->feedSnake(*randX_, *randY_); // possibly implicit conversion of int to float!! note int&
	window_->setActive(true);
	window_->clear();
	window_->draw(shape);
	window_->display();
	window_->setActive(false);
}

#endif // !MULTITHREAD_H
