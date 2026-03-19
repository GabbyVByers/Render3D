
#include "Math.h"

Violet::Quaternion::Quaternion() {
	w = 1.0;
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Violet::Quaternion::Quaternion(double w, double x, double y, double z) {
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Violet::Quaternion::normalize() {
	double len = sqrt((w * w) + (x * x) + (y * y) + (z * z));
	w /= len;
	x /= len;
	y /= len;
	z /= len;
}

Violet::Quaternion Violet::Quaternion::buildRotationQuaternion(const Vec3d& axis, double theta) {
	Vec3d axis_n = axis;
	axis_n.normalize();
	double half = theta * 0.5;
	double s = sin(half);
	return {
		cos(half),
		s * axis_n.x,
		s * axis_n.y,
		s * axis_n.z
	};
}


Violet::Quaternion Violet::Quaternion::complexConjugate(const Quaternion& quat) {
	return {
		quat.w,
	   -quat.x,
	   -quat.y,
	   -quat.z
	};
}

Violet::Quaternion Violet::Quaternion::operator * (const Quaternion& q) const {
	return {
		(w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
		(w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
		(w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
		(w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
	};
}

