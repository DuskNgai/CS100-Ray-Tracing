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
#include <stdlib.h>

#include "integrator.h"

int main() {
    // TODO: replace by parsing command line arguments/configuration files.
    uint32_t image_width = 0, image_height = 0;
    fprintf(stderr, "Image width you want: ");
    if (scanf("%u", &image_width) != 1) {
        fprintf(stderr, "[Error] Invalid image_width, process terminate.\n");
        return 1;
    }
    fprintf(stderr, "Image height you want: ");
    if (scanf("%u", &image_height) != 1) {
        fprintf(stderr, "[Error] Invalid image_height, process terminate.\n");
        return 1;
    }
    if (image_width > 2048 || image_height > 2048) {
        fprintf(stderr, "[Error] The image is too large to create, process terminate.\n");
        return 1;
    }

    fprintf(stderr, "The image size is %u x %u pixels.\n", image_width, image_height);
    // Create the camera.
    Camera* camera = camera_create(
        (Point3f){ 0.0, 0.0, 0.0 },
        (Point3f){ 0.0, 0.0, -1.0 },
        (Vector3f){ 0.0, 1.0, 0.0 },
        (Float)90.0,
        (Float)1.0,
        film_create(image_width, image_height));

    // Create the scene.
    Scene* scene = scene_create(2);
    Sphere* s1 = (Sphere*)malloc(sizeof(Sphere));
    s1->center = (Point3f){ 0.0, 0.0, -1.0 };
    s1->radius = 0.5;
    Sphere* s2 = (Sphere*)malloc(sizeof(Sphere));
    s2->center = (Point3f){ 0.0, -100.5, -1.0 };
    s2->radius = 100.0;
    scene_add_object(scene, s1, 0);
    scene_add_object(scene, s2, 1);

    // Render the image.
    render(camera, scene);
    fprintf(stderr, "\nRendering done, outputing image.\n");
    film_save(camera->film);
    fprintf(stderr, "Done!\n");

    scene_destroy(scene);
    film_destroy(camera->film);
    camera_destroy(camera);
    return 0;
}
