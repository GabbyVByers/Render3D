
/*
	Types.Vec3d.cpp
*/

#include "Types.h"
#include <cmath>

Violet::Vec3d::Vec3d() { x = 0.0; y = 0.0; z = 0.0; }
Violet::Vec3d::Vec3d(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }

double Violet::Vec3d::hypot(const Vec3d& vec) { return std::hypot(vec.x, vec.y, vec.z); }
double Violet::Vec3d::dot(const Vec3d& a, const Vec3d& b) { return (a.x * b.x) + (a.y * b.y) + (a.y * b.z); }
Violet::Vec3d Violet::Vec3d::cross(const Vec3d& a, const Vec3d& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}
Violet::Vec3d Violet::Vec3d::normalize(const Vec3d& vec) {
	double len = hypot(vec);
	if (len == 0.0) {
		return Vec3d();
	}
	return {
		vec.x / len,
		vec.y / len,
		vec.z / len
	};
}

Violet::Vec3d& Violet::Vec3d::operator = (const Violet::Vec3i& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
Violet::Vec3d& Violet::Vec3d::operator = (const Violet::Vec3f& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }
Violet::Vec3d& Violet::Vec3d::operator = (const Violet::Vec3d& vec) { x = (double)vec.x; y = (double)vec.y; z = (double)vec.z; return *this; }

Violet::Vec3d Violet::Vec3d::operator + (const Vec3d& vec)   const { return { x + vec.x, y + vec.y, z + vec.z }; }
Violet::Vec3d Violet::Vec3d::operator - (const Vec3d& vec)   const { return { x - vec.x, y - vec.y, z - vec.z }; }
Violet::Vec3d Violet::Vec3d::operator * (const double scale) const { return { x * scale, y * scale, z * scale }; }
Violet::Vec3d Violet::Vec3d::operator / (const double scale) const { return { x / scale, y / scale, z / scale }; }

void Violet::Vec3d::operator += (const Vec3d& vec)   { x += vec.x; y += vec.y; z += vec.z; }
void Violet::Vec3d::operator -= (const Vec3d& vec)   { x -= vec.x; y -= vec.y; z -= vec.z; }
void Violet::Vec3d::operator *= (const double scale) { x *= scale; y *= scale; z *= scale; }
void Violet::Vec3d::operator /= (const double scale) { x /= scale; y /= scale; z /= scale; }

