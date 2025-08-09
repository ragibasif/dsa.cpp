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

#include "Vector.hpp"
#include "thirdparty/dbg.h"

#include <iostream>

void generate_subsets( std::vector<int> subset, int start, int end ) {
    if ( start == end + 1 ) {
        dbg( subset, subset.size() );
        // for ( int i = 0; i < subset.size(); i++ ) {
        //     std::cout << subset[i] << " ";
        // }
        // std::cout << "\n";
    } else {
        // include start in the subset
        subset.push_back( start );
        generate_subsets( subset, start + 1, end );
        subset.pop_back();
        // don't include start in the subset
        generate_subsets( subset, start + 1, end );
    }
}

int main( void ) {

    Vector v( 10 );
    for ( int i = 0; i < 10; i++ ) { v.set( i, i ); }
    v.print();

    auto result = v.find( 5 );
    if ( result.has_value() ) {
        std::cout << "Found at index: " << *result << "\n";
    } else {
        std::cout << "Value not found.\n";
    }

    result = v.find( 55 );
    if ( result.has_value() ) {
        std::cout << "Found at index: " << *result << "\n";
    } else {
        std::cout << "Value not found.\n";
    }

    std::vector<int> subset;
    generate_subsets( subset, 0, 3 );

    std::cerr << std::endl
              << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec"
              << std::endl;

    return EXIT_SUCCESS;
} // main
