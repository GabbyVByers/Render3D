
#pragma once
#include "Vec2.h"
#include "Color.h"
#include "png.h"
#include <vector>
#include <string>
#include <cstdio>

namespace Violet {

	class Image {
	public:
		Vec2i size() const;
		Color& pixel(size_t x, size_t y);
		Image(const std::string& path);

	private:
		Vec2i image_size;
		std::vector<Color> pixels;
	};
}

