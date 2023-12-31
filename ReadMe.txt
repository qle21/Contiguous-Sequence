# ContiguousSequence Project

## Introduction
	This project implements a C++ class called `ContiguousSequence` that combines the advantages of arrays and linked lists. The class dynamically allocates contiguous storage and allows for variable size. Elements can be inserted, removed, and accessed using the provided methods.

## Compilation
	Use either the g++ or CLang compiler with the C++11 standard to compile the code.

### Compilation Command:
	g++ -std=c++11 ContiguousSequence.cpp main.cpp -o ContiguousSequence
	Then run ./ContiguousSequence

## File Structure
	- `ContiguousSequence.h`: Header file containing the class declaration.
	- `ContiguousSequence.cpp`: Implementation file containing the class methods.
	- `YourMainFile.cpp`: Your main program file that includes and uses the `ContiguousSequence` class.
	- `Makefile` (optional): You may create a Makefile for easier compilation.

## Usage
	1. Include the "ContiguousSequence.h" header file in your main program.
  	 #include "ContiguousSequence.h"


	2. Create an instance of the `ContiguousSequence` class and use its methods to manipulate the sequence of integers.
  	 ContiguousSequence mySequence;
   	// Example: Insert an element at index 0
   	mySequence.insertAt(0, 42);
  	 // Example: Access elements using the indexing operator
  	 int element = mySequence[0];
   	// Example: Remove an element at index 0
   	mySequence.removeAt(0);
   
	3. Compile your program using the recommended compilation command.

	4. Run the executable generated after compilation.

	OR 

	Run and excute the main.cpp file for sample output 

## Notes
	- Ensure that you handle exceptions appropriately when using the methods, especially indexing operations.

