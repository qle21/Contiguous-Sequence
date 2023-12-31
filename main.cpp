// Quang Le
// Project 3
// CS 474
// main.cpp file

#include "ContiguousSequence.h"
#include <iostream>
using namespace std;

void printListAndSize(const ContiguousSequence& cs) {
    cout << "Elements in the list:";
    for (int i = 0; i < cs.size(); ++i) {
        cout << " | " << cs[i];
    }
    
    if (cs.size() != 0) {
        cout << " |";
    }
    
    cout << endl;
    cout << "Entire allocated space: " << cs.basicSize() << endl;
}

void getStartAndEnd () {
    ContiguousSequence cs;
    cout << "\n+Test getter and setter:\n";
    cout << "Start is:" << cs.getStart()<< endl;
    cout << "End is:" << cs.getEnd()<< endl;
    cs.setStart(4);
    cs.setEnd(3);
    cout << "Modify Start to 4:" << cs.getStart() << endl;
    cout << "Modify End to 3:" << cs.getEnd() << endl;
}


void testDefaultConstructor() {
    ContiguousSequence cs;
    cout << "\n+Test Default Constructor:\n";
    printListAndSize(cs);

    cout << "Size: " << cs.size() << endl;
    cout << "Basic Size: " << cs.basicSize() << endl;
}

void testParameterizedConstructor() {
    ContiguousSequence cs(42);
    cout << "\n+Test Parameterized Constructor:\n";
    printListAndSize(cs);

    cout << "Size: " << cs.size() << endl;
    cout << "Basic Size: " << cs.basicSize() << endl;
}

void testCopyConstructor() {
    ContiguousSequence original;
    original.insertAt(0, 5);
    original.insertAt(1, 10);
    original.insertAt(2, 15);

    ContiguousSequence copy(original);
    cout << "\n+Test Copy Constructor:\n";
    printListAndSize(copy);

    cout << "Size: " << copy.size() << endl;
    cout << "Basic Size: " << copy.basicSize() << endl;
}

void testAssignmentOperator() {
    ContiguousSequence original;
    original.insertAt(0, 5);
    original.insertAt(1, 10);
    original.insertAt(2, 15);

    ContiguousSequence assigned;
    assigned = original;
    cout << "\n+Test Assignment Operator:\n";
    printListAndSize(assigned);

    cout << "Size: " << assigned.size() << endl;
    cout << "Basic Size: " << assigned.basicSize() << endl;
}

void testInsertAndRemove() {
    ContiguousSequence cs;
    cs.insertAt(0, 5);
    cs.insertAt(1, 10);
    cs.insertAt(2, 15);
    cs.insertAt(1, 20);

    cout << "\n+Test Insert and Remove:\n";
    printListAndSize(cs);

    cout << "Size: " << cs.size() << endl;
    cout << "Basic Size: " << cs.basicSize() << endl;

    cs.removeAt(1);
    cout << "After removeAt(1):\n";
    printListAndSize(cs);

    cout << "Size: " << cs.size() << endl;
    cout << "Basic Size: " << cs.basicSize() << endl;
}

void testIterate() {
    ContiguousSequence cs;
    cs.insertAt(0, 5);
    cs.insertAt(1, 10);
    cs.insertAt(2, 15);

    cout << "\n+Test Iterate:\n";
    cout << "Before\n";
    printListAndSize(cs);
    cout << "\nAfter\n";
    cs.iterate([](int value) { return value * 2; });
    printListAndSize(cs);

    cout << "Size: " << cs.size() << endl;
    cout << "Basic Size: " << cs.basicSize() << endl;
}



void testFind() {
    ContiguousSequence cs;
    cs.insertAt(0, 5);
    cs.insertAt(1, 10);
    cs.insertAt(2, 15);

    std::cout << "\n+Test Find:\n";
    printListAndSize(cs);

    int index = cs.find(10);
    cout << "Index of value 10: " << index << endl;

    index = cs.find(25);
    cout << "Index of value 25: " << index << endl;
}

void testBound() {
    ContiguousSequence cs;
    cs.insertAt(0, 5);
    cout << "\n+Test Throw error at index 20:\n";
    cout << "Throw error" << cs[20] << endl;
}

void testMemorysize() {
    ContiguousSequence original;
    original.insertAt(0, 5);
    original.insertAt(0, 10);
    original.insertAt(0, 15);
    original.insertAt(0, 20);
    original.insertAt(0, 25);
    original.insertAt(0, 30);
    original.insertAt(1, 35);
    original.insertAt(0, 90);
    original.insertAt(3, 45);

    ContiguousSequence assigned;
    assigned = original;
    cout << "\n+Test Double Size:\n";
    printListAndSize(assigned);

    cout << "Size: " << assigned.size() << endl;
    cout << "Basic Size: " << assigned.basicSize() << endl;
}

int main() {
    // Test Default Constructor
    testDefaultConstructor();

    // Test Parameterized Constructor
    testParameterizedConstructor();

    // Test Copy Constructor
    testCopyConstructor();

    // Test Assignment Operator
    testAssignmentOperator();

    // Test Insert and Remove
    testInsertAndRemove();

    // Test Iterate
    testIterate();

    // Test Double Memorysize
    testMemorysize();
    
    //Test Find
    testFind();
    
    //Test getter and setter 
    getStartAndEnd ();
    
    // test out bound case 
    testBound();
    

    return 0;
}
