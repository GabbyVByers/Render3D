
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

		Color operator *  (const float scale) const;
		Color operator /  (const float scale) const;
		void  operator *= (const float scale);
		void  operator /= (const float scale);

	private:
		static float clamp(float value);
	};
}

