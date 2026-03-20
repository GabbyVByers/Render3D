
#pragma once
#include "Core.h"

namespace Violet {
	class Shape {
	public:
		Shape()  = delete;
		~Shape() = delete;
		
		static Mesh testTriangle() {
			Mesh triangle("default", GL_TRIANGLES);
			triangle.vertices.push_back({ Vec3f(-0.5, 0.5, 0.0), Color::random() });
			triangle.vertices.push_back({ Vec3f(-0.5,-0.5, 0.0), Color::random() });
			triangle.vertices.push_back({ Vec3f( 0.5, 0.0, 0.0), Color::random() });
			return triangle;
		}

		static Mesh sphere() {
			Mesh sphere("default", GL_TRIANGLES);
			return sphere;
		}

	private:
		// helper funcs
	};


}

