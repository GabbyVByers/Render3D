
#pragma once
#include "Vec2.h"
#include "Vec3.h"
#include "Quat.h"

namespace Violet {
	namespace Math {

		constexpr double Pi64 = 3.141592653589793;
		constexpr float  Pi32 = 3.1415927f;

		int    dot(const Vec2i& a, const Vec2i& b);
		float  dot(const Vec2f& a, const Vec2f& b);
		double dot(const Vec2d& a, const Vec2d& b);
		int    dot(const Vec3i& a, const Vec3i& b);
		float  dot(const Vec3f& a, const Vec3f& b);
		double dot(const Vec3d& a, const Vec3d& b);
		
		Vec3i  cross(const Vec3i& a, const Vec3i& b);
		Vec3f  cross(const Vec3f& a, const Vec3f& b);
		Vec3d  cross(const Vec3d& a, const Vec3d& b);
		
		double hypot(const Vec2i& vec);
		double hypot(const Vec2f& vec);
		double hypot(const Vec2d& vec);
		double hypot(const Vec3i& vec);
		double hypot(const Vec3f& vec);
		double hypot(const Vec3d& vec);
		
		Vec2f  normalize(const Vec2f& vec);
		Vec2d  normalize(const Vec2d& vec);
		Vec3f  normalize(const Vec3f& vec);
		Vec3d  normalize(const Vec3d& vec);
		Vec3f  rotate_vec3f_around_vec3i(const Vec3f& vec, const Vec3i& axis, float  theta);
		Vec3f  rotate_vec3f_around_vec3f(const Vec3f& vec, const Vec3f& axis, float  theta);
		Vec3d  rotate_vec3d_around_vec3i(const Vec3d& vec, const Vec3i& axis, double theta);
		Vec3d  rotate_vec3d_around_vec3d(const Vec3d& vec, const Vec3d& axis, double theta);
		Vec3f  apply_quat_rotation_vec3f(const Vec3f& vec, const Quat& rotation_quat);
		Vec3d  apply_quat_rotation_vec3d(const Vec3d& vec, const Quat& rotation_quat);
		
		Quat normalize(const Quat& quat);
		Quat complex_conjugate(const Quat& quat);
		Quat rotation_quat_vec3i(const Vec3i& axis, double theta);
		Quat rotation_quat_vec3f(const Vec3f& axis, double theta);
		Quat rotation_quat_vec3d(const Vec3d& axis, double theta);
	}
}

