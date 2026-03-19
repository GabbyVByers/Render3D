
#include "Math.h"

Violet::Matrix Violet::Transformation::modelMatrix() const {
	Matrix scalar_matrix      = Matrix::buildScalarMatrix(scale);
	Matrix translation_matrix = Matrix::buildTranslationMatrix(position);
	Matrix rotation_matrix    = Matrix::buildRotationMatrix(orientation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

Violet::Matrix Violet::Transformation::viewMatrix() const {
	Matrix translation_matrix_inverse = Matrix::buildTranslationMatrix(position);
	Matrix rotation_matrix_inverse    = Matrix::buildRotationMatrix(Quaternion::complexConjugate(orientation));
	return rotation_matrix_inverse * translation_matrix_inverse;
}

