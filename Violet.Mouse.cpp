
#include "Violet.h"

Violet::Mouse& Violet::Mouse::get_mouse() {
	static Mouse mouse;
	return mouse;
}

Violet::Vec2d Violet::Mouse::position() const {
	return pos;
}

Violet::Vec2d Violet::Mouse::velocity() const {
	return vel;
}

bool Violet::Mouse::pressing(int BUTTON) const {
	return glfwGetMouseButton(Window::get_glfw_ptr(), BUTTON) == GLFW_PRESS;
}

bool Violet::Mouse::clicked(int BUTTON, int ACTION) const {
	for (const GlfwMouseEvent& mouse_event : mouse_events) {
		if (mouse_event.button != BUTTON)
			continue;
		if (mouse_event.action != ACTION)
			continue;
		return true;
	}
	return false;
}

double Violet::Mouse::scroll() const {
	double scroll_accumulator = 0.0;
	for (const GlfwScrollEvent& scroll_event : scroll_events) {
		scroll_accumulator += scroll_event.yoffset;
	}
	return scroll_accumulator;
}

void Violet::Mouse::reset() {
	GLFWwindow* window_ptr = Window::get_glfw_ptr();
	double x, y; glfwGetCursorPos(window_ptr, &x, &y);
	Vec2d new_pos = { x, y };
	vel = new_pos - pos;
	pos = new_pos;
	mouse_events.clear();
	scroll_events.clear();
}

void Violet::Mouse::push_mouse_event(GlfwMouseEvent mouse_event) {
	mouse_events.push_back(mouse_event);
}

void Violet::Mouse::push_scroll_event(GlfwScrollEvent scroll_event) {
	scroll_events.push_back(scroll_event);
}

