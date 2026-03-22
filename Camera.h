
#pragma once
#include "Math.h"

namespace Violet {
	constexpr double Pi64 = 3.141592653589793;
	constexpr float  Pi32 = 3.1415927f;

	class Camera {
	public:
		double     fov_degrees;
		double     near, far;
		Vec3d      position;
		Quaternion orientation;

		Camera();
		Vec3d forwardDirection() const;
		Vec3d upDirection() const;
		Vec3d rightDirection() const;
		Mat4 viewMatrix() const;
		Mat4 projectionMatrix(const Vec2i& window_size) const;
	};
}

