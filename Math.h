
#pragma once
#include "Vec2.h"
#include "Vec3.h"
#include "Matrix.h"
#include "Quaternion.h"

namespace Violet {
	namespace Math {

		double hypot(const Vec2i& vec);
		double hypot(const Vec2f& vec);
		double hypot(const Vec2d& vec);
		double hypot(const Vec3i& vec);
		double hypot(const Vec3f& vec);
		double hypot(const Vec3d& vec);

		Vec2i normalize(const Vec2i& vec);
		Vec2f normalize(const Vec2f& vec);
		Vec2d normalize(const Vec2d& vec);
		Vec3i normalize(const Vec3i& vec);
		Vec3f normalize(const Vec3f& vec);
		Vec3d normalize(const Vec3d& vec);

		double dot(const Vec2i& a, const Vec3i& b);
		double dot(const Vec2f& a, const Vec3f& b);
		double dot(const Vec2d& a, const Vec3d& b);
		double dot(const Vec3i& a, const Vec3i& b);
		double dot(const Vec3f& a, const Vec3f& b);
		double dot(const Vec3d& a, const Vec3d& b);

		Vec3i cross(const Vec3i& a, const Vec3i& b);
		Vec3f cross(const Vec3f& a, const Vec3f& b);
		Vec3d cross(const Vec3d& a, const Vec3d& b);

		Vec3d rotate(const Vec3d& vec, const Vec3d& axis, double theta);
		Vec3d rotate(const Vec3d& vec, const Quaternion& rotation_quat);

		Mat4 scalarMatrix(double scale);
		Mat4 translationMatrix(const Vec3d& position);
		Mat4 rotationMatrix(const Quaternion& rotation);

		Quaternion normalize(const Vec3d& vec);
		Quaternion rotationQuaternion();
		Quaternion complexConjugate();
	}
}

