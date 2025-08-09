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

int main( void ) {

    DA v( 10 );
    for ( int i = 0; i < 10; i++ ) { v.set( i, i ); }
    v.print();
    std::cout << v.find( 5 ) << " " << v.find( 55 );

    std::cerr << std::endl
              << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec"
              << std::endl;

    return EXIT_SUCCESS;
} // main
