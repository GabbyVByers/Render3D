
#include "Math.h"

Math::double3::double3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Math::double3::double3(double _x, double _y, double _z) {
	x = _x;
	y = _y;
	z = _z;
}

Math::double3::double3(const Quat& quat, const double3& basis_dir) {
	Quat quat_inv = quat.complexConjugate();
	Quat p = Quat(0.0, basis_dir.x, basis_dir.y, basis_dir.z);
	Quat result = quat * p * quat_inv;
	x = result.x;
	y = result.y;
	z = result.z;
}

Math::double3 Math::double3::operator +  (const double3& vec) const { return { x + vec.x, y + vec.y, z + vec.z, }; }
Math::double3 Math::double3::operator -  (const double3& vec) const { return { x - vec.x, y - vec.y, z - vec.z, }; }
Math::double3 Math::double3::operator *  (const double scale) const { return { x * scale, y * scale, z * scale, }; }
Math::double3 Math::double3::operator /  (const double scale) const { return { x / scale, y / scale, z / scale, }; }
void          Math::double3::operator += (const double3& vec) { x += vec.x; y += vec.y; z += vec.z; }
void          Math::double3::operator -= (const double3& vec) { x -= vec.x; y -= vec.y; z -= vec.z; }
void          Math::double3::operator *= (const double scale) { x *= scale; y *= scale; z *= scale; }
void          Math::double3::operator /= (const double scale) { x /= scale; y /= scale; z /= scale; }

Math::double3 Math::double3::rotated(const double3& axis, double theta) const {
	Quat rotation = Quat(axis, theta);
	return double3(rotation, (*this));
}

Math::double3 Math::double3::normalized() const {
	double len = length();
	return {
		x / len,
		y / len,
		z / len
	};
}

double Math::double3::lengthSq() const {
	return (x * x) + (y * y) + (z * z);
}

double Math::double3::length() const {
	return sqrt(lengthSq());
}

double Math::double3::dot(const double3& vec) const {
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}

Math::double3 Math::double3::cross(const double3& vec) const {
	return {
		(y * vec.z) - (z * vec.y),
		(z * vec.x) - (x * vec.z),
		(x * vec.y) - (y * vec.x)
	};
}

