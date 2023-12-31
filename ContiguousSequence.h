// Quang Le
// Project 3
// CS 474
// ContiguousSequence.h file

#ifndef CONTIGUOUSSEQUENCE_H
#define CONTIGUOUSSEQUENCE_H

class ContiguousSequence {
public:
    // Default constructor
    ContiguousSequence();

    // Constructor with an initial element
    ContiguousSequence(int value);

    // Copy constructor
    ContiguousSequence(const ContiguousSequence& other);

    // Destructor
    ~ContiguousSequence();

    // Assignment operator
    ContiguousSequence& operator=(const ContiguousSequence& other);

    // Return the current capacity of the contiguous sequence
    int basicSize() const;

    // Return the number of elements in the contiguous sequence
    int size() const;

    // Indexing operator (non-const version) with bounds checking
    int& operator[](int index);

    // Indexing operator (const version) with bounds checking
    const int& operator[](int index) const;

    // Insert an element at a specific index
    ContiguousSequence& insertAt(int index, int value);

    // Find the index of a specific element in the contiguous sequence
    int find(int value) const;

    // Remove an element at a specific index
    ContiguousSequence& removeAt(int index);

    // Apply a function to each element in the contiguous sequence
    ContiguousSequence& iterate(int (*fn)(int));

    //optional 
    // getter and setter 
    int getStart() {
        return this->start;
    }
    
    void setStart(int start){
        this->start = start;
    }

    int getEnd() {
        return this->end;
    } 

    void setEnd(int end){
        this->end = end;
    }


private:
    // Pointer to the dynamically allocated sequence
    int* sequence;

    // Current capacity of the contiguous sequence
    int capacity;

    // Start index of the region storing elements
    int start;

    // End index of the region storing elements
    int end;

    // Non-public method to dynamically allocate a larger storage region
    void grow();
};

#endif // CONTIGUOUSSEQUENCE_H
