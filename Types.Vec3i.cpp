
/*
	Types.Vec3i.cpp
*/

#include "Types.h"
#include <cmath>
#include <vector>

Violet::Vec3i::Vec3i() { x = 0; y = 0; z = 0; }
Violet::Vec3i::Vec3i(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }

int Violet::Vec3i::hypot(const Vec3i& vec) { return std::hypot(vec.x, vec.y, vec.z); }
int Violet::Vec3i::dot(const Vec3i& a, const Vec3i& b) { return (a.x * b.x) + (a.y * b.y) + (a.y * b.z); }
Violet::Vec3i Violet::Vec3i::cross(const Vec3i& a, const Vec3i& b) {
	return {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}
Violet::Vec3i Violet::Vec3i::normalize(const Vec3i& vec) {
	int sum =
		std::abs(vec.x) +
		std::abs(vec.y) +
		std::abs(vec.z);
	if (sum == 1)
		return vec;
	static const std::vector<Vec3f> basisies{
		Vec3f( 1.0f, 0.0f, 0.0f),
		Vec3f(-1.0f, 0.0f, 0.0f),
		Vec3f( 0.0f, 1.0f, 0.0f),
		Vec3f( 0.0f,-1.0f, 0.0f),
		Vec3f( 0.0f, 0.0f, 1.0f),
		Vec3f( 0.0f, 0.0f,-1.0f)
	};
	Vec3f vec_f = {
		(float)vec.x,
		(float)vec.y,
		(float)vec.z
	};
	std::vector<float> dots;
	dots.reserve(6);
	for (size_t i = 0; i < 6; i++) {
		const Vec3f& a = basisies[i];
		dots.push_back(Vec3f::dot(a, vec_f));
	}
	size_t index_max = 0;
	float max = -FLT_MAX;
	for (size_t i = 0; i < 6; i++) {
		const float dot_prod = dots[i];
		if (dot_prod > max) {
			max = dot_prod;
			index_max = i;
		}
	}
	Vec3f closest_basis_f = basisies[index_max];
	return {
		(int)closest_basis_f.x,
		(int)closest_basis_f.y,
		(int)closest_basis_f.z
	};
}

Violet::Vec3i& Violet::Vec3i::operator = (const Violet::Vec3i& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
Violet::Vec3i& Violet::Vec3i::operator = (const Violet::Vec3f& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }
Violet::Vec3i& Violet::Vec3i::operator = (const Violet::Vec3d& vec) { x = (int)vec.x; y = (int)vec.y; z = (int)vec.z; return *this; }

Violet::Vec3i Violet::Vec3i::operator + (const Vec3i& vec) const { return { x + vec.x, y + vec.y, z + vec.z }; }
Violet::Vec3i Violet::Vec3i::operator - (const Vec3i& vec) const { return { x - vec.x, y - vec.y, z - vec.z }; }
Violet::Vec3i Violet::Vec3i::operator * (const int scale)  const { return { x * scale, y * scale, z * scale }; }
Violet::Vec3i Violet::Vec3i::operator / (const int scale)  const { return { x / scale, y / scale, z / scale }; }

void Violet::Vec3i::operator += (const Vec3i& vec) { x += vec.x; y += vec.y; z += vec.z; }
void Violet::Vec3i::operator -= (const Vec3i& vec) { x -= vec.x; y -= vec.y; z -= vec.z; }
void Violet::Vec3i::operator *= (const int scale)  { x *= scale; y *= scale; z *= scale; }
void Violet::Vec3i::operator /= (const int scale)  { x /= scale; y /= scale; z /= scale; }

