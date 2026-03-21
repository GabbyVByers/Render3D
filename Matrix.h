
#pragma once

namespace Violet {
	class Mat4 {
	public:
		double data[4][4];
		Mat4();
		Mat4(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		);
		/*
		static Matrix buildScalarMatrix(double scale);
		static Matrix buildTranslationMatrix(const Vec3d& position);
		static Matrix buildRotationMatrix(const Quaternion& rotation);
		*/
		Mat4 operator * (const Mat4& matrix) const;
	};
}

