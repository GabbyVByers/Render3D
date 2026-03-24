
#include "Violet.h"

Violet::Keyboard& Violet::Keyboard::get_keyboard() {
	static Keyboard keyboard;
	return keyboard;
}

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
	return glfwGetKey(Window::get_glfw_ptr(), key) == GLFW_PRESS;
}

void Violet::Keyboard::reset() {
	keyboard_events.clear();
}

void Violet::Keyboard::push_key_event(GlfwKeyboardEvent& key_event) {
	keyboard_events.push_back(key_event);
}

