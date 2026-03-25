
#pragma once
#include "glEvent.h"
#include "RenderMath.h"

namespace Violet {

	class Mouse;
	class Window;

	class Mouse {
	public:
		Vec2d position() const;
		Vec2d velocity() const;
		bool pressing(int BUTTON) const;
		bool clicked(int BUTTON, int ACTION) const;
		double scroll() const;

	private:
		friend Window;
		GLFWwindow* window_ptr;
		Vec2d pos, vel;
		std::vector<GlfwMouseEvent> mouse_events;
		std::vector<GlfwScrollEvent> scroll_events;

		Mouse(GLFWwindow* window_ptr);
		~Mouse();
		void reset();
		void push_mouse_event(GlfwMouseEvent mouse_event);
		void push_scroll_event(GlfwScrollEvent scroll_event);

		Mouse(const Mouse& other) = delete;
		Mouse(Mouse&& other) = delete;
		Mouse& operator = (const Mouse& other) = delete;
		Mouse& operator = (Mouse&& other) = delete;
	};
}

