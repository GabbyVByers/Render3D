
/*
	Mesh.h
*/

#pragma once
#include "Types.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Violet {

	class Camera;
	class Material;
	class Transform;
	class Texture;
	class Vertex;
	class Mesh;

	class Camera {
	public:
		double far         = 100.0f;
		double near        = 0.01f;
		double fov_degrees = 70.0f;
		Vec3d  position    = Vec3d();
		Quat   orientation = Quat();

		Camera()  = default;
		~Camera() = default;
		Vec3d forward() const;
		Vec3d up() const;
		Vec3d right() const;
		Mat4  view_matrix() const;
		Mat4  projection_matrix(const Vec2i& window_size) const;
	};

	class Material {
	public:
		GLuint vao       = NULL;
		GLuint vbo       = NULL;
		GLuint shader    = NULL;
		GLenum primitive = NULL;

		Material()  = default;
		~Material() = default;
		Material(const Material& other) = delete;
		Material(Material&& other) noexcept;
		Material& operator = (const Material& other) = delete;
		Material& operator = (Material&& other) noexcept;
		static Material init(const std::string& path, GLenum type);
	};

	class Transform {
	public:
		double scale       = 1.0;
		Vec3d  position    = Vec3d();
		Quat   orientation = Quat();
		Mat4   model_matrix() const;
	};

	class Texture {
	public:
		GLuint texture = NULL;
		Texture() = default;
		~Texture();
		Texture(Texture&& other) noexcept;
		Texture(const Texture& other) = delete;
		Texture& operator = (Texture&& other) noexcept;
		Texture& operator = (const Texture& other) = delete;
		Texture init(const std::string& path = "default_no_texture");
	};

	class Vertex {
	public:
		Vec3f position = Vec3f();
		Color color = Color::white();
		Vec2f tex_coord = Vec2f();
		Vertex() = default;
		Vertex(const Vec3f& position, const Color& color, const Vec2f& tex_coord);
	};

	class Window;
	class Mesh {
	public:
		Material material = Material("default", GL_TRIANGLES);
		Transform transform = Transform();
		Texture texture = Texture();
		std::vector<Vertex> vertices = std::vector<Vertex>();
		Mesh() = default;
		void paint(const Color& color);
	};
}

