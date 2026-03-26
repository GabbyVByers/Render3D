
#include "Mesh.h"
#include <fstream>
#include <sstream>

Violet::Mesh::Mesh(const std::string& path, GLenum type) {
	primative_type = type;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(vao);//?
	glBindBuffer(GL_ARRAY_BUFFER, vbo);//?
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);//?

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	auto load = [](std::string path) -> std::string {
		std::ifstream file(path);
		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	};

	std::string vert_source = load(path + ".vert");
	std::string frag_source = load(path + ".frag");
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
	glGetShaderiv(shader, GL_LINK_STATUS, &success);
	if (!success)
		std::terminate();
}

Violet::Mesh::~Mesh() {
	glDeleteProgram(shader);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	glDeleteVertexArrays(1, &vao);
}

