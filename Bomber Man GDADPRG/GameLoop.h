#pragma once
#include <SFML/Graphics.hpp>


using namespace std;

class GameLoop: private sf::NonCopyable
{
public:
	static const sf::Time TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 832;
	static const int WINDOW_HEIGHT = 832;

	// constructor & runner
	GameLoop();
	void run();

private:
	sf::Time ticks;
	sf::RenderWindow window;

	// functions
	void render();
	void processEvents();
	void update(sf::Time elapsedTime);
};

