
#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "glEvent.h"
#include "Camera.h"
#include "Color.h"

namespace Violet {

	class Vertex;
	class Mesh;

	class Mouse;
	class Keyboard;
	class Window;

	class Vertex {
	public:
		Vec3f position;
		Color color;
	};

	class Mesh {
	public:
		double     scale;
		Vec3d      position;
		Quaternion orientation;
		std::vector<Vertex> vertices;

		Mesh(const std::string& path, GLenum type);
		~Mesh();
		Mat4 modelMatrix() const;

	private:
		friend Window;
		GLuint vao, vbo, shader;
		GLenum primative_type;
	};

	class Mouse {
	public:
		static Mouse& getMouse();
		Vec2d position() const;
		Vec2d velocity() const;
		bool pressing(int BUTTON) const;
		bool clicked(int BUTTON, int ACTION) const;
		double scroll() const;

	private:
		friend Window;
		Vec2d pos, vel;
		std::vector<glMouseEvent> mouse_events;
		std::vector<glScrollEvent> scroll_events;

		Mouse()  {};
		~Mouse() {};
		void reset();
		void pushMouseEvent(glMouseEvent mouse_event);
		void pushScrollEvent(glScrollEvent scroll_event);

		Mouse(const Mouse& other)              = delete;
		Mouse(Mouse&& other)                   = delete;
		Mouse& operator = (const Mouse& other) = delete;
		Mouse& operator = (Mouse&& other)      = delete;
	};

	class Keyboard {
	public:
		static Keyboard& getKeyboard();
		bool pressed(int key, int edge);
		bool pressing(int key);

	private:
		friend Window;
		std::vector<glKeyboardEvent> keyboard_events;

		Keyboard()  {};
		~Keyboard() {};
		void reset();
		void pushKeyEvent(glKeyboardEvent& key_event);

		Keyboard(const Keyboard& other)              = delete;
		Keyboard(Keyboard&& other)                   = delete;
		Keyboard& operator = (const Keyboard& other) = delete;
		Keyboard& operator = (Keyboard&& other)      = delete;
	};

	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window();
		static Vec2i size();
		void vSync(bool vsync);
		bool isOpen();
		void pollEvents();
		void clear(Color color);
		void draw(const Mesh& mesh, Camera& camera);
		void display();

	private:
		friend Mouse;
		friend Keyboard;
		inline static GLFWwindow* window_ptr = nullptr;
		
		static GLFWwindow* getGLFWptr();
		static void callBackWindowResize(GLFWwindow* window_ptr, int width, int height);
		static void callBackKeyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods);
		static void callBackMouse(GLFWwindow* window_ptr, int button, int action, int mods);
		static void callBackMouseScroll(GLFWwindow* window_ptr, double xoffset, double yoffset);
		
		Window(const Window& other)              = delete;
		Window(Window&& other)                   = delete;
		Window& operator = (const Window& other) = delete;
		Window& operator = (Window&& other)      = delete;
	};
}

