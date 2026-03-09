
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

#define Violet Violet
#define Vi Violet

namespace Violet {
	constexpr double Pi64 = 3.1415926535897932;
	constexpr float  Pi32 = 3.14159265f;


	class Window {
	public:
		Window()  = delete;
		~Window() = delete;

		static void createGLFWContext(std::string title, size_t width, size_t height) {
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			glfwWindowPtr = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(glfwWindowPtr);
			gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
			glViewport(0, 0, (GLsizei)width, (GLsizei)height);
			glEnable(GL_DEPTH_TEST);

			glfwSetFramebufferSizeCallback(glfwWindowPtr, callBackWindowResize);
			glfwSetKeyCallback(glfwWindowPtr, callBackKeyboard);
			glfwSetMouseButtonCallback(glfwWindowPtr, callBackMouse);
			glfwSetScrollCallback(glfwWindowPtr, callBackMouseScroll);
			isGLFWContextValid = true;
		}

		static void destroyGLFWContext() {
			isGLFWContextValid = false;
		}

		static bool isOpen() {
			assert(isGLFWContextValid);
			return true;
		}

	private:
		// STATE
		inline static GLFWwindow* glfwWindowPtr = nullptr;
		inline static bool isGLFWContextValid   = false;

		// CALL BACK
		static void callBackWindowResize(GLFWwindow* glfwWindow, int32_t width, int32_t height);
		static void callBackKeyboard(GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mods);
		static void callBackMouse(GLFWwindow* window, int32_t button, int32_t action, int32_t mods);
		static void callBackMouseScroll(GLFWwindow* window, double xoffset, double yoffset);
	};

}

