#include "snake.h"


// constructors

snake::snake():snakeSize_(3), snakeSpeed_(1), isDirectionChanged(false)
{
	snakePosition_[0] = 0.0;
	snakePosition_[1] = 0.0;
	snakeDirection_[0] = 1;
	snakeDirection_[1] = 0;
};

snake::snake(int snakeSize, double snakeSpeed, double p[], int dir[]) :snakeSize_(snakeSize), snakeSpeed_(snakeSpeed)
, isDirectionChanged(false)
{
	snakePosition_[0] = p[0];
	snakePosition_[1] = p[1];
	snakeDirection_[0] = dir[0];
	snakeDirection_[1] = dir[1];
}

snake::snake(int snakeSize, const double* snakeSpeed, const double p[], const int dir[]) :snakeSize_(snakeSize), snakeSpeed_(*snakeSpeed)
, isDirectionChanged(false)
{
	snakePosition_[0] = p[0];
	snakePosition_[1] = p[1];
	snakeDirection_[0] = dir[0];
	snakeDirection_[1] = dir[1];
}


// destructor

snake::~snake() {};

// member functions
	// Edit
void snake::setSnakeSize(const int& snakeSize)
{
	snakeSize_ = snakeSize;
}

void snake::setSnakeSpeed(const double& snakeSpeed)
{
	snakeSpeed_ = snakeSpeed;
}

void snake::setSnakePosition(const double& x, const double& y)
{
	snakePosition_[0] = x; 
	snakePosition_[1] = y;
}

void snake::setSnakeDirection(const int& dir1, const int& dir2)
{
	snakeDirection_[0] = dir1;
	snakeDirection_[1] = dir2;
}

void snake::setisDirectionChanged(bool value)
{
	isDirectionChanged = value;
}

void snake::setisDirectionChanged(bool value) const
{
	this->setisDirectionChanged(value);
}

	// Access
const int* snake::getSnakeSize() const
{
	return &snakeSize_;
}

const double* snake::getSnakeSpeed() const
{
	return &snakeSpeed_;
}

const double* snake::getSnakePosition() const
{
	return snakePosition_; // pointer to the first element of position array.
}

const int* snake::getSnakeDirection() const
{
	return snakeDirection_;
}

const bool snake::getisDirectionChanged() const
{
	return isDirectionChanged;
}
	// Interact
void snake::snakeMove(const double& dt)
{
	snakePosition_[0] += snakeSpeed_ * dt * snakeDirection_[0];
	snakePosition_[1] += snakeSpeed_ * dt * snakeDirection_[1];
}

void snake::snakeBigger()
{
	snakeSize_++;
}

void snake::snakeFaster()
{
	snakeSpeed_++;
}

void snake::snakeStop()
{
	this->setSnakeDirection(0, 0);
}

void snake::snakeEat(sf::RectangleShape rectangle)
{

	if (snakePosition_[0] == rectangle.getPosition().x && snakePosition_[1] == rectangle.getPosition().y)
		snakeSize_++;

}