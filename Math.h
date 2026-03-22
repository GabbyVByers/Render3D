
#pragma once
#include "Vec2.h"
#include "Vec3.h"
#include "Mat4.h"
#include "Quaternion.h"

namespace Violet {
	namespace Math {

		double hypot(const Vec2i& vec);
		double hypot(const Vec2f& vec);
		double hypot(const Vec2d& vec);
		double hypot(const Vec3i& vec);
		double hypot(const Vec3f& vec);
		double hypot(const Vec3d& vec);

		Vec2f normalize(const Vec2f& vec);
		Vec2d normalize(const Vec2d& vec);
		Vec3f normalize(const Vec3f& vec);
		Vec3d normalize(const Vec3d& vec);

		int    dot(const Vec2i& a, const Vec2i& b);
		float  dot(const Vec2f& a, const Vec2f& b);
		double dot(const Vec2d& a, const Vec2d& b);
		int    dot(const Vec3i& a, const Vec3i& b);
		float  dot(const Vec3f& a, const Vec3f& b);
		double dot(const Vec3d& a, const Vec3d& b);

		Vec3i cross(const Vec3i& a, const Vec3i& b);
		Vec3f cross(const Vec3f& a, const Vec3f& b);
		Vec3d cross(const Vec3d& a, const Vec3d& b);

		Vec3f rotateAroundAxis(const Vec3f& vec, const Vec3i& axis, float  theta);
		Vec3f rotateAroundAxis(const Vec3f& vec, const Vec3f& axis, float  theta);
		Vec3d rotateAroundAxis(const Vec3d& vec, const Vec3i& axis, double theta);
		Vec3d rotateAroundAxis(const Vec3d& vec, const Vec3d& axis, double theta);
		Vec3f applyQuaternionRotation(const Vec3f& vec, const Quaternion& rotation_quat);
		Vec3d applyQuaternionRotation(const Vec3d& vec, const Quaternion& rotation_quat);

		Quaternion normalize(const Quaternion& quat);
		Quaternion complexConjugate(const Quaternion& quat);
		Quaternion rotationQuaternion(const Vec3i& axis, double theta);
		Quaternion rotationQuaternion(const Vec3f& axis, double theta);
		Quaternion rotationQuaternion(const Vec3d& axis, double theta);

		Mat4 scalarMatrix(double scale);
		Mat4 translationMatrix(const Vec3d& position);
		Mat4 rotationMatrix(const Quaternion& rotation);
		Mat4f floatMatrix(const Mat4& matrix);
	}
}

