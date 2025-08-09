/*
 * File: da.h
 * Author: Ragib Asif
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#ifndef DA_H_
#define DA_H_

#include <iostream>
#include <stdexcept>

class DA {
  private:
    int *buffer   = nullptr;
    int  size     = 0;
    int  capacity = 0;

  public:
    DA( int size = 0 ) : size( size ) {
        if ( size < 0 ) {
            throw std::invalid_argument( "Size cannot be less than zero!" );
        }
        capacity = size * 2;
        buffer   = new int[capacity]{};
    }
    ~DA() {
        delete[] buffer;
        buffer   = nullptr;
        size     = 0;
        capacity = 0;
    }
};

#endif // DA_H_
