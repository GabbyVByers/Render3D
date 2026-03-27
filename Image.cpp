
#include "Image.h"

Violet::Vec2i Violet::Image::size() const {
	return image_size;
}

Violet::Color& Violet::Image::pixel(size_t x, size_t y) {
	if (x >= image_size.x)
		std::terminate();
	if (y >= image_size.y)
		std::terminate();
	size_t index = (y * (size_t)image_size.x) + x;
	return pixels[index];
}

Violet::Image::Image(const std::string& path) {
	FILE* file = fopen(path.c_str(), "rb");
	if (!file)
		std::terminate();

	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png)
		std::terminate();

	png_infop info = png_create_info_struct(png);
	if (!info)
		std::terminate();

	if (setjmp(png_jmpbuf(png)))
		std::terminate();

	png_init_io(png, file);
	png_read_info(png, info);

	png_uint_32 width, height;
	int bit_depth, color_type;
	png_get_IHDR(png, info, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

	if (bit_depth == 16)
		png_set_strip_16(png);

	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);

	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png);

	if (!(color_type & PNG_COLOR_MASK_ALPHA))
		png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);

	if (color_type == PNG_COLOR_TYPE_GRAY ||
		color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png);

	png_read_update_info(png, info);

	png_bytep* rows = new png_bytep[(size_t)height];
	size_t row_bytes = (size_t)png_get_rowbytes(png, info);
	for (size_t y = 0; y < (size_t)height; y++)
		rows[y] = new png_byte[row_bytes];
	png_read_image(png, rows);

	this->image_size.x = (int)width;
	this->image_size.y = (int)height;
	this->pixels.clear();
	this->pixels.reserve((size_t)width * (size_t)height);
	for (size_t y = 0; y < (size_t)height; y++) {
		png_bytep row = rows[y];
		for (size_t x = 0; x < (size_t)width; x++) {
			png_bytep px = &row[x * 4];
			unsigned char r, g, b, a;
			r = px[0];
			g = px[1];
			b = px[2];
			a = px[3];
			Color color = {
				(float)r / 255.0f,
				(float)g / 255.0f,
				(float)b / 255.0f,
				(float)a / 255.0f
			};
			this->pixels.push_back(color);
		}
	}

	for (size_t y = 0; y < (size_t)height; y++)
		delete[] rows[y];
	delete[] rows;
	png_destroy_read_struct(&png, &info, NULL);
	fclose(file);
}

