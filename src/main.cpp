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

#include "da.h"

#include <iostream>
// #include "thirdparty/dbg.h"

int main( void ) {

    DA *v = new DA( -10 );

    std::cerr << std::endl
              << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec"
              << std::endl;

    return EXIT_SUCCESS;
} // main
