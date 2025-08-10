/*
 * File: da.hpp
 * Author: Ragib Asif
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#ifndef DA_HPP
#define DA_HPP

#include <iostream>
#include <optional>
#include <stdexcept>

namespace dsa {

class da {
  private:
    int   *buffer   = nullptr;
    size_t size     = 0;
    size_t capacity = 0;

  public:
    da( size_t size = 0 ) : size( size ) {
        capacity = size * 2;
        buffer   = new int[capacity]{};
        memset( buffer, 0, capacity );
    }

    ~da() {
        delete[] buffer;
        buffer   = nullptr;
        size     = 0;
        capacity = 0;
    }

    int get( size_t index ) {
        if ( index >= size ) {
            throw std::out_of_range( "Index is out of range." );
        }
        return buffer[index];
    }

    void set( size_t index, int value ) {
        if ( index >= size ) {
            throw std::out_of_range( "Index is out of range." );
        }
        buffer[index] = value;
    }

    void print() {
        for ( size_t i = 0; i < size; i++ ) { std::cout << buffer[i] << " "; }
        std::cout << "\n";
    }

    std::optional<size_t> find( int value ) {
        for ( size_t i = 0; i < size; i++ ) {
            if ( buffer[i] == value ) { return i; }
        }
        return std::nullopt; // not found
    }

    // TODO: this needs to be tested
    void resize() {
        capacity *= 2;
        int *temp_buffer = new int[capacity];
        memset( temp_buffer, 0, capacity );
        for ( size_t i = 0; i < size; i++ ) { temp_buffer[i] = buffer[i]; }
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
    void insert( size_t index, int value );
    void remove( size_t index );
    void sort();
    void right_rotate( size_t count );
    void left_rotate( size_t count );
    void shuffle();
};

} // namespace dsa

#endif // DA_HPP
