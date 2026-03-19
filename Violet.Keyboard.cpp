
#include "Violet.h"

Violet::Keyboard& Violet::Keyboard::getKeyboard() {
	static Keyboard keyboard;
	return keyboard;
}

bool Violet::Keyboard::pressed(int key, int edge) {
	for (glKeyboardEvent key_event : keyboard_events) {
		if (key_event.key != key)
			continue;
		if (key_event.action != edge)
			continue;
		return true;
	}
	return false;
}

bool Violet::Keyboard::pressing(int key) {
	return glfwGetKey(Window::getGLFWptr(), key) == GLFW_PRESS;
}

void Violet::Keyboard::reset() {
	keyboard_events.clear();
}

void Violet::Keyboard::pushKeyEvent(glKeyboardEvent& key_event) {
	keyboard_events.push_back(key_event);
}

