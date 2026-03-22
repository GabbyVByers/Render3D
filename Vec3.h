
#pragma once

namespace Violet {

	class Vec3i;
	class Vec3f;
	class Vec3d;

	class Vec3i {
	public:
		int x, y, z;
		Vec3i();
		Vec3i(int x, int y, int z);

		Vec3i& operator = (const Vec3i& vec);
		Vec3i& operator = (const Vec3f& vec);
		Vec3i& operator = (const Vec3d& vec);

		Vec3i operator + (const Vec3i& vec) const;
		Vec3i operator - (const Vec3i& vec) const;
		Vec3i operator * (const int scale)  const;
		Vec3i operator / (const int scale)  const;

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

		Vec3f& operator = (const Vec3i& vec);
		Vec3f& operator = (const Vec3f& vec);
		Vec3f& operator = (const Vec3d& vec);

		Vec3f operator + (const Vec3f& vec)  const;
		Vec3f operator - (const Vec3f& vec)  const;
		Vec3f operator * (const float scale) const;
		Vec3f operator / (const float scale) const;

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

		Vec3d& operator = (const Vec3i& vec);
		Vec3d& operator = (const Vec3f& vec);
		Vec3d& operator = (const Vec3d& vec);

		Vec3d operator + (const Vec3d& vec)   const;
		Vec3d operator - (const Vec3d& vec)   const;
		Vec3d operator * (const double scale) const;
		Vec3d operator / (const double scale) const;

		void  operator += (const Vec3d& vec);
		void  operator -= (const Vec3d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};
}

