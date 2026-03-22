
#include "Violet.h"
#include <fstream>
#include <sstream>

static std::string loadFileAsString(std::string file_path) {
	std::ifstream file(file_path);
	if (!file.is_open())
		std::terminate();
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

Violet::Mesh::Mesh(const std::string& path, GLenum type) {
	scale = 1.0;
	primative_type = type;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	std::string vert_source = loadFileAsString(path + ".vert");
	std::string frag_source = loadFileAsString(path + ".frag");
	const char* vert_c_str = vert_source.c_str();
	const char* frag_c_str = frag_source.c_str();

	GLuint vert_program = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_program, 1, &vert_c_str, nullptr);
	glCompileShader(vert_program);
	GLint success;
	glGetProgramiv(vert_program, GL_LINK_STATUS, &success);
	if (!success)
		std::terminate();

	GLuint frag_program = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_program, 1, &frag_c_str, nullptr);
	glCompileShader(frag_program);
	glGetProgramiv(frag_program, GL_LINK_STATUS, &success);
	if (!success)
		std::terminate();

	shader = glCreateProgram();
	glAttachShader(shader, vert_program);
	glAttachShader(shader, frag_program);
	glLinkProgram(shader);
	glDeleteShader(vert_program);
	glDeleteShader(frag_program);
	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success)
		std::terminate();
}

Violet::Mesh::~Mesh() {
	glDeleteProgram(shader);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

Violet::Mat4 Violet::Mesh::modelMatrix() const {
	Mat4 scalar_matrix      = Math::scalarMatrix(scale);
	Mat4 translation_matrix = Math::translationMatrix(position);
	Mat4 rotation_matrix    = Math::rotationMatrix(orientation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

