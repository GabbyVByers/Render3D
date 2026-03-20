
#include "Vector.h"

Violet::Vec2d::Vec2d() {
	x = 0.0;
	y = 0.0;
}

Violet::Vec2d::Vec2d(double x, double y) {
	this->x = x;
	this->y = y;
}

Violet::Vec2d Violet::Vec2d::operator +  (const Vec2d& vec)   const { return { x + vec.x, y + vec.y }; }
Violet::Vec2d Violet::Vec2d::operator -  (const Vec2d& vec)   const { return { x - vec.x, y - vec.y }; }
Violet::Vec2d Violet::Vec2d::operator *  (const double scale) const { return { x * scale, y * scale }; }
Violet::Vec2d Violet::Vec2d::operator /  (const double scale) const { return { x / scale, y / scale }; }
void          Violet::Vec2d::operator += (const Vec2d& vec)   { x += vec.x; y += vec.y; }
void          Violet::Vec2d::operator -= (const Vec2d& vec)   { x -= vec.x; y -= vec.y; }
void          Violet::Vec2d::operator *= (const double scale) { x *= scale; y *= scale; }
void          Violet::Vec2d::operator /= (const double scale) { x /= scale; y /= scale; }

