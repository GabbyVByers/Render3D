
#include "Math.h"

Math::Quat::Quat() {
	w = 1.0;
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Math::Quat::Quat(double _w, double _x, double _y, double _z) {
	w = _w;
	x = _x;
	y = _y;
	z = _z;
}

Math::Quat::Quat(const double3& _axis, double theta) {
	double3 axis = _axis.normalized();
	double half = theta * 0.5;
	double s = sin(half);
	w = cos(half);
	x = s * axis.x;
	y = s * axis.y;
	z = s * axis.z;
}

Math::Quat Math::Quat::normalized() const {
	double len = sqrt((w * w) + (x * x) + (y * y) + (z * z));
	return {
		w / len,
		x / len,
		y / len,
		z / len
	};
}

Math::Quat Math::Quat::complexConjugate() const {
	return {
		w,
	   -x,
	   -y,
	   -z
	};
}

Math::Quat Math::Quat::operator * (const Quat& q) const {
	return {
		(w * q.w) - (x * q.x) - (y * q.y) - (z * q.z),
		(w * q.x) + (x * q.w) + (y * q.z) - (z * q.y),
		(w * q.y) - (x * q.z) + (y * q.w) + (z * q.x),
		(w * q.z) + (x * q.y) - (y * q.x) + (z * q.w)
	};
}

