
#include "Camera.h"
#include <cmath>

Violet::Camera::Camera() {
	fov_degrees = 100.0;
	near = 0.1; far = 100.0;
	position = Vec3d(0.0, 0.0, 0.0);
}

Violet::Vec3d Violet::Camera::forward_dir(const Camera& camera) {
	Vec3d forward = Vec3d(0.0, 0.0, -1.0);
	return Math::apply_quat_rotation_vec3d(forward, camera.orientation);
}

Violet::Vec3d Violet::Camera::up_dir(const Camera& camera) {
	Vec3d up = Vec3d(0.0, 1.0, 0.0);
	return Math::apply_quat_rotation_vec3d(up, camera.orientation);
}

Violet::Vec3d Violet::Camera::right_dir(const Camera& camera) {
	Vec3d right = Vec3d(1.0, 0.0, 0.0);
	return Math::apply_quat_rotation_vec3d(right, camera.orientation);
}

