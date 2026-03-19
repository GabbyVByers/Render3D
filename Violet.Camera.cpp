
#include "Violet.h"

Violet::Camera::Camera() {
	fov_degrees = 100.0;
	near = 0.1;
	far = 100.0;
}

Violet::Matrix Violet::Camera::buildProjectionMatrix(const Camera& camera, const Vec2i& window_size) {
	int width = window_size.x;
	int height = window_size.y;
	if (height == 0)
		height = 1;
	double aspect_ratio = (double)width / (double)height;
	double fov_radians = camera.fov_degrees * Pi64 / 180.0;
	double f = 1.0 / tan(fov_radians / 2.0);
	Matrix projectionMatrix = {
		f / aspect_ratio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (camera.far + camera.near) / (camera.near - camera.far),
		(2.0 * camera.far * camera.near) / (camera.near - camera.far),
		0.0, 0.0, -1.0, 0.0
	};
	return projectionMatrix;
}

