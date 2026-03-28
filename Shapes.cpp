
/*
	Shapes.cpp
*/

#include "Shapes.h"

namespace Violet {

	Mesh Shapes::arrow() {
		return Mesh();
	}

	Mesh Shapes::cube(unsigned int divisions) {
		return Mesh();
	}

	Mesh Shapes::sphere(unsigned int divisions) {
		// always radius = 1 (in vertex positions)
		// change mesh scale to change size
		// this method is maximally precision preserving

		Mesh sphere_mesh;
		sphere_mesh.material = Material("default", GL_TRIANGLES);

		for (size_t i = 0; i < (size_t)divisions + 1; i++) {
			for (size_t j = 0; j < (size_t)divisions + 1; j++) {

			}
		}

		return sphere_mesh;
	}

	namespace Immediate {

		void bounding_box(const Mesh& mesh, const Color& color) {
			// todo: draws an axis aligned bounding box around a mesh w/ given color
		}
	}
}

