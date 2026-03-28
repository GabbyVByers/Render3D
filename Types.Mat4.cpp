
/*
	Types.Mat4.cpp
*/

#include "Types.h"

Violet::Mat4::Mat4() {
	(*this) = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
}

Violet::Mat4::Mat4(
	double a, double b, double c, double d,
	double e, double f, double g, double h,
	double i, double j, double k, double l,
	double m, double n, double o, double p
) {
	data[0][0] = a; data[0][1] = b; data[0][2] = c; data[0][3] = d;
	data[1][0] = e; data[1][1] = f; data[1][2] = g; data[1][3] = h;
	data[2][0] = i; data[2][1] = j; data[2][2] = k; data[2][3] = l;
	data[3][0] = m; data[3][1] = n; data[3][2] = o; data[3][3] = p;
}

Violet::Mat4 Violet::Mat4::operator * (const Mat4& matrix) const {
	Mat4 result;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			double sum = 0.0;
			for (size_t k = 0; k < 4; k++) {
				sum += data[i][k] * matrix.data[k][j];
			}
			result.data[i][j] = sum;
		}
	}
	return result;
}

Violet::Mat4f::Mat4f() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			data[i][j] = 0.0f;
		}
		data[i][i] = 1.0f;
	}
}

