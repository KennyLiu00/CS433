# Producer-Consumer Problem
First, you should get the starter code for the assignment from the GitHub repository csusm-cs/cs433_assign_starter (github.com) (Links to an external site.). The starter code of assignment 4 is under the directory "assign4". Your program should be based on the starter code. 

This assignment is based on programming project 4 "The Producer-Consumer Problem" in chapter 7 of the textbook Links to an external site..

# Starter Code
**buffer.h and .cpp**: A Buffer class with bounded size. The number of items in the buffer cannot exceed the size of the buffer. Complete its implementation in the buffer.h and buffer.cpp file. 

**main.cpp**: The main program to create and synchronize multiple producer and consumer threads. Complete its implementation, especially correct synchronization code in the producer and consumer thread function.

# Required Output
You should solve the producer-consumer problem using the PThread API. You need to include <pthread.h> header file and link the PThread library using "-lpthread".

Your program should allow creating multiple producer and consumer threads. Three parameters are passed on the command line:

1. How long does the main thread sleep before terminating (in seconds)
2. The number of producer threads
3. The number of consumer threads

Type make to build the executable prog4 using included Makefile. Then run the executable with three command-line argument, e.g.,

	./prog4 10 3 2

creates three producers and two consumer threads and allows the main thread to sleep for 10 seconds before exiting. Each producer would have a unique ID starting at 1, passed as the parameter into its thread function. For example, the three producers in the upper example would have IDs 1, 2, and 3, respectively. Each producer would insert its own ID into the buffer. For example, thread 1 will insert 1; thread 2 will insert 2, and so on. Whenever a producer adds an item or a consumer removes an item from the buffer, it should print out a message and the current content of the buffer. An example output in "example_out.txt" looks like

	Producer 1: Inserted item 1
	Buffer: [1]
	Producer 1: Inserted item 1
	Buffer: [1, 1]
	Consumer Removed item 1
	Buffer: [1]
	Producer 3: Inserted item 3
	Buffer: [1, 3]
	Consumer Removed item 1
	Buffer: [3]
	Producer 2: Inserted item 2
	Buffer: [3, 2]
	Producer 2: Inserted item 2
	Buffer: [3, 2, 2]
	Producer 3: Inserted item 3
	Buffer: [3, 2, 2, 3]
	Consumer Removed item 3
	Buffer: [2, 2, 3]
	Consumer Removed item 2
	Buffer: [2, 3]
	Producer 1: Inserted item 1
	Buffer: [2, 3, 1]

The items should be removed in their order of being added, i.e. FIFO. The producer and consumer threads sleep for some random time under one second, using the usleep() function like “usleep(rand()%1000000);”, as the usleep() function allows a thread to sleep for some number of microseconds.

Instead of using semaphores in the main program, note it's possible to make the Buffer into a monitor by using mutex and condition variables inside its implementation. 

# Submission
Complete all the TODOs in the starter code and remove TODOs from the comments. You need to submit the following required source code files and the report file (in PDF format) for Assignment 4 on the GradeScope . 

- buffer.h
- buffer.cpp
- main.cpp
