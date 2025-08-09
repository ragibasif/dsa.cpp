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
        memset( buffer, 0, capacity );
    }

    ~DA() {
        delete[] buffer;
        buffer   = nullptr;
        size     = 0;
        capacity = 0;
    }

    int get( int index ) {
        if ( index >= size || index < 0 ) {
            throw std::out_of_range( "Index is out of range." );
        }
        return buffer[index];
    }

    void set( int index, int value ) {
        if ( index >= size || index < 0 ) {
            throw std::out_of_range( "Index is out of range." );
        }
        buffer[index] = value;
    }

    void print() {
        for ( int i = 0; i < size; i++ ) { std::cout << buffer[i] << " "; }
        std::cout << "\n";
    }

    int find( int value ) {
        for ( int i = 0; i < size; i++ ) {
            if ( buffer[i] == value ) { return i; }
        }
        return -1;
    }

    void resize() {
        capacity *= 2;
        int *temp_buffer = new int[capacity];
        memset( temp_buffer, 0, capacity );
        for ( int i = 0; i < size; i++ ) { temp_buffer[i] = buffer[i]; }
        delete[] buffer;
        buffer      = temp_buffer;
        temp_buffer = nullptr;
    }

    int  first() { return buffer[0]; }
    int  last() { return buffer[size - 1]; }
    void push_back( int value );
    void pop_back();
    void push_front( int value );
    void pop_front();
};

#endif // DA_H_
