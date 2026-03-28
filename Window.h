
/*
	Window.h
*/

#pragma once
#include "GlfwEvent.h"
#include "Mesh.h"
#include "Shapes.h"

namespace Violet {

	class Mouse;
	class Keyboard;
	class Window;

	class Mouse {
	public:
		Vec2d position() const;
		Vec2d velocity() const;
		bool pressing(int button) const;
		bool clicked(int button, int edge) const;
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
		Mouse(Mouse&& other) noexcept = delete;
		Mouse& operator = (const Mouse& other) = delete;
		Mouse& operator = (Mouse&& other) noexcept = delete;
	};

	class Keyboard {
	public:
		bool pressed(int key, int edge);
		bool pressing(int key);

	private:
		friend Window;
		GLFWwindow* window_ptr;
		std::vector<GlfwKeyboardEvent> keyboard_events;

		Keyboard(GLFWwindow* window_ptr);
		~Keyboard();
		void reset();
		void push_key_event(GlfwKeyboardEvent& key_event);

		Keyboard(const Keyboard& other) = delete;
		Keyboard(Keyboard&& other) = delete;
		Keyboard& operator = (const Keyboard& other) = delete;
		Keyboard& operator = (Keyboard&& other) = delete;
	};

	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window();
		static Vec2i size();
		void vsync(bool vsync);
		bool is_open();
		void poll_events();
		void clear(Color color);
		void draw(const Mesh& mesh, Camera& camera);
		void display();

		static Mouse& mouse();
		static Keyboard& keyboard();

	private:
		inline static GLFWwindow* window_ptr = nullptr;
		static void callback_window_resize(GLFWwindow* window_ptr, int width, int height);
		static void callback_keyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods);
		static void callback_mouse(GLFWwindow* window_ptr, int button, int action, int mods);
		static void callback_mousescroll(GLFWwindow* window_ptr, double xoffset, double yoffset);

		Window(const Window& other)              = delete;
		Window(Window&& other)                   = delete;
		Window& operator = (const Window& other) = delete;
		Window& operator = (Window&& other)      = delete;
	};
}

