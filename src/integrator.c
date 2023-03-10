/*
 * CS100-Ray-Tracing for course recitation.
 * The implementation of the integrator, which calculate the radiance of a ray.
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

#include "integrator.h"

#include <stdio.h>

#include "math-utils.h"
#include "vector3.h"

void render(Film const* film) {
	for (uint32_t j = 0; j < film->height; ++j) {
		fprintf(stderr, "\rScanlines remaining: %u ", film->height - j - 1);
		fflush(stderr);

		for (uint32_t i = 0; i < film->width; ++i) {
			// [0, W - 1] -> [0.0, 1.0]
			Float r = (Float)i / (Float)(film->width - 1);
			Float g = (Float)j / (Float)(film->height - 1);
			Float b = (Float)0.25;

			film_set_pixel(film, i, j, (Color3f){r, g, b});
		}
	}
	fprintf(stderr, "\nRendering done.\n");
}
