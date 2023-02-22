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

#include <stdio.h>
#include <stdint.h>

typedef float Float;

int main() {
	uint32_t image_width = 256, image_height = 256;

	// Render the image.
	// Output the image.
	printf("P3\n%u %u\n255\n", image_width, image_height);
	for (uint32_t j = 0; j < image_height; ++j) {
		for (uint32_t i = 0; i < image_width; ++i) {
			// [0, W - 1] -> [0.0, 1.0]
			Float r = (Float)i / (Float)(image_width - 1);
			Float g = (Float)j / (Float)(image_height - 1);
			Float b = (Float)0.25;

			// [0.0, 1.0] -> [0, 255]
			uint8_t ir = (uint8_t)(255.0 * r);
			uint8_t ig = (uint8_t)(255.0 * g);
			uint8_t ib = (uint8_t)(255.0 * b);

			printf("%u %u %u\n", ir, ig, ib);
		}
	}
	return 0;
}
