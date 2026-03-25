
#include "Quat.h"
#include <cmath>

Violet::Quat::Quat() {
	w = 1.0;
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Violet::Quat::Quat(double w, double x, double y, double z) {
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}

Violet::Quat Violet::Quat::normalize(const Quat& quat) {
	double length = std::hypot(quat.w, std::hypot(quat.x, quat.y, quat.z));
	return {
		quat.w / length,
		quat.x / length,
		quat.y / length,
		quat.z / length
	};
}

Violet::Quat Violet::Quat::complex_conjugate(const Quat& quat) {
	return {
		quat.w,
		-quat.x,
		-quat.y,
		-quat.z
	};
}

Violet::Quat Violet::Quat::operator * (const Quat& q) const {
	return {
		(w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
		(w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
		(w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
		(w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
	};
}

