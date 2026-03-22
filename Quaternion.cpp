
#include "Quaternion.h"

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

Violet::Quaternion Violet::Quaternion::operator * (const Quaternion& q) const {
	return {
		(w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
		(w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
		(w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
		(w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
	};
}

