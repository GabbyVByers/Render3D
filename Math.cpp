
#include "Math.h"
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

Violet::Vec3f Violet::Math::rotateAroundAxis(const Vec3f& vec, const Vec3i& axis, float  theta) {
	Quaternion rotation = rotationQuaternion(axis, theta);
	return applyQuaternionRotation(vec, rotation);
}

Violet::Vec3f Violet::Math::rotateAroundAxis(const Vec3f& vec, const Vec3f& axis, float  theta) {
	Quaternion rotation = rotationQuaternion(axis, theta);
	return applyQuaternionRotation(vec, rotation);
}

Violet::Vec3d Violet::Math::rotateAroundAxis(const Vec3d& vec, const Vec3i& axis, double theta) {
	Quaternion rotation = rotationQuaternion(axis, theta);
	return applyQuaternionRotation(vec, rotation);
}

Violet::Vec3d Violet::Math::rotateAroundAxis(const Vec3d& vec, const Vec3d& axis, double theta) {
	Quaternion rotation = rotationQuaternion(axis, theta);
	return applyQuaternionRotation(vec, rotation);
}

Violet::Vec3f Violet::Math::applyQuaternionRotation(const Vec3f& vec, const Quaternion& rotation_quat) {
	Quaternion q_inv = complexConjugate(rotation_quat);
	Quaternion p = { 0.0, vec.x, vec.y, vec.z };
	Quaternion result_quat = rotation_quat * p * q_inv;
	return {
		(float)result_quat.x,
		(float)result_quat.y,
		(float)result_quat.z
	};
}

Violet::Vec3d Violet::Math::applyQuaternionRotation(const Vec3d& vec, const Quaternion& rotation_quat) {
	Quaternion q_inv = complexConjugate(rotation_quat);
	Quaternion p = { 0.0, vec.x, vec.y, vec.z };
	Quaternion result_quat = rotation_quat * p * q_inv;
	return {
		result_quat.x,
		result_quat.y,
		result_quat.z
	};
}

Violet::Quaternion Violet::Math::normalize(const Quaternion& quat) {
	double length = std::hypot(quat.w, std::hypot(quat.x, quat.y, quat.z));
	return {
		quat.w / length,
		quat.x / length,
		quat.y / length,
		quat.z / length
	};
}

Violet::Quaternion Violet::Math::rotationQuaternion(const Vec3i& axis, double theta) {
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * (double)axis.x,
		s * (double)axis.y,
		s * (double)axis.z
	};
}

Violet::Quaternion Violet::Math::rotationQuaternion(const Vec3f& axis, double theta) {
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

Violet::Quaternion Violet::Math::rotationQuaternion(const Vec3d& axis, double theta) {
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

Violet::Quaternion Violet::Math::complexConjugate(const Quaternion& quat) {
	return {
		quat.w,
		-quat.x,
		-quat.y,
		-quat.z
	};
}

Violet::Mat4 Violet::Math::scalarMatrix(double scale) {
	double s = scale;
	return {
		s, 0, 0, 0,
		0, s, 0, 0,
		0, 0, s, 0,
		0, 0, 0, 1
	};
}

Violet::Mat4 Violet::Math::translationMatrix(const Violet::Vec3d& position) {
	const double x = position.x;
	const double y = position.y;
	const double z = position.z;
	return {
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	};
}

Violet::Mat4 Violet::Math::rotationMatrix(const Violet::Quaternion& rotation) {
	Quaternion rot_n = normalize(rotation);
	double xw = rot_n.x * rot_n.w;
	double xx = rot_n.x * rot_n.x;
	double xy = rot_n.x * rot_n.y;
	double xz = rot_n.x * rot_n.z;
	double yw = rot_n.y * rot_n.w;
	double yy = rot_n.y * rot_n.y;
	double yz = rot_n.y * rot_n.z;
	double zw = rot_n.z * rot_n.w;
	double zz = rot_n.z * rot_n.z;
	return {
		1 - 2 * (yy + zz), 2 * (xy - zw), 2 * (xz + yw), 0,
		2 * (xy + zw), 1 - 2 * (xx + zz), 2 * (yz - xw), 0,
		2 * (xz - yw), 2 * (yz + xw), 1 - 2 * (xx + yy), 0,
		0, 0, 0, 1
	};
}

Violet::Mat4f Violet::Math::floatMatrix(const Mat4& matrix) {
	Mat4f matrix_f;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			matrix_f.data[i][j] = (float)matrix.data[i][j];
		}
	}
	return matrix_f;
}

