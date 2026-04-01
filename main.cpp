
/*
	main.cpp
*/

#include "Window.h"
#include "Demo.h"

class Planet {
public:
	
};

class Map {

};

int main() {
	Vi::Window window("AHHHHHHH", 1920, 1080);
	Vi::Camera camera;

	while (window.is_open()) {
		window.poll_events();
		window.clear(Vi::Color::blue() * 0.2f);
		


		window.display();
	}

	return 0;
}

