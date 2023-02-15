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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int image_width = 256, image_height = 256;

	printf("P3\n%d %d\n255\n", image_width, image_height);

	for (int j = 0; j < image_height; ++j) {
		for (int i = 0; i < image_width; ++i) {
			// [0, W - 1] -> [0.0, 1.0]
			double r = (double)i / (double)(image_width - 1);
			double g = (double)j / (double)(image_height - 1);
			double b = 0.25;

			// [0.0, 1.0] -> [0, 255]
			int ir = (int)(255.0 * r);
			int ig = (int)(255.0 * g);
			int ib = (int)(255.0 * b);

			printf("%d %d %d\n", ir, ig, ib);
		}
	}
	return 0;
}
