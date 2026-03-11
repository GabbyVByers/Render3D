
#include "Math.h"

Math::float3::float3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Math::float3::float3(const double3& vec) {
	x = (float)vec.x;
	y = (float)vec.y;
	z = (float)vec.z;
}

