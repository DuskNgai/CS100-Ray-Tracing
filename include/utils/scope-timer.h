/*
 * CS100-Ray-Tracing for course recitation.
 * The definition of a simple timer.
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

#ifndef _CS100_RAY_TRACING_UTILS_SCOPE_TIMER_H_
#define _CS100_RAY_TRACING_UTILS_SCOPE_TIMER_H_

#include <chrono>
#include <iostream>

#include "common.h"

CS100_RAY_TRACING_NAMESPACE_BEGIN

/// @tparam The elapsed time in milliseconds.
template <typename duration_t = std::chrono::milliseconds>
class ScopeTimer {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time{};

public:
    ScopeTimer()
        : start_time(std::chrono::steady_clock::now()) {}
    ScopeTimer(ScopeTimer const&) = delete;
    ScopeTimer(ScopeTimer&&) = delete;
    ScopeTimer& operator=(ScopeTimer const&) = delete;
    ScopeTimer& operator=(ScopeTimer&&) = delete;
    ~ScopeTimer() {
        auto end_time = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<duration_t>(end_time - start_time);
        std::cout << "Elapsed time: " << elapsed_time.count() << " ms" << std::endl;
    }
};

CS100_RAY_TRACING_NAMESPACE_END

#endif // !_CS100_RAY_TRACING_UTILS_SCOPE_TIMER_H_
