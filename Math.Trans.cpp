
#include "Math.h"

Math::double4x4 Math::Trans::modelMatrix() const {
	double4x4 scalar_matrix = double4x4(scale);
	double4x4 translation_matrix = double4x4(position);
	double4x4 rotation_matrix = double4x4(rotation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

Math::double4x4 Math::Trans::viewMatrix() const {
	double4x4 translation_matrix_inverse = double4x4(position);
	double4x4 rotation_matrix_inverse = double4x4(rotation.complexConjugate());
	return rotation_matrix_inverse * translation_matrix_inverse;
}

