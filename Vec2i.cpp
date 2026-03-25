
#include "Vec2.h"
#include <cmath>
#include <vector>

Violet::Vec2i::Vec2i() { x = 0; y = 0; }
Violet::Vec2i::Vec2i(int x, int y) { this->x = x; this->y = y; }

int Violet::Vec2i::hypot(const Vec2i& vec) { return std::hypot(vec.x, vec.y); }
int Violet::Vec2i::dot(const Vec2i& a, const Vec2i& b) { return (a.x * b.x) + (a.y * b.y); }
int Violet::Vec2i::cross(const Vec2i& a, const Vec2i& b) { return (a.x * b.y) - (a.y * b.x); }
Violet::Vec2i Violet::Vec2i::normalize(const Vec2i& vec) {
	static const std::vector<Vec2f> basisies{
		Vec2f( 1.0f, 0.0f),
		Vec2f(-1.0f, 0.0f),
		Vec2f( 0.0f, 1.0f),
		Vec2f( 0.0f,-1.0f)
	};
	Vec2f vec_f = {
		(float)vec.x,
		(float)vec.y
	};
	std::vector<float> dots;
	dots.reserve(4);
	for (size_t i = 0; i < 4; i++) {
		const Vec2f& a = basisies[i];
		dots.push_back(Vec2f::dot(a, vec_f));
	}
	size_t index_max = 0;
	float max = -FLT_MAX;
	for (size_t i = 0; i < 4; i++) {
		const float dot_prod = dots[i];
		if (dot_prod > max) {
			max = dot_prod;
			index_max = i;
		}
	}
	Vec2f closest_basis_f = basisies[index_max];
	return {
		(int)closest_basis_f.x,
		(int)closest_basis_f.y
	};
}

Violet::Vec2i& Violet::Vec2i::operator = (const Vec2i& vec) { x = (int)vec.x; y = (int)vec.y; return *this; }
Violet::Vec2i& Violet::Vec2i::operator = (const Vec2f& vec) { x = (int)vec.x; y = (int)vec.y; return *this; }
Violet::Vec2i& Violet::Vec2i::operator = (const Vec2d& vec) { x = (int)vec.x; y = (int)vec.y; return *this; }

Violet::Vec2i Violet::Vec2i::operator + (const Vec2i& vec) const { return { x + vec.x, y + vec.y }; }
Violet::Vec2i Violet::Vec2i::operator - (const Vec2i& vec) const { return { x - vec.x, y - vec.y }; }
Violet::Vec2i Violet::Vec2i::operator * (const int scale)  const { return { x * scale, y * scale }; }
Violet::Vec2i Violet::Vec2i::operator / (const int scale)  const { return { x / scale, y / scale }; }

void Violet::Vec2i::operator += (const Vec2i& vec) { x += vec.x; y += vec.y; }
void Violet::Vec2i::operator -= (const Vec2i& vec) { x -= vec.x; y -= vec.y; }
void Violet::Vec2i::operator *= (const int scale)  { x *= scale; y *= scale; }
void Violet::Vec2i::operator /= (const int scale)  { x /= scale; y /= scale; }

