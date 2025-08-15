/*
 * File: main.cpp
 * Author: Ragib Asif
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#include "test_vector.hpp"

#include <chrono>
#include <iostream>

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    test_vector();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_vec = end - start;
    std::cout << "Finished in: " << duration_vec.count() << std::endl;

    return EXIT_SUCCESS;
}
