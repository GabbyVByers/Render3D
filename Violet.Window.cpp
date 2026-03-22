
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
	io.FontGlobalScale = 1.0f;
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

Violet::Vec2i Violet::Window::size() {
	int x, y; glfwGetFramebufferSize(window_ptr, &x, &y);
	return { x, y };
}

void Violet::Window::vSync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

bool Violet::Window::isOpen() {
	return !glfwWindowShouldClose(window_ptr);
}

void Violet::Window::pollEvents() {
	Mouse::getMouse().reset();
	Keyboard::getKeyboard().reset();
	glfwPollEvents();
}

void Violet::Window::clear(Violet::Color color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Violet::Window::draw(const Mesh& mesh, Camera& camera) {
	const GLuint vao = mesh.vao;
	const GLuint vbo = mesh.vbo;
	const GLuint shader = mesh.shader;
	const std::vector<Vertex>& vertices = mesh.vertices;

	if (vertices.size() == 0)
		return;

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glUseProgram(shader);

	Mat4 model_matrix = mesh.modelMatrix();
	Mat4 view_matrix  = camera.viewMatrix();
	Mat4 projection_matrix = camera.projectionMatrix(Window::size());

	Mat4 model_view_project = projection_matrix * view_matrix * model_matrix;
	Mat4f mvp_float = Math::floatMatrix(model_view_project);
	glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewProject"), 1, GL_TRUE, &mvp_float.data[0][0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);
	glDrawArrays(mesh.primative_type, 0, (GLsizei)vertices.size());
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window_ptr);
}

GLFWwindow* Violet::Window::getGLFWptr() {
	return window_ptr;
}

void Violet::Window::callBackWindowResize(GLFWwindow* window_ptr, int width, int height) {
	glViewport(0, 0, width, height);
}

void Violet::Window::callBackKeyboard(GLFWwindow* window_ptr, int key, int scancode, int action, int mods) {
	glKeyboardEvent key_event = {
		key,
		scancode,
		action,
		mods
	};
	Keyboard& keyboard = Keyboard::getKeyboard();
	keyboard.pushKeyEvent(key_event);
}

void Violet::Window::callBackMouse(GLFWwindow* window_ptr, int button, int action, int mods) {
	glMouseEvent mouse_event = {
		button,
		action,
		mods
	};
	Mouse& mouse = Mouse::getMouse();
	mouse.pushMouseEvent(mouse_event);
}

void Violet::Window::callBackMouseScroll(GLFWwindow* window_ptr, double xoffset, double yoffset) {
	glScrollEvent scroll_event{
		xoffset,
		yoffset
	};
	Mouse& mouse = Mouse::getMouse();
	mouse.pushScrollEvent(scroll_event);
}

