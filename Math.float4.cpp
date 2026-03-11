
#include "Math.h"

Math::float4::float4() {
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	a = 1.0f;
}

Math::float4::float4(float _r, float _g, float _b, float _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

Math::float4 Math::float4::white()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
Math::float4 Math::float4::black()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
Math::float4 Math::float4::red()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
Math::float4 Math::float4::green()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
Math::float4 Math::float4::blue()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
Math::float4 Math::float4::cyan()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
Math::float4 Math::float4::purple() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
Math::float4 Math::float4::yellow() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }

