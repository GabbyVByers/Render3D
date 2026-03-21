
#include "Vec2.h"

Violet::Vec2f::Vec2f() { x = 0.0f; y = 0.0f; }
Violet::Vec2f::Vec2f(float x, float y) { this->x = x; this->y = y; }

Violet::Vec2f& Violet::Vec2f::operator = (const Vec2i& vec) { x = (float)vec.x; y = (float)vec.y; }
Violet::Vec2f& Violet::Vec2f::operator = (const Vec2f& vec) { x = (float)vec.x; y = (float)vec.y; }
Violet::Vec2f& Violet::Vec2f::operator = (const Vec2d& vec) { x = (float)vec.x; y = (float)vec.y; }

Violet::Vec2f Violet::Vec2f::operator + (const Vec2f& vec)  const { return { x + vec.x, y + vec.y }; }
Violet::Vec2f Violet::Vec2f::operator - (const Vec2f& vec)  const { return { x - vec.x, y - vec.y }; }
Violet::Vec2f Violet::Vec2f::operator * (const float scale) const { return { x * scale, y * scale }; }
Violet::Vec2f Violet::Vec2f::operator / (const float scale) const { return { x / scale, y / scale }; }

void Violet::Vec2f::operator += (const Vec2f& vec)  { x += vec.x; y += vec.y; }
void Violet::Vec2f::operator -= (const Vec2f& vec)  { x -= vec.x; y -= vec.y; }
void Violet::Vec2f::operator *= (const float scale) { x *= scale; y *= scale; }
void Violet::Vec2f::operator /= (const float scale) { x /= scale; y /= scale; }

