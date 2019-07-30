#include "tail.h"
#include<iostream>

//- constructors
tail::tail() : nTail_(3), offsetX_(5.0), offsetY_(5.0)
{
	const size_t vectorSize = 3;
	snakeTail_.reserve(vectorSize);
	sf::RectangleShape rectangle1(sf::Vector2f(5, 5));
	sf::RectangleShape rectangle2(sf::Vector2f(5, 5));
	sf::RectangleShape rectangle3(sf::Vector2f(5, 5));
	// position 
	rectangle1.setPosition(250.f, -255.f);
	rectangle2.setPosition(250.f, -260.f);
	rectangle3.setPosition(250.f, -265.f);
	// color
	rectangle1.setFillColor(sf::Color::White);
	rectangle2.setFillColor(sf::Color::White);
	rectangle3.setFillColor(sf::Color::White);

	snakeTail_.emplace_back(rectangle1);
	snakeTail_.emplace_back(rectangle2);
	snakeTail_.emplace_back(rectangle3);
	//- for debugging purposes only
	std::cout << "tail constructor is called. getting information on snakeTail: " << std::endl
		<< "snakeTail size: " << snakeTail_.size() << std::endl
		<< "first rectangle position: " << snakeTail_[0].getPosition().x 
		<< ", " << snakeTail_[0].getPosition().y << std::endl
		<< "second rectangle position: " << snakeTail_[1].getPosition().x 
		<< ", " << snakeTail_[1].getPosition().y << std::endl
		<< "third rectangle position: " << snakeTail_[2].getPosition().x 
		<< ", " << snakeTail_[2].getPosition().y << std::endl;

};

//- destructor
tail::~tail() {};

//- member functions

// Access
double tail::getOffsetX()
{
	return offsetX_;
}

double tail::getOffsetY()
{
	return offsetY_;
}

int tail::getnTail()
{
	return nTail_;
}

std::vector<sf::RectangleShape> tail::getSnakeTail()
{
	return snakeTail_;
}

// Edit
void tail::followSnake(const snake& snake_, double& snakeTurnPosition_x, double& snakeTurnPosition_y)
{
	for (size_t	 i = 0; i < snakeTail_.size(); i++)
	{
		//*(this->getSnakePosition) = *(snake_.getSnakePosition) - offsetX_ * nTail_; // x position
		//*(this->getSnakePosition + 1) = *(snake_.getSnakePosition + 1) - offsetY_ * nTail_; // y position
		if (!snake_.getisDirectionChanged())
		{
			snakeTail_[i].setPosition(*(snake_.getSnakePosition()) - offsetX_ * i * *(snake_.getSnakeDirection()),
				-(*(snake_.getSnakePosition() + 1) - offsetY_ * i * *(snake_.getSnakeDirection() + 1)));
		}
		else
		{
			if (std::abs(std::abs(snakeTail_[i].getPosition().x ) - std::abs(snakeTurnPosition_x) < 0.01) &&
				std::abs(std::abs(snakeTail_[i].getPosition().y) - std::abs(snakeTurnPosition_y) < 0.01) )
			{
				snakeTail_[i].setPosition(*(snake_.getSnakePosition()) - offsetX_ * i * *(snake_.getSnakeDirection()),
					-(*(snake_.getSnakePosition() + 1) - offsetY_ * i * *(snake_.getSnakeDirection() + 1)));
				snake_.setisDirectionChanged(false);
			}
			else
			{
				snake tmpSnake(1 , snake_.getSnakeSpeed(), snake_.getSnakePosition(), snake_.getSnakeDirection());

			}
		}
		//updateTail();
	}
}


void tail::setOffsetX(const double& offsetX)
{
	offsetX_ = offsetX;
}

void tail::setOffsetY(const double& offsetY)
{
	offsetY_ = offsetY;
}

void tail::setnTail(const int& nTail)
{
	nTail_ = nTail;
}

void tail::setSnakeTail(const std::vector<sf::RectangleShape>& snakeTail)
{
	snakeTail_ = snakeTail;
}

void tail::addTail()
{
	sf::RectangleShape tmpTail(sf::Vector2f(5.0, 5.0));
	tmpTail.setFillColor(sf::Color::White);
	tmpTail.setPosition(snakeTail_[snakeTail_.size() - 1].getPosition().x - 5.0, 
		snakeTail_[snakeTail_.size() - 1].getPosition().y - 5.0);
	snakeTail_.push_back(tmpTail);
	nTail_++; // update number of tails.

}