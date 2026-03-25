
#pragma once

namespace Violet {

	class Quat {
	public:
		double w, x, y, z;
		Quat();
		Quat(double w, double x, double y, double z);

		static Quat normalize(const Quat& quat);
		static Quat complex_conjugate(const Quat& quat);

		Quat operator * (const Quat& q) const;
	};
}

