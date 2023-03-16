/*
 * CS100-Ray-Tracing for course recitation.
 * A common header for other files to use, which need to be included in all files directly or indirectly.
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

#ifndef _CS100_RAY_TRACING_COMMON_H_
#define _CS100_RAY_TRACING_COMMON_H_

#define CS100_RAY_TRACING_NAMESPACE_BEGIN namespace CS100 {
#define CS100_RAY_TRACING_NAMESPACE_END }

CS100_RAY_TRACING_NAMESPACE_BEGIN

struct Interaction;
struct Material;

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_COMMON_H_
