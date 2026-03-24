
#pragma once

namespace Violet {

	class Quat {
	public:
		double w, x, y, z;
		Quat();
		Quat(double w, double x, double y, double z);
		Quat operator * (const Quat& q) const;
	};
}

