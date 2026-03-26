
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
		double scale;
		Vec3d position;
		Quat orientation;
		std::vector<Vertex> vertices;
		GLuint vao;
		GLuint vbo;
		GLuint shader;
		GLenum primative_type;

		Mesh();
		// Move create/destroy to Mesh()/~Mesh()
		// delete the other 4 special member functions
		void create(const std::string& path, GLenum type);
		void destroy();
	};
}

