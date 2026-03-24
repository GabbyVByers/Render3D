
#include "VecMath.h"
#include <cmath>

double Violet::Math::hypot(const Vec2i& vec) { return std::hypot(vec.x, vec.y); }
double Violet::Math::hypot(const Vec2f& vec) { return std::hypot(vec.x, vec.y); }
double Violet::Math::hypot(const Vec2d& vec) { return std::hypot(vec.x, vec.y); }
double Violet::Math::hypot(const Vec3i& vec) { return std::hypot(vec.x, vec.y, vec.z); }
double Violet::Math::hypot(const Vec3f& vec) { return std::hypot(vec.x, vec.y, vec.z); }
double Violet::Math::hypot(const Vec3d& vec) { return std::hypot(vec.x, vec.y, vec.z); }

Violet::Vec2f Violet::Math::normalize(const Vec2f& vec) { return vec / hypot(vec); }
Violet::Vec2d Violet::Math::normalize(const Vec2d& vec) { return vec / hypot(vec); }
Violet::Vec3f Violet::Math::normalize(const Vec3f& vec) { return vec / hypot(vec); }
Violet::Vec3d Violet::Math::normalize(const Vec3d& vec) { return vec / hypot(vec); }

int    Violet::Math::dot(const Vec2i& a, const Vec2i& b) { return (a.x * b.x) + (a.y * b.y); }
float  Violet::Math::dot(const Vec2f& a, const Vec2f& b) { return (a.x * b.x) + (a.y * b.y); }
double Violet::Math::dot(const Vec2d& a, const Vec2d& b) { return (a.x * b.x) + (a.y * b.y); }
int    Violet::Math::dot(const Vec3i& a, const Vec3i& b) { return (a.x * b.x) + (a.y * b.y) + (a.y * b.z); }
float  Violet::Math::dot(const Vec3f& a, const Vec3f& b) { return (a.x * b.x) + (a.y * b.y) + (a.y * b.z); }
double Violet::Math::dot(const Vec3d& a, const Vec3d& b) { return (a.x * b.x) + (a.y * b.y) + (a.y * b.z); }

Violet::Vec3i Violet::Math::cross(const Vec3i& a, const Vec3i& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}

Violet::Vec3f Violet::Math::cross(const Vec3f& a, const Vec3f& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}

Violet::Vec3d Violet::Math::cross(const Vec3d& a, const Vec3d& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}

Violet::Vec3f Violet::Math::rotate_vec3f_around_vec3i(const Vec3f& vec, const Vec3i& axis, float  theta) {
	auto is_basis = [](const Vec3i& vec) -> bool {
		if (abs(vec.x) == 1)
			return (vec.y == 0) && (vec.z == 0);
		if (abs(vec.y) == 1)
			return (vec.x == 0) && (vec.z == 0);
		if (abs(vec.z) == 1)
			return (vec.x == 0) && (vec.y == 0);
		return false;
	};
	if (is_basis(axis)) {
		Quat rotation = rotation_quat_vec3i(axis, theta);
		return apply_quat_rotation_vec3f(vec, rotation);
	}
	else
		return Vec3f();
}

Violet::Vec3f Violet::Math::rotate_vec3f_around_vec3f(const Vec3f& vec, const Vec3f& axis, float  theta) {
	Quat rotation = rotation_quat_vec3f(axis, theta);
	return apply_quat_rotation_vec3f(vec, rotation);
}

Violet::Vec3d Violet::Math::rotate_vec3d_around_vec3i(const Vec3d& vec, const Vec3i& axis, double theta) {
	auto is_basis = [](const Vec3i& vec) -> bool {
		if (abs(vec.x) == 1)
			return (vec.y == 0) && (vec.z == 0);
		if (abs(vec.y) == 1)
			return (vec.x == 0) && (vec.z == 0);
		if (abs(vec.z) == 1)
			return (vec.x == 0) && (vec.y == 0);
		return false;
	};
	if (is_basis(axis)) {
		Quat rotation = rotation_quat_vec3i(axis, theta);
		return apply_quat_rotation_vec3d(vec, rotation);
	}
	else
		return Vec3d();
}

Violet::Vec3d Violet::Math::rotate_vec3d_around_vec3d(const Vec3d& vec, const Vec3d& axis, double theta) {
	Quat rotation = rotation_quat_vec3d(axis, theta);
	return apply_quat_rotation_vec3d(vec, rotation);
}

Violet::Vec3f Violet::Math::apply_quat_rotation_vec3f(const Vec3f& vec, const Quat& rotation_quat) {
	Quat q_inv = complex_conjugate(rotation_quat);
	Quat p = { 0.0, vec.x, vec.y, vec.z };
	Quat result_quat = rotation_quat * p * q_inv;
	return {
		(float)result_quat.x,
		(float)result_quat.y,
		(float)result_quat.z
	};
}

Violet::Vec3d Violet::Math::apply_quat_rotation_vec3d(const Vec3d& vec, const Quat& rotation_quat) {
	Quat q_inv = complex_conjugate(rotation_quat);
	Quat p = { 0.0, vec.x, vec.y, vec.z };
	Quat result_quat = rotation_quat * p * q_inv;
	return {
		result_quat.x,
		result_quat.y,
		result_quat.z
	};
}

Violet::Quat Violet::Math::normalize(const Quat& quat) {
	double length = std::hypot(quat.w, std::hypot(quat.x, quat.y, quat.z));
	return {
		quat.w / length,
		quat.x / length,
		quat.y / length,
		quat.z / length
	};
}

Violet::Quat Violet::Math::rotation_quat_vec3i(const Vec3i& axis, double theta) {
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * (double)axis.x,
		s * (double)axis.y,
		s * (double)axis.z
	};
}

Violet::Quat Violet::Math::rotation_quat_vec3f(const Vec3f& axis, double theta) {
	Vec3f axis_n = normalize(axis);
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * (double)axis_n.x,
		s * (double)axis_n.y,
		s * (double)axis_n.z
	};
}

Violet::Quat Violet::Math::rotation_quat_vec3d(const Vec3d& axis, double theta) {
	Vec3d axis_n = normalize(axis);
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * axis_n.x,
		s * axis_n.y,
		s * axis_n.z
	};
}

Violet::Quat Violet::Math::complex_conjugate(const Quat& quat) {
	return {
		quat.w,
		-quat.x,
		-quat.y,
		-quat.z
	};
}

