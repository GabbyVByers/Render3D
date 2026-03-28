
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

			Mesh bounding_box(const Color& color);
			//Mesh arrow();
		}
	};
}

