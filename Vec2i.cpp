
#include "Vec2.h"

Violet::Vec2i::Vec2i() { x = 0; y = 0; }
Violet::Vec2i::Vec2i(int x, int y) { this->x = x; this->y = y; }

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

