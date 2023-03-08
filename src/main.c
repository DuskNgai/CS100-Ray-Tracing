/*
 * CS100-Ray-Tracing for course recitation.
 * The entrypoint of the program.
 *
 * Copyright (C) 2023
 * Author: Haizhao Dai
 * Email: daihzh@shanghaitech.edu.cn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// TODO: remove this after introducing CMake.
#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <stdio.h>

#include "integrator.h"

int main() {
	uint32_t image_width, image_height;

	fprintf(stderr, "Image width you want: ");
	if (scanf("%u", &image_width) != 1) {
		fprintf(stderr, "[Error] Invalid image_width, process terminate\n.");
		return 1;
	}

	fprintf(stderr, "Image height you want: ");
	if (scanf("%u", &image_height) != 1) {
		fprintf(stderr, "[Error] Invalid image_height, process terminate\n.");
		return 1;
	}

	if (image_width > 2048 || image_height > 2048) {
		fprintf(stderr, "[Error] Image size too large, process terminate\n.");
		return 1;
	}

	fprintf(stderr, "The image size is %u x %u pixels.\n", image_width, image_height);

	// Create a film.
	Film* film = film_create(image_width, image_height);

	// Render the image.
	render(film);

	film_save(film);
	fprintf(stderr, "Image saving done!\n");

	film_destroy(film);
	return 0;
}
