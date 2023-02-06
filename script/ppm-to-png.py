#* CS100-Ray-Tracing for course recitation.
#* Converting .ppm file to .png file.
#* 
#* Copyright (C) 2023
#* Author: Haizhao Dai
#* Email: daihzh@shanghaitech.edu.cn
#* 
#* This program is free software: you can redistribute it and/or modify
#* it under the terms of the GNU General Public License as published by
#* the Free Software Foundation, either version 3 of the License, or
#* (at your option) any later version.
#* 
#* This program is distributed in the hope that it will be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#* GNU General Public License for more details.
#* 
#* You should have received a copy of the GNU General Public License
#* along with this program.  If not, see <http://www.gnu.org/licenses/>.

import sys

from PIL import Image
import numpy as np

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Invalid arguments. Usage python image.py <ppm_name>")
        exit(1)

    with open(sys.argv[1], encoding="utf-8") as f:
        # Read out ppm type.
        f.readline()
        # Read out image size.
        width, height = list(map(int, f.readline().split(' ')))
        # Read out color bit depth.
        f.readline()
        # Read data.
        data = list(map(
            lambda x: list(map(int, x)),
            map(lambda x: x.split(' '), f.readlines())
        ))
    image = np.array(data).reshape((width, height, 3)).astype(np.uint8)

    output = sys.argv[1].replace(".ppm", ".png")
    Image.fromarray(image).save(output)
    print("Saved image as {}".format(output))
