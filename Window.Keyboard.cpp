
/*
	Window.Keyboard.cpp
*/

#include "Window.h"

Violet::Keyboard::Keyboard(GLFWwindow* window_ptr) { this->window_ptr = window_ptr; }
Violet::Keyboard::~Keyboard() {}

bool Violet::Keyboard::pressed(int key, int edge) {
	for (GlfwKeyboardEvent key_event : keyboard_events) {
		if (key_event.key != key)
			continue;
		if (key_event.action != edge)
			continue;
		return true;
	}
	return false;
}

bool Violet::Keyboard::pressing(int key) {
	return glfwGetKey(window_ptr, key) == GLFW_PRESS;
}

void Violet::Keyboard::reset() {
	keyboard_events.clear();
}

void Violet::Keyboard::push_key_event(GlfwKeyboardEvent& key_event) {
	keyboard_events.push_back(key_event);
}

