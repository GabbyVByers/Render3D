
#include "Math.h"

Violet::Matrix Violet::Transformation::buildModelMatrix(const Transformation& trans) {
	Matrix scalar_matrix      = Matrix::buildScalarMatrix(trans.scale);
	Matrix translation_matrix = Matrix::buildTranslationMatrix(trans.position);
	Matrix rotation_matrix    = Matrix::buildRotationMatrix(trans.orientation);
	return translation_matrix * scalar_matrix * rotation_matrix;
}

Violet::Matrix Violet::Transformation::buildViewMatrix(const Transformation& trans) {
	Matrix translation_matrix_inverse = Matrix::buildTranslationMatrix(trans.position);
	Matrix rotation_matrix_inverse    = Matrix::buildRotationMatrix(Quaternion::complexConjugate(trans.orientation));
	return rotation_matrix_inverse * translation_matrix_inverse;
}

