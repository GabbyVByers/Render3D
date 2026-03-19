
#include "Violet.h"

Violet::Vec2i Violet::Window::getDisplaySize() {
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

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glUseProgram(shader);

	Matrix model_matrix = Transformation::buildModelMatrix(mesh.trans);
	Matrix view_matrix  = Transformation::buildViewMatrix(camera.trans);
	Matrix projection_matrix = Camera::buildProjectionMatrix(camera, Window::getDisplaySize());

	Matrix model_view_project = projection_matrix * view_matrix * model_matrix;
	Matrix_f mvp_float(model_view_project);
	glUniformMatrix4fv(glGetUniformLocation(shader, "uModelViewProject"), 1, GL_FALSE, &mvp_float.data[0][0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);
	glDrawArrays(mesh.primative_type, 0, (GLsizei)vertices.size());
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window_ptr);
}

