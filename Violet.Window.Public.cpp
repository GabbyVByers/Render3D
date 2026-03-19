
#include "Violet.h"

void Violet::Window::vSync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

Violet::Vec2i Violet::Window::size() {
	int x, y; glfwGetFramebufferSize(window_ptr, &x, &y);
	return { x, y };
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
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glUseProgram(shader);
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window_ptr);
}

