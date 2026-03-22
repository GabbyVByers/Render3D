
#include "Vec3.h"

Violet::Vec3d::Vec3d() { x = 0.0; y = 0.0; z = 0.0; }
Violet::Vec3d::Vec3d(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }

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

