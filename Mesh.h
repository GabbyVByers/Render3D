
#pragma once
#include <vector>
#include <string>
#include "Corelib.h"
#include "Color.h"
#include "QuatMath.h"

namespace Violet {

	class Vertex;
	class Transform;
	class Material;
	class Mesh;

	class Vertex {
	public:
		Vec3f position = Vec3f();
		Color color    = Color::white();
	};

	class Transform {
	public:
		double scale     = 1.0;
		Vec3d position   = Vec3d();
		Quat orientation = Quat();
	};

	class Material {
	public:
		GLuint vao       = NULL;
		GLuint vbo       = NULL;
		GLuint ebo       = NULL;
		GLuint shader    = NULL;
		GLenum primitive = NULL;
		Material(const std::string& path, GLenum type);
		~Material();
		Material(Material&& other) noexcept;                   // Move Constructor
		Material(const Material& other) = delete;              // Copy Constructor
		Material& operator = (Material&& other) noexcept;      // Move Assignment
		Material& operator = (const Material& other) = delete; // Copy Assignment
	};

	class Mesh {
	public:
		Material material = Material("default", GL_TRIANGLES);
		Transform transform = Transform();
		std::vector<Vertex> vertices = std::vector<Vertex>();
		std::vector<unsigned int> indices = std::vector<unsigned int>();
	};
}

