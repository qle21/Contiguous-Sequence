// Quang Le
// Project 3
// CS 474
// ContiguousSequence.cpp file

#include "ContiguousSequence.h"
#include <iostream>
using namespace std;

// Default constructor
ContiguousSequence::ContiguousSequence() {
    capacity = 8;
    sequence = new int[capacity];
    start = 3;
    end = 2;
}

// Constructor with an initial element
ContiguousSequence::ContiguousSequence(int value) : ContiguousSequence() {
    sequence[start] = value;
    end++;
}

// Copy constructor
ContiguousSequence::ContiguousSequence(const ContiguousSequence& other) {
    // Deep copy of the other object
    capacity = other.capacity;
    sequence = new int[capacity];
    start = other.start;
    end = other.end;

    for (int i = start; i <= end; i++) {
        sequence[i] = other.sequence[i];
    }
}

// Destructor
ContiguousSequence::~ContiguousSequence() {
    // Destructor to avoid memory leaks
    delete[] sequence;
}

// Assignment operator
ContiguousSequence& ContiguousSequence::operator=(const ContiguousSequence& other) {
    // Assignment operator for deep copy
    if (this != &other) {
        delete[] sequence;

        capacity = other.capacity;
        sequence = new int[capacity];
        start = other.start;
        end = other.end;

        for (int i = start; i <= end; i++) {
            sequence[i] = other.sequence[i];
        }
    }
    return *this;
}

// Return the current capacity of the contiguous sequence
int ContiguousSequence::basicSize() const {
    return capacity;
}

// Return the number of elements in the contiguous sequence
int ContiguousSequence::size() const {
    return end - start + 1;
}

// Indexing operator (non-const version) with bounds checking
int& ContiguousSequence::operator[](int index) {
    if (index < 0 || index >= size()) {
        throw out_of_range("Error out of bounds");
         //cout"Error out of bounds"; // uncomment if you want to only print error 
    }
    return sequence[start + index];
}

// Indexing operator (const version) with bounds checking
const int& ContiguousSequence::operator[](int index) const {
    if (index < 0 || index >= size()) {
        throw out_of_range("Error out of bounds");
        //cout"Error out of bounds"; // uncomment if you want to only print error 
    }
    return sequence[start + index];
}

// Insert an element at a specific index
ContiguousSequence& ContiguousSequence::insertAt(int index, int value) {
    // if no element or out of bound
    if (index < 0 || index > size()) {
        cout << "Error out of bounds" << endl;
        //throw out_of_range("Error out of bounds");// uncomment if you want to stop and throw error 
        return *this;
    }
    
    // double memory size  
    if (size() == capacity) {
        grow();
    }

    // Handle different insertion scenarios
    if (index == 0) {
        if (start == 0) {
            // Shift elements to the right
            for (int i = end; i >= start; i--) {
                sequence[i + 1] = sequence[i];
            }
            end++;
        } else {
            start--;
        }
    } else if (index == size()) {
        if (end == capacity - 1) {
            // Shift elements to the left
            for (int i = start; i <= end; i++) {
                sequence[i - 1] = sequence[i];
            }
            start--;
        } else {
            end++;
        }
    } else {
        if (end == capacity - 1) {
            // Shift elements to the left
            for (int i = start + index; i <= end; i++) {
                sequence[i - 1] = sequence[i];
            }
            start--;
        } else {
            // Shift elements to the right
            for (int i = end; i >= start + index; i--) {
                sequence[i + 1] = sequence[i];
            }
            end++;
        }
    }

    sequence[start + index] = value;
    return *this;
}

// Find the index of a specific element in the contiguous sequence
int ContiguousSequence::find(int value) const {
    for (int i = start; i <= end; i++) {
        if (sequence[i] == value) {
            return i - start;
        }
    }
    return -1;
}

// Remove an element at a specific index
ContiguousSequence& ContiguousSequence::removeAt(int index) {
    if (index < 0 || index >= size()) {
        cout << "Index out of bounds" << endl;
        return *this;
    }

    // Shift elements to fill the gap caused by removal
    for (int i = start + index; i < end; i++) {
        sequence[i] = sequence[i + 1];
    }

    // Adjust start and end pointers
    if (index == 0) {
        start++;
    } else if (index == size() - 1) {
        end--;
    }

    return *this;
}

// Apply a function to each element in the contiguous sequence
ContiguousSequence& ContiguousSequence::iterate(int (*fn)(int)) {
    for (int i = start; i <= end; i++) {
        sequence[i] = fn(sequence[i]);
    }
    return *this;
}

// Non-public method to dynamically allocate a larger storage region
void ContiguousSequence::grow() {
    int newCapacity = capacity * 2;
    int* newSequence = new int[newCapacity];

    // Copy elements to the new region
    for (int i = start; i <= end; i++) {
        newSequence[i] = sequence[i];
    }

    // Deallocate old storage and update pointers
    delete[] sequence;
    sequence = newSequence;
    capacity = newCapacity;
}
