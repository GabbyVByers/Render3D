
#include "Violet.h"

Violet::Color::Color() {
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	a = 1.0f;
}

Violet::Color::Color(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Violet::Color Violet::Color::random() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0
	};
}

Violet::Color Violet::Color::white()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::black()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
Violet::Color Violet::Color::red()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
Violet::Color Violet::Color::green()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
Violet::Color Violet::Color::blue()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::cyan()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::purple() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::yellow() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }

