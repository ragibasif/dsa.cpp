/*
 * File: test_da.cpp
 * Author: Ragib Asif
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#include "test_da.hpp"

#include "da.hpp"

#include <cassert>
#include <iostream>

void test_da() {
    lexicon::da<int> v;
    for ( int i = 0; i < 10; i++ ) { v.push_back( i ); }
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

    v.push_front( 99 );
    v.print();
    v.pop_front();
    v.print();
}
