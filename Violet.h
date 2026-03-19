
#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include "Math.h"

namespace Violet {

	class Color;
	class Vertex;
	class Camera;
	class Mesh;
	class glMouseEvent;
	class glScrollEvent;
	class glKeyboardEvent;
	class Mouse;
	class Keyboard;
	class Window;

	class Color {
	public:
		float r, g, b, a;
		Color();
		Color(float r, float g, float b, float a = 1.0f);
		static Color random();
		static Color white();
		static Color black();
		static Color red();
		static Color green();
		static Color blue();
		static Color cyan();
		static Color purple();
		static Color yellow();
	};

	class Vertex {
	public:
		Vec3f position;
		Color color;
	};

	class Camera {
	public:
		double fov_degrees, near, far;
		Vec3d position;
		Quaternion orientation;
		Camera();
		Matrix buildViewMatrix() const;
		Matrix buildProjectionMatrix(const Vec2i& window_size) const;
	};

	class Mesh {
	public:
		double scale;
		Vec3d position;
		Quaternion orientation;
		std::vector<Vertex> vertices;
		Mesh(const std::string& path = "default", GLenum type = GL_TRIANGLES);
		~Mesh();
		Matrix buildModelMatrix() const;
		void cube(double radius, int divisions);
		void sphere(double radius, int divisions);

	private:
		friend Window;
		GLuint vao, vbo, shader;
		GLenum primative_type;
	};

	class glMouseEvent {
	public:
		int button, action, mods;
	};

	class glScrollEvent {
	public:
		double xoffset, yoffset;
	};

	class glKeyboardEvent {
	public:
		int key, scancode, action, mods;
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
		Mouse() {};
		~Mouse() {};
		void reset();
		void pushMouseEvent(glMouseEvent mouse_event);
		void pushScrollEvent(glScrollEvent scroll_event);
		Vec2d pos, vel;
		std::vector<glMouseEvent> mouse_events;
		std::vector<glScrollEvent> scroll_events;
	};

	class Keyboard {
	public:
		static Keyboard& getKeyboard();
		bool pressed(int key, int edge);
		bool pressing(int key);

	private:
		friend Window;
		Keyboard() {};
		~Keyboard() {};
		void reset();
		void pushKeyEvent(glKeyboardEvent& key_event);
		std::vector<glKeyboardEvent> keyboard_events;
	};

	class Window {
	public:
		Window(std::string title, int width, int height);
		~Window();
		Window(const Window& other)              = delete;
		Window(Window&& other)                   = delete;
		Window& operator = (const Window& other) = delete;
		Window& operator = (Window&& other)      = delete;
		static Vec2i getDisplaySize();
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
	};
}

