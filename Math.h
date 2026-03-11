
#pragma once
#include <cmath>
#include <memory>

#define Math Math
namespace Math {
	constexpr double Pi64 = 3.141592653589793;
	constexpr float  Pi32 = 3.1415927f;

	class Quat;
	class double3;
	class float3;
	class float4;
	class double4x4;
	class float4x4;
	class Trans;

	class Quat {
	public:
		double w, x, y, z;
		Quat();
		Quat(double _w, double _x, double _y, double _z);
		Quat(const double3& axis, double theta);
		Quat normalized() const;
		Quat complexConjugate() const;
		Quat operator * (const Quat& q) const;
	};

	class double3 {
	public:
		double x, y, z;
		double3();
		double3(double _x, double _y, double _z);
		double3(const Quat& quat, const double3& basis_dir);
		double3 rotated(const double3& axis, double theta) const;
		double3 normalized() const;
		double  lengthSq() const;
		double  length() const;
		double  dot(const double3& vec) const;
		double3 cross(const double3& vec) const;
		double3 operator +  (const double3& vec) const;
		double3 operator -  (const double3& vec) const;
		double3 operator *  (const double scale) const;
		double3 operator /  (const double scale) const;
		void    operator += (const double3& vec);
		void    operator -= (const double3& vec);
		void    operator *= (const double scale);
		void    operator /= (const double scale);
	};

	class float3 {
	public:
		float x, y, z;
		float3();
		float3(const double3& vec);
	};

	class float4 {
	public:
		float r, g, b, a;
		float4();
		float4(float _r, float _g, float _b, float _a = 1.0f);
		static float4 white();
		static float4 black();
		static float4 red();
		static float4 green();
		static float4 blue();
		static float4 cyan();
		static float4 purple();
		static float4 yellow();
	};

	class double4x4 {
	public:
		double data[4][4];
		double4x4(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		);
		double4x4();
		double4x4(double scale);
		double4x4(const double3& position);
		double4x4(const Quat& rotation);
		double4x4 operator * (const double4x4& matrix) const;
	};

	class float4x4 {
	public:
		float data[4][4];
		float4x4();
		float4x4(const double4x4& matrix);
	};

	class Trans {
	public:
		double scale;
		double3 position;
		Quat rotation;
		double4x4 modelMatrix() const;
		double4x4 viewMatrix() const;
	};
}

