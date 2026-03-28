
/*
	Shapes.h
*/

#pragma once
#include "Mesh.h"

namespace Violet {
	namespace Shapes {

		Mesh arrow();
		Mesh cube(unsigned int divisions);
		Mesh sphere(unsigned int divisions);

		namespace Immediate {

			void bounding_box(const Mesh& mesh, const Color& color);
			//Mesh arrow();
		}
	};
}

