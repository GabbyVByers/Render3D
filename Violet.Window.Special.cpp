
#include "Violet.h"

Violet::Window::Window(std::string title, int width, int height) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (window_ptr != nullptr)
		std::terminate();
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

Violet::Window::~Window() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window_ptr);
	window_ptr = nullptr;
	glfwTerminate();
}

