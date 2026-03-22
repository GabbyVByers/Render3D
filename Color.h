
#pragma once

namespace Violet {

	class Color {
	public:
		float r, g, b, a;
		Color();
		Color(float r, float g, float b, float a = 1.0f);
		static Color random();
		static Color white();
		static Color black();
		static Color red();
		static Color green();
		static Color blue();
		static Color cyan();
		static Color purple();
		static Color yellow();
	};
}

