
#pragma once
#include <vector>
#include <string>
#include "Corelib.h"
#include "Color.h"
#include "QuatMath.h"

namespace Violet {

	class Vertex;
	class Mesh;

	class Vertex {
	public:
		Vec3f position;
		Color color;
	};

	class Mesh {
	public:
		double scale     = 1.0;
		Vec3d position   = Vec3d(0.0, 0.0, 0.0);
		Quat orientation = Quat();
		std::vector<Vertex> vertices = std::vector<Vertex>();
		std::vector<unsigned int> indices = std::vector<unsigned int>();
		GLuint vao            = NULL;
		GLuint vbo            = NULL;
		GLuint ebo            = NULL;
		GLuint shader         = NULL;
		GLenum primative_type = NULL;

		Mesh(const std::string& path, GLenum type);
		~Mesh();
	};
}

