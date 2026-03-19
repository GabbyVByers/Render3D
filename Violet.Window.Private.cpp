
#include "Violet.h"

GLFWwindow* Violet::Window::getGLFWptr() {
	return window_ptr;
}

void Violet::Window::callBackWindowResize(GLFWwindow* window_ptr, int width, int height) {
	glViewport(0, 0, width, height);
}

void Violet::Window::callBackKeyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods) {
	glKeyboardEvent key_event = {
		key,
		scancode,
		action,
		mods
	};
	Keyboard& keyboard = Keyboard::getKeyboard();
	keyboard.pushKeyEvent(key_event);
}

void Violet::Window::callBackMouse(GLFWwindow* window_ptr, int button, int action, int mods) {
	glMouseEvent mouse_event = {
		button,
		action,
		mods
	};
	Mouse& mouse = Mouse::getMouse();
	mouse.pushMouseEvent(mouse_event);
}

void Violet::Window::callBackMouseScroll(GLFWwindow* window_ptr, double xoffset, double yoffset) {
	glScrollEvent scroll_event{
		xoffset,
		yoffset
	};
	Mouse& mouse = Mouse::getMouse();
	mouse.pushScrollEvent(scroll_event);
}

