/*******************************************************************************
 * Project Ips4o Benchmark Suite
 *
 * src/benchmark/benchmark_raduls.cpp
 *
 * RADULS benchmark.
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

#include "../algorithm/raduls.hpp"
#include "../benchmark.hpp"
#include "../name_extractor.hpp"

using Algorithm = Sequence<true, stdthread::Raduls>;

int main(int argc, char *argv[]) {
    Config config = readParameters(argc, argv, NameExtractor<Algorithm>());
    benchmark<Algorithm>(config);
    return 0;
}
