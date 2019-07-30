#ifndef TAIL_H
#define TAIL_H

#include<vector>
#include<SFML/Graphics.hpp>
#include "snake.h"
#include<cmath>

class tail : public snake
{
	std::vector<sf::RectangleShape> snakeTail_;
	double offsetX_;
	double offsetY_;
	int nTail_;


public:
	//- constructors
	tail();

	//- destructor
	~tail();

	//- member functions

	// Access
	double getOffsetX();
	double getOffsetY();
	int getnTail();
	std::vector<sf::RectangleShape> getSnakeTail();

	// Edit
	void followSnake(const snake& snake_, double& snakeTurnPosition_x, double& snakeTurnPosition_y);
	void setOffsetX(const double& offsetX);
	void setOffsetY(const double& offsetY);
	void setnTail(const int& nTail);	
	void setSnakeTail(const std::vector<sf::RectangleShape>& snakeTail);
	void addTail();
};

#endif // !
