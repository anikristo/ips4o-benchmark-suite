/*******************************************************************************
 * Project Ips4o Benchmark Suite
 *
 * src/algorithm/aspasparallel.hpp
 *
 * Parallel version of the algorithm ASPAS.
 *
 * Copyright (C) 2020 Michael Axtmann <michael.axtmann@gmail.com>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see
 * <https://www.gnu.org/licenses/>.
 ******************************************************************************/

#pragma once

#include <chrono>
#include <limits>
#include <string>
#include <type_traits>

#include "../../extern/aspas_sort/include/aspas.h"

#include "../datatypes.hpp"
#include "../sequence.hpp"

namespace parallel {

class Aspasparallel {
 public:
    Aspasparallel() {}

    template <class T>
    static constexpr bool accepts() {
        return std::is_same_v<T, int>
                || std::is_same_v<T, double>
                || std::is_same_v<T, float>;
    }

    static bool isParallel() { return true; }

    static std::string name() { return "aspasparallel"; }

    template <class T, template <class T1> class Vector>
    static std::pair<double, double> sort(T* begin, T* end, size_t num_threads) {
        if (end - begin > std::numeric_limits<uint32_t>::max()) { return {0., 0.}; }
        auto comp = Datatype<T>::getComparator();
        using CompType = decltype(comp);
        if (!std::is_same_v<CompType, std::less<T>>) { return {0., 0.}; }

        auto start = std::chrono::high_resolution_clock::now();
        if (end - begin <= 1ul << 30) { aspas::parallel_sort(begin, end - begin); }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = finish - start;
        return {0, elapsed.count()};
    }
};

}  // namespace parallel
