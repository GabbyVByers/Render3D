
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include "Core.h"
#include "Vector.h"
#include "Quaternion.h"

namespace Violet {
	class Color {
	public:
		float r, g, b, a;
		Color();
		Color(float r, float g, float b, float a = 1.0f);
		static Color random();
		static Color white();
		static Color black();
		static Color red();
		static Color green();
		static Color blue();
		static Color cyan();
		static Color purple();
		static Color yellow();
	};

	class Vertex {
	public:
		Vec3f position;
		Color color;
	};

	class Mesh {
	public:
		double     scale;
		Vec3d      position;
		Quaternion orientation;
		std::vector<Vertex> vertices;

		Mesh(const std::string& path, GLenum type);
		~Mesh();
		Matrix modelMatrix() const;

	private:
		friend Window;
		GLuint vao, vbo, shader;
		GLenum primative_type;
	};
}

