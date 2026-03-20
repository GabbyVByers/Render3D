
#include "Camera.h"
#include "Vector.h"
#include "Matrix.h"
#include "Quaternion.h"
#include <cmath>

Violet::Camera::Camera() {
	fov_degrees = 100.0;
	near = 0.1;
	far = 100.0;
}

Violet::Vec3d Violet::Camera::forwardDirection() const {
	Vec3d forward = Vec3d(0.0, 0.0, -1.0);
	forward.rotate(orientation);
	return forward;
}

Violet::Vec3d Violet::Camera::upDirection() const {
	Vec3d up = Vec3d(0.0, 1.0, 0.0);
	up.rotate(orientation);
	return up;
}

Violet::Vec3d Violet::Camera::rightDirection() const {
	Vec3d right = Vec3d(1.0, 0.0, 0.0);
	right.rotate(orientation);
	return right;
}

Violet::Matrix Violet::Camera::viewMatrix() const {
	Matrix translation_matrix_inverse = Matrix::buildTranslationMatrix(position);
	Matrix rotation_matrix_inverse    = Matrix::buildRotationMatrix(Quaternion::complexConjugate(orientation));
	return rotation_matrix_inverse * translation_matrix_inverse;
}

Violet::Matrix Violet::Camera::projectionMatrix(const Vec2i& window_size) const {
	int width = window_size.x;
	int height = window_size.y;
	if (height == 0)
		height = 1;
	double aspect_ratio = (double)width / (double)height;
	double fov_radians = fov_degrees * Pi64 / 180.0;
	double f = 1.0 / tan(fov_radians / 2.0);
	Matrix projectionMatrix = {
		f / aspect_ratio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (far + near) / (near - far),
		(2.0 * far * near) / (near - far),
		0.0, 0.0, -1.0, 0.0
	};
	return projectionMatrix;
}

