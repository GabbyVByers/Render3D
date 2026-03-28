
/*
	Window.Keyboard.cpp
*/

#include "Window.h"

namespace Violet {

	Keyboard::Keyboard(GLFWwindow* ptr) {
		window_ptr = ptr;
	}

	bool Keyboard::pressed(int key, int edge) {
		for (GlfwKeyboardEvent key_event : keyboard_events) {
			if (key_event.key != key)
				continue;
			if (key_event.action != edge)
				continue;
			return true;
		}
		return false;
	}

	bool Keyboard::pressing(int key) {
		return glfwGetKey(window_ptr, key) == GLFW_PRESS;
	}

	void Keyboard::reset() {
		keyboard_events.clear();
	}

	void Keyboard::push_key_event(GlfwKeyboardEvent& key_event) {
		keyboard_events.push_back(key_event);
	}
}

