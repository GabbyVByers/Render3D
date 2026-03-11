
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

#define Violet Violet
namespace Violet {
	class Vertex {
	public:
		Math::float3 position;
		Math::float4 color;
	};

	class Camera {
	public:

	};

	class Mesh {
	public:
		GLuint vao;
		GLuint vbo;
		GLuint shader;
		Math::Trans trans;
		GLenum primative_type;
		std::vector<Vertex> vertices;
		void create(const std::string& path = "default", GLenum type = GL_TRIANGLES);
		void destroy();
	};

	class Window {
	public:
		Window()  = delete;
		~Window() = delete;

		static void create(std::string title, int width, int height) {
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			window_ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(window_ptr);
			gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			glViewport(0, 0, width, height);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_PROGRAM_POINT_SIZE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glfwSetFramebufferSizeCallback(window_ptr, callBackWindowResize);
			glfwSetKeyCallback(window_ptr, callBackKeyboard);
			glfwSetMouseButtonCallback(window_ptr, callBackMouse);
			glfwSetScrollCallback(window_ptr, callBackMouseScroll);

			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.FontGlobalScale = 2.0f;
			io.IniFilename = nullptr;
			ImGui::StyleColorsDark();
			ImGui_ImplGlfw_InitForOpenGL(window_ptr, true);
			ImGui_ImplOpenGL3_Init("#version 330");
		}

		static void destroy() {
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			ImGui::DestroyContext();
			glfwDestroyWindow(window_ptr);
			glfwTerminate();
		}

		static void pollEvents() {
			glfwPollEvents();
		}

		static void draw(const Mesh& mesh, Camera& camera) {
			const GLuint vao    = mesh.vao;
			const GLuint vbo    = mesh.vbo;
			const GLuint shader = mesh.shader;

			glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glUseProgram(shader);
		}

		static bool isOpen() {
			return true;
		}

	private:
		inline static GLFWwindow* window_ptr = nullptr;

		static void callBackWindowResize(GLFWwindow* window_ptr, int width, int height);
		static void callBackKeyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods);
		static void callBackMouse(GLFWwindow* window_ptr, int button, int action, int mods);
		static void callBackMouseScroll(GLFWwindow* window_ptr, double xoffset, double yoffset);
	};
}

