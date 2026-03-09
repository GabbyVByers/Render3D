
#include "Window.h"

int main() {
	Vi::Window::createGLFWContext("Render3D", 1920, 1080);
	
	while (Vi::Window::isOpen()) {

	}

	Vi::Window::destroyGLFWContext();
	return 0;
}

