
#pragma once

namespace Violet {

	class Quaternion {
	public:
		double w, x, y, z;
		Quaternion();
		Quaternion(double w, double x, double y, double z);
		Quaternion operator * (const Quaternion& q) const;
	};
}

