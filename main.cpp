#include <SFML/Graphics.hpp>
#include "snake.h"
#include<iostream>
#include "tail.h"
#include<vector>
#include<time.h>
#include "multiThread.h"
#include "food.h"
#include<cmath>

#include<chrono>
#include<thread>

int main()
{

	//- class hierarchy test 
	A obja;
	B objb;
	A* objc = new B(7);

	objb.printa();
	std::cout << obja.accessA() << std::endl;
	std::cout << objb.accessA() << std::endl;
	objc->printa();
	/*obja.convert(objb);
	obja.accessA();*/
	

	sf::RenderWindow window(sf::VideoMode(400, 500), "snake | rendered with SFML");
	sf::RectangleShape rectangle(sf::Vector2f(5, 5));
	
	//- random number generator test
	std::srand(time(0));
	int max_x = (int)window.getSize().x;
	int max_y = (int)window.getSize().y;

	int rand_x = std::rand() % max_x + 1;
	int rand_y = std::rand() % max_y + 1;

	for (int i = 0; i < 10; i++)
	{
		rand_x = std::rand() % max_x + 1;
		rand_y = std::rand() % max_y + 1;
		std::cout << "xrand: " << rand_x << std::endl
			<< "yrand: " << rand_y << std::endl;
	}

	//rectangle.setOutlineColor(sf::Color::Red);
	//rectangle.setOutlineThickness(0.5);

	rectangle.setPosition(0.f, 0.f);
	rectangle.setFillColor(sf::Color::Red);

	snake snake1;
	std::cout << snake1.getSnakeSize() << std::endl;
	std::cout << snake1.getSnakeSpeed() << std::endl;

	std::cout << "-------------------------------" << std::endl;
	std::cout << *(snake1.getSnakeSize()) << std::endl;
	std::cout << *(snake1.getSnakeSpeed()) << std::endl;

	double position[2] = { 250.0, -250.0 };
	int direction[2] = { 0, 0 };
	snake snake2(3, 2.0, position, direction);
	//std::cout << *(snake2.getSnakePosition()) << std::endl;
	//std::cout << *(snake2.getSnakePosition() + 1) << std::endl;
	// move the snake and see how it will look like.
	double dt = 0.1;
	snake2.snakeMove(dt);
	/*std::cout << *(snake2.getSnakePosition()) << std::endl;
	std::cout << *(snake2.getSnakePosition() + 1) << std::endl;

	std::cout << "----------------------------------" << std::endl;
	std::cout << rectangle.getSize().x << std::endl;
	std::cout << rectangle.getSize().y << std::endl;
*/

	// tail portion
	tail tail2;
	//- extra information on tail 

	// food portion
	food snakeFood;
	std::chrono::seconds foodUpdateTime(7);

	// thread construction
	/*std::thread t1(snakeFood.feedSnake((float)rand_x, (float)rand_y));
	t1.detach();*/

	// time control for feeding snake
	clock_t feedTime = clock();
	//bool multiThreadFinished = true;

	//- junk 
	sf::RectangleShape testShape(sf::Vector2f(5, 5));
	testShape.setPosition(15, 15);
	testShape.setFillColor(sf::Color::Red);
	
	std::vector<sf::RectangleShape> foodStorage;

	double snakeTurnPositionX = 0;
	double snakeTurnPositionY = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed | (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						window.close();
						break;

					case sf::Keyboard::Up:
						snake2.setSnakeDirection(0, 1);
						snake2.setisDirectionChanged(true);
						snakeTurnPositionX = *(snake2.getSnakePosition());
						snakeTurnPositionX = *(snake2.getSnakePosition() + 1);
						break;
						
					case sf::Keyboard::Down:
						snake2.setSnakeDirection(0, -1);
						snake2.setisDirectionChanged(true);
						snakeTurnPositionX = *(snake2.getSnakePosition());
						snakeTurnPositionX = *(snake2.getSnakePosition() + 1);
						break;

					case sf::Keyboard::Left:
						snake2.setSnakeDirection(-1, 0);
						snake2.setisDirectionChanged(true);
						snakeTurnPositionX = *(snake2.getSnakePosition());
						snakeTurnPositionX = *(snake2.getSnakePosition() + 1);
						break;

					case sf::Keyboard::Right:
						snake2.setSnakeDirection(1, 0);
						snake2.setisDirectionChanged(true);
						snakeTurnPositionX = *(snake2.getSnakePosition());
						snakeTurnPositionX = *(snake2.getSnakePosition() + 1);
						break;

					case sf::Keyboard::Space:
						snake2.snakeStop();
						break;

					default:
						break;
				}
			}
		}
		
		// random position generator
		rand_x = std::rand() % max_x + 1;
		rand_y = std::rand() % max_y + 1;

		window.clear();
		window.draw(testShape);
		rectangle.setFillColor(sf::Color::Red);
		window.draw(rectangle); // our snake head. 
		for (size_t i = 0; i < tail2.getnTail(); i++)
			window.draw(tail2.getSnakeTail()[i]); // drawing tail.
		for (size_t j = 0; j < foodStorage.size(); j++)
			window.draw(foodStorage[j]); // drawing snake food. this way not blinking!

		/*if (multiThreadFinished)
		{
			window.setActive(true);
		}*/


		window.display();

		//- threading -- no need for threading with following lines of codes.
		if ( (float)(clock() - feedTime) / CLOCKS_PER_SEC > 10.000 )
		{
			/*window.setActive(false);
			std::thread t1(multiThreadWindowDraw, &window, &snakeFood, &rand_x, &rand_y);
			feedTime = clock();
			multiThreadFinished = true;*/
			sf::RectangleShape shape = snakeFood.feedSnake((float)rand_x, (float)rand_y);
			window.draw(shape);
			window.display();
			feedTime = clock();
			foodStorage.push_back(shape);

		}
		//t1.detach();
		//window.draw(snakeFood.multiThread((float)rand_x, (float)rand_y)); // random food for snake.

		// SFML threading capability :: cannot be used since it doesn't get versatile inputs.
		
		/*for (size_t i = 0; i < tail2.getSnakeTail().size(); i++)
			std::cout << "position of first tail: ( " << tail2.getSnakeTail()[i].getPosition().x
			<< ", " << tail2.getSnakeTail()[i].getPosition().y << ") " << std::endl;

		std::cout << "snake head position : (" << *(snake2.getSnakePosition()) << ", "
			<< *(snake2.getSnakePosition() + 1) << ")" << std::endl;*/

		//- check if snake has eaten the food.
		for (size_t k = 0; k < foodStorage.size(); k++)
		{
			if ( std::abs( std::abs(*(snake2.getSnakePosition())) - 
				std::abs(foodStorage[k].getPosition().x) <= 5 ) &&
				std::abs( std::abs(*(snake2.getSnakePosition() + 1)) - 
					std::abs(foodStorage[k].getPosition().y) ) <= 5 )
			{
				tail2.addTail();
				foodStorage.erase(foodStorage.begin() + k);
			}
		}

		std::chrono::milliseconds duration(10);
		std::this_thread::sleep_for(duration);

		snake2.snakeMove(dt);
		rectangle.setPosition( *(snake2.getSnakePosition()), - *(snake2.getSnakePosition() + 1));
		tail2.followSnake(snake2, snakeTurnPositionX, snakeTurnPositionY);

		/*std::cout << *(snake2.getSnakePosition()) << std::endl;
		std::cout << *(snake2.getSnakePosition() + 1) << std::endl;
		*/
	
	}

	return 0;
}
