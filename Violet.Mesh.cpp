
#include "Violet.h"
#include <fstream>
#include <sstream>

Violet::Mesh::Mesh() {
	this->scale = 1.0;
	this->position = Vec3d(0.0, 0.0, 0.0);
	this->orientation = Quat();
	this->vertices = std::vector<Vertex>();
	this->vao = NULL;
	this->vbo = NULL;
	this->shader = NULL;
	this->primative_type = NULL;
}

void Violet::Mesh::create(const std::string& path, GLenum type) {
	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &this->vbo);
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	this->primative_type = type;

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

	this->shader = glCreateProgram();
	glAttachShader(this->shader, vert_program);
	glAttachShader(this->shader, frag_program);
	glLinkProgram(this->shader);
	glDeleteShader(vert_program);
	glDeleteShader(frag_program);
	glGetProgramiv(this->shader, GL_LINK_STATUS, &success);
	if (!success)
		std::terminate();
}

void Violet::Mesh::destroy() {
	glDeleteProgram(this->shader);
	glDeleteBuffers(1, &this->vbo);
	glDeleteVertexArrays(1, &this->vao);
	this->shader = NULL;
	this->vbo = NULL;
	this->vao = NULL;
}

