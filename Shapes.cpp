
#include "Shapes.h"

Violet::Mesh Violet::Shapes::sphere(unsigned int divisions) {
	// always radius = 1 (in vertex positions)
	// change mesh scale to change size
	// this method is maximally precision preserving

	Mesh sphere_mesh("default", GL_TRIANGLES);


	for (size_t i = 0; i < divisions; i++) {

	}



	return sphere_mesh;
}

