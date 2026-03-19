
#include "Violet.h"

static std::string loadFileAsString(std::string file_path) {
	std::ifstream file(file_path);
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

	GLuint frag_program = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_program, 1, &frag_c_str, nullptr);
	glCompileShader(frag_program);

	shader = glCreateProgram();
	glAttachShader(shader, vert_program);
	glAttachShader(shader, frag_program);
	glLinkProgram(shader);
	glDeleteShader(vert_program);
	glDeleteShader(frag_program);
}

Violet::Mesh::~Mesh() {
	glDeleteProgram(shader);
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

Violet::Matrix Violet::Mesh::buildModelMatrix() const {
	Matrix scalar_matrix      = Matrix::buildScalarMatrix(scale);
	Matrix translation_matrix = Matrix::buildTranslationMatrix(position);
	Matrix rotation_matrix    = Matrix::buildRotationMatrix(orientation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

