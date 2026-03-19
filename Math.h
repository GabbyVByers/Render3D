
#pragma once
#include <cmath>
#include <memory>

namespace Violet {
	constexpr double Pi64 = 3.141592653589793;
	constexpr float  Pi32 = 3.1415927f;

	class Vec2i;
	class Vec2d;
	class Vec3i;
	class Vec3f;
	class Vec3d;
	class Matrix;
	class Matrix_f;
	class Quaternion;
	class Transformation;

	class Vec2i {
	public:
		int x, y;
		Vec2i();
		Vec2i(int x, int y);
		Vec2i operator +  (const Vec2i& vec) const;
		Vec2i operator -  (const Vec2i& vec) const;
		Vec2i operator *  (const int scale)  const;
		Vec2i operator /  (const int scale)  const;
		void  operator += (const Vec2i& vec);
		void  operator -= (const Vec2i& vec); 
		void  operator *= (const int scale);
		void  operator /= (const int scale);
	};

	class Vec2d {
	public:
		double x, y;
		Vec2d();
		Vec2d(double x, double y);
		Vec2d operator +  (const Vec2d& vec)   const;
		Vec2d operator -  (const Vec2d& vec)   const;
		Vec2d operator *  (const double scale) const;
		Vec2d operator /  (const double scale) const;
		void  operator += (const Vec2d& vec);
		void  operator -= (const Vec2d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};

	class Vec3i {
	public:
		int x, y, z;
		Vec3i();
		Vec3i(int x, int y, int z);
		Vec3i operator +  (const Vec3i& vec) const;
		Vec3i operator -  (const Vec3i& vec) const;
		Vec3i operator *  (const int scale)  const;
		Vec3i operator /  (const int scale)  const;
		void  operator += (const Vec3i& vec);
		void  operator -= (const Vec3i& vec);
		void  operator *= (const int scale);
		void  operator /= (const int scale);
	};

	class Vec3f {
	public:
		float x, y, z;
		Vec3f();
		Vec3f(float x, float y, float z);
		Vec3f(const Vec3d& vec);
		Vec3f operator +  (const Vec3f& vec)  const;
		Vec3f operator -  (const Vec3f& vec)  const;
		Vec3f operator *  (const float scale) const;
		Vec3f operator /  (const float scale) const;
		void  operator += (const Vec3f& vec);
		void  operator -= (const Vec3f& vec);
		void  operator *= (const float scale);
		void  operator /= (const float scale);
	};

	class Vec3d {
	public:
		double x, y, z;
		Vec3d();
		Vec3d(double x, double y, double z);
		void normalize();
		void rotate(const Vec3d& axis, double theta);
		void rotate(const Quaternion& quat);
		static double lengthSq(const Vec3d& vec);
		static double length(const Vec3d& vec);
		static double dot(const Vec3d& a, const Vec3d& b);
		static Vec3d cross(const Vec3d& a, const Vec3d& b);
		Vec3d operator +  (const Vec3d& vec)   const;
		Vec3d operator -  (const Vec3d& vec)   const;
		Vec3d operator *  (const double scale) const;
		Vec3d operator /  (const double scale) const;
		void  operator += (const Vec3d& vec);
		void  operator -= (const Vec3d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};

	class Matrix {
	public:
		double data[4][4];
		Matrix();
		Matrix(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		);
		static Matrix buildScalarMatrix(double scale);
		static Matrix buildTranslationMatrix(const Vec3d& position);
		static Matrix buildRotationMatrix(const Quaternion& rotation);
		Matrix operator * (const Matrix& matrix) const;
	};

	class Matrix_f {
	public:
		float data[4][4];
		Matrix_f();
		Matrix_f(const Matrix& matrix);
	};

	class Quaternion {
	public:
		double w, x, y, z;
		Quaternion();
		Quaternion(double w, double x, double y, double z);
		void normalize();
		static Quaternion buildRotationQuaternion(const Vec3d& axis, double theta);
		static Quaternion complexConjugate(const Quaternion& quat);
		Quaternion operator * (const Quaternion& q) const;
	};

	class Transformation {
	public:
		double scale;
		Vec3d position;
		Quaternion orientation;
		Matrix modelMatrix() const;
		Matrix viewMatrix() const;
	};
}

