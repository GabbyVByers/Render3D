
/*
	Types.Vec3f.cpp
*/

#include "Types.h"
#include <cmath>

Violet::Vec3f::Vec3f() { x = 0.0f; y = 0.0f; z = 0.0f; }
Violet::Vec3f::Vec3f(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

float Violet::Vec3f::hypot(const Vec3f& vec) { return std::hypot(vec.x, vec.y, vec.z); }
float Violet::Vec3f::dot(const Vec3f& a, const Vec3f& b) { return (a.x * b.x) + (a.y * b.y) + (a.y * b.z); }
Violet::Vec3f Violet::Vec3f::cross(const Vec3f& a, const Vec3f& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}
Violet::Vec3f Violet::Vec3f::normalize(const Vec3f& vec) {
	float len = hypot(vec);
	if (len == 0.0f) {
		return Vec3f();
	}
	return {
		vec.x / len,
		vec.y / len,
		vec.z / len
	};
}

Violet::Vec3f& Violet::Vec3f::operator = (const Violet::Vec3i& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
Violet::Vec3f& Violet::Vec3f::operator = (const Violet::Vec3f& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }
Violet::Vec3f& Violet::Vec3f::operator = (const Violet::Vec3d& vec) { x = (float)vec.x; y = (float)vec.y; z = (float)vec.z; return *this; }

Violet::Vec3f Violet::Vec3f::operator + (const Vec3f& vec)  const { return { x + vec.x, y + vec.y, z + vec.z }; }
Violet::Vec3f Violet::Vec3f::operator - (const Vec3f& vec)  const { return { x - vec.x, y - vec.y, z - vec.z }; }
Violet::Vec3f Violet::Vec3f::operator * (const float scale) const { return { x * scale, y * scale, z * scale }; }
Violet::Vec3f Violet::Vec3f::operator / (const float scale) const { return { x / scale, y / scale, z / scale }; }

void Violet::Vec3f::operator += (const Vec3f& vec)  { x += vec.x; y += vec.y; z += vec.z; }
void Violet::Vec3f::operator -= (const Vec3f& vec)  { x -= vec.x; y -= vec.y; z -= vec.z; }
void Violet::Vec3f::operator *= (const float scale) { x *= scale; y *= scale; z *= scale; }
void Violet::Vec3f::operator /= (const float scale) { x /= scale; y /= scale; z /= scale; }

