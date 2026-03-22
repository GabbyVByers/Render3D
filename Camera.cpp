
#include "Camera.h"
#include <cmath>

Violet::Camera::Camera() {
	fov_degrees = 100.0;
	near = 0.1;
	far = 100.0;
}

Violet::Vec3d Violet::Camera::forwardDirection() const {
	Vec3d forward = Vec3d(0.0, 0.0, -1.0);
	return Math::applyQuaternionRotation(forward, orientation);
}

Violet::Vec3d Violet::Camera::upDirection() const {
	Vec3d up = Vec3d(0.0, 1.0, 0.0);
	return Math::applyQuaternionRotation(up, orientation);
}

Violet::Vec3d Violet::Camera::rightDirection() const {
	Vec3d right = Vec3d(1.0, 0.0, 0.0);
	return Math::applyQuaternionRotation(right, orientation);
}

Violet::Mat4 Violet::Camera::viewMatrix() const {
	Mat4 translation_matrix_inverse = Math::translationMatrix(position);
	Mat4 rotation_matrix_inverse    = Math::rotationMatrix(Math::complexConjugate(orientation));
	return rotation_matrix_inverse * translation_matrix_inverse;
}

Violet::Mat4 Violet::Camera::projectionMatrix(const Vec2i& window_size) const {
	int width = window_size.x;
	int height = window_size.y;
	if (height == 0)
		height = 1;
	double aspect_ratio = (double)width / (double)height;
	double fov_radians = fov_degrees * Math::Pi64 / 180.0;
	double f = 1.0 / tan(fov_radians / 2.0);
	Mat4 projectionMatrix = {
		f / aspect_ratio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (far + near) / (near - far),
		(2.0 * far * near) / (near - far),
		0.0, 0.0, -1.0, 0.0
	};
	return projectionMatrix;
}

