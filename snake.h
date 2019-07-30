#ifndef  SNAKE_H
#define  SNAKE_H
#include "SFML/Graphics.hpp"

class snake
{
	int	snakeSize_;
	double snakeSpeed_;
	double snakePosition_[2];
	int snakeDirection_[2];
	bool isDirectionChanged;


public:

	// constructors
	snake();
	snake(int snakeSize, double snakeSpeed, double p[], int dir[]);
	snake(int snakeSize, const double* snakeSpeed, const double p[], const int dir[]);
	// destructor
	~snake();

	// function members
		// Edit
	void setSnakeSize(const int& snakeSize);
	void setSnakeSpeed(const double& snakeSpeed);
	void setSnakePosition(const double& x, const double& y);
	void setSnakeDirection(const int& dir1, const int& dir2);
	void setisDirectionChanged(bool value);
	void setisDirectionChanged(bool value) const;

		// Access
	const int* getSnakeSize() const ;
	const double*	getSnakeSpeed() const;
	const double*	getSnakePosition() const;
	const int* getSnakeDirection() const;
	const bool getisDirectionChanged() const;

		// Interact
	void snakeMove(const double& dt);
	void snakeBigger();
	void snakeFaster();
	void snakeStop();
	void snakeEat(sf::RectangleShape rectangle);
};

#endif // !
