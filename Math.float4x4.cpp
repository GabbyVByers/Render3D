
#include "Math.h"

Math::float4x4::float4x4() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; i++) {
			data[i][j] = 0.0f;
		}
		data[i][i] = 1.0f;
	}
}

Math::float4x4::float4x4(const double4x4& matrix) {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; i++) {
			data[i][j] = (float)matrix.data[i][j];
		}
	}
}

