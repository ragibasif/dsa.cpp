/*
 * File: vector.hpp
 * Author: Ragib Asif
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <iostream>
#include <optional>
#include <stdexcept>

namespace dsa {

constexpr size_t DEFAULT_SIZE     = 0;
constexpr size_t DEFAULT_CAPACITY = 0;
constexpr size_t GROWTH_FACTOR    = 2;

template <typename T>
class vector {
  private:
    T     *buffer_;
    size_t size_;
    size_t capacity_;

    void bounds_check( int index ) {
        if ( index < 0 || index >= size_ ) {
            throw std::out_of_range( "Index is out of range." );
        }
    }

  public:
    // Default constructor - Creates an empty vector with no elements.
    vector() : size_( DEFAULT_SIZE ), capacity_( DEFAULT_CAPACITY ) {
        buffer_ = new T[capacity_];
    }

    // Fill constructors - Creates a vector with a given size and
    // optionally an item to fill every element.
    vector( int size ) {
        if ( size < 0 ) { return vector(); }
        size_     = size;
        capacity_ = size_ * GROWTH_FACTOR;
        buffer_   = new T[capacity_]{};
    }

    vector( int size, T item ) {
        if ( size < 0 ) { return vector(); }
        size_     = size;
        capacity_ = size_ * GROWTH_FACTOR;
        buffer_   = new T[capacity_]{};
        for ( size_t i = 0; i < size_; i++ ) { buffer_[i] = item; }
    }

    // Destructor - Frees any dynamically allocated memory and calls
    // element destructors.
    ~vector() {
        delete[] buffer_;
        buffer_   = nullptr;
        size_     = 0;
        capacity_ = 0;
    }

    // TODO: Range constructor - Creates a vector from a range of
    // iterators (copies all elements from another container/range).

    // TODO: Copy constructor - Creates a vector as a copy of another
    // vector.

    // TODO: Move constructor - Creates a vector by moving the resources
    // of another vector without copying (leaves the other empty).

    // TODO: Initializer list constructor - Creates a vector from an
    // initializer list, e.g., {1, 2, 3}.

    // TODO: Copy assignment (operator=) - Replaces contents with a copy of
    // another vector.

    // TODO: Move assignment (operator=) - Replaces contents by taking over the
    // resources of another vector.

    // TODO: Initializer list assignment - Replaces contents with the values
    // from an initializer list.

    // TODO: operator[] - Provides unchecked access to an element at a given
    // index.

    void print() {
        for ( size_t i = 0; i < size_; i++ ) { std::cout << buffer_[i] << " "; }
        std::cout << "\n";
    }

    std::optional<size_t> find( const T item ) {
        for ( size_t i = 0; i < size_; i++ ) {
            if ( buffer_[i] == item ) { return i; }
        }
        return std::nullopt; // not found
    }

    // at() - Accesses an element at a given index but throws an exception
    // if the index is out of range.
    const T at( int index ) {
        bounds_check( index );
        return buffer_[index];
    }

    // front() - Returns a reference to the first element.
    const T &front() { return &buffer_[0]; }

    // back() - Returns a reference to the last element.
    const T &back() { return &buffer_[size_ - 1]; }

    // data() - Returns a pointer to the underlying raw array.
    const T *data() { return *buffer_; }

    // empty() - Returns whether the vector has no elements.
    const bool empty() { return size_ > 0; }

    // size() - Returns the number of elements currently in the
    // vector.
    const size_t size() { return size_; }

    // TODO: max_size() - Returns the maximum number of elements that can be
    // held (theoretical limit).

    // capacity() - Returns the current number of elements the vector
    // can hold without reallocating.
    const size_t capacity() { return capacity_; }

    // TODO: reserve() - Increases the capacity to at least a given item,
    // avoiding repeated allocations.

    // TODO: shrink_to_fit() -  Requests to reduce capacity to match current
    // size.

    // clear() - Removes all elements (capacity usually remains
    // unchanged).
    void clear() { size_ = 0; }

    // TODO: insert() - Inserts elements at a specific position (can insert a
    // single element, multiple, or a range).

    // TODO: emplace() - Constructs an element in place at a specific position.

    // push_back() - Appends a copy of an element to the end.
    void push_back( const T item ) {
        if ( size_ == capacity_ ) { resize(); }
        buffer_[size_++] = item;
    }

    // TODO: emplace_back() - Constructs an element directly at the end without
    // copying.

    // pop_back() - Removes the last element.
    void pop_back() {
        if ( size_ == 0 ) { return; }
        size_--;
    }

    // TODO: erase() - Removes an element or range of elements from specific
    // positions.

    // FIX: resize() - Changes the size of the vector (either truncates
    // or appends default-initialized elements).
    void resize() {
        if ( capacity_ == 0 ) { capacity_++; }
        capacity_ *= GROWTH_FACTOR;
        T *temp_buffer = new T[capacity_];
        for ( size_t i = 0; i < size_; i++ ) { temp_buffer[i] = buffer_[i]; }
        std::swap( buffer_, temp_buffer );
        delete[] temp_buffer;
        temp_buffer = nullptr;
    }

    // push_front() - Appends a copy of an element to the front by shifting all
    // items to the right by one. Time: O(N)
    void push_front( const T item ) {
        push_back( item );
        for ( size_t i = size_ - 1; i > 0; i-- ) {
            buffer_[i] = buffer_[i - 1];
        }
        buffer_[0] = item;
    }

    // pop_front() - Removes the first element by shifting all items to the left
    // by one. Time: O(N)
    void pop_front() {
        for ( size_t i = 0; i < size_ - 1; i++ ) {
            buffer_[i] = buffer_[i + 1];
        }
        size_--;
    }

    // TODO: begin() / end() - Returns iterators to the start and one past the
    // last element.

    // TODO: cbegin() / cend() - Same as above, but returns constant iterators.

    // TODO: rbegin() / rend() - Reverse iterators for iterating from the end to
    // the start.

    // TODO: crbegin() / crend() - Constant reverse iterators.

    // TODO: swap() - Exchanges the contents with another vector in
    // constant time.

    // TODO: operator==, operator!=, operator<, operator<=, operator>,
    // operator>= - Compare vectors lexicographically or for equality.

    // TODO: get_allocator() - Returns the allocator object used for memory
    // management.
};

} // namespace dsa

#endif // VECTOR_HPP
