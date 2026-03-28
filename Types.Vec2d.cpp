
/*
	Types.Vec2d.cpp
*/

#include "Types.h"
#include <cmath>

Violet::Vec2d::Vec2d() { x = 0.0; y = 0.0; }
Violet::Vec2d::Vec2d(double x, double y) { this->x = x; this->y = y; }

double Violet::Vec2d::hypot(const Vec2d& vec) { return std::hypot(vec.x, vec.y); }
double Violet::Vec2d::dot(const Vec2d& a, const Vec2d& b) { return (a.x * b.x) + (a.y * b.y); }
double Violet::Vec2d::cross(const Vec2d& a, const Vec2d& b) { return (a.x * b.y) - (a.y * b.x); }
Violet::Vec2d Violet::Vec2d::normalize(const Vec2d& vec) {
	float len = hypot(vec);
	return {
		vec.x / len,
		vec.y / len
	};
}

Violet::Vec2d& Violet::Vec2d::operator = (const Vec2i& vec) { x = (double)vec.x; y = (double)vec.y; return *this; }
Violet::Vec2d& Violet::Vec2d::operator = (const Vec2f& vec) { x = (double)vec.x; y = (double)vec.y; return *this; }
Violet::Vec2d& Violet::Vec2d::operator = (const Vec2d& vec) { x = (double)vec.x; y = (double)vec.y; return *this; }

Violet::Vec2d Violet::Vec2d::operator + (const Vec2d& vec)   const { return { x + vec.x, y + vec.y }; }
Violet::Vec2d Violet::Vec2d::operator - (const Vec2d& vec)   const { return { x - vec.x, y - vec.y }; }
Violet::Vec2d Violet::Vec2d::operator * (const double scale) const { return { x * scale, y * scale }; }
Violet::Vec2d Violet::Vec2d::operator / (const double scale) const { return { x / scale, y / scale }; }

void Violet::Vec2d::operator += (const Vec2d& vec)   { x += vec.x; y += vec.y; }
void Violet::Vec2d::operator -= (const Vec2d& vec)   { x -= vec.x; y -= vec.y; }
void Violet::Vec2d::operator *= (const double scale) { x *= scale; y *= scale; }
void Violet::Vec2d::operator /= (const double scale) { x /= scale; y /= scale; }

