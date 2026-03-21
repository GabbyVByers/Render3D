
#pragma once

namespace Violet {

	class Vec2i {
	public:
		int x, y;
		Vec2i();
		Vec2i(int x, int y);

		Vec2i& operator = (const Vec2i& vec);
		Vec2i& operator = (const Vec2f& vec);
		Vec2i& operator = (const Vec2d& vec);

		Vec2i operator + (const Vec2i& vec) const;
		Vec2i operator - (const Vec2i& vec) const;
		Vec2i operator * (const int scale)  const;
		Vec2i operator / (const int scale)  const;

		void  operator += (const Vec2i& vec);
		void  operator -= (const Vec2i& vec);
		void  operator *= (const int scale);
		void  operator /= (const int scale);
	};

	class Vec2f {
	public:
		float x, y;
		Vec2f();
		Vec2f(float x, float y);

		Vec2f& operator = (const Vec2i& vec);
		Vec2f& operator = (const Vec2f& vec);
		Vec2f& operator = (const Vec2d& vec);

		Vec2f operator + (const Vec2f& vec)  const;
		Vec2f operator - (const Vec2f& vec)  const;
		Vec2f operator * (const float scale) const;
		Vec2f operator / (const float scale) const;

		void  operator += (const Vec2f& vec);
		void  operator -= (const Vec2f& vec);
		void  operator *= (const float scale);
		void  operator /= (const float scale);
	};

	class Vec2d {
	public:
		double x, y;
		Vec2d();
		Vec2d(double x, double y);

		Vec2d& operator = (const Vec2i& vec);
		Vec2d& operator = (const Vec2f& vec);
		Vec2d& operator = (const Vec2d& vec);

		Vec2d operator + (const Vec2d& vec)   const;
		Vec2d operator - (const Vec2d& vec)   const;
		Vec2d operator * (const double scale) const;
		Vec2d operator / (const double scale) const;

		void  operator += (const Vec2d& vec);
		void  operator -= (const Vec2d& vec);
		void  operator *= (const double scale);
		void  operator /= (const double scale);
	};
}

