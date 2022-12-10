# Page Replacement Algorithms
In this assignment, you will implement a page table and analyze different page replacement algorithms, assuming a single running process and a fixed-size physical memory.
# Starter Code
The starter code contains the following files:

**pagetable.h and .cpp**: It defines a "PageTable" class, which is just an array of Page Entries.  Each page entry has a frame number, valid bit and dirty bit (not used in this assignment). Remember the virtual page number is the index to the array. You need to complete the implementation of the PageTable in the pagetable.cpp file.

**replacement.h and .cpp**: It defines a "Replacement" class, the base class of the classes that implement specific replacement algorithms. You will need to add additional member variables to keep track of the statistics, such as number-of-page-faults and number-of-page-replacements, etc. Then complete the  replacement.cpp file, especially the access_page function. The access_page function simulates the access by a single page number. If the page is found to be in memory, i.e. the corresponding page entry is valid, it calls the touch_page function; if the page isn't in memory but there are still free frames available, it would call the load_page function; if the page isn't in memory and there isn't any free frame, it then calls the replace_page function. The touch_page, load_page and replace_page are virtual functions that can be overridden for different replacement algorithms in the subclasses. 

**fifo_replacement.h and .cpp**: FIFOReplacement is a subclass of the Replacement, and implements the FIFO page replacement algorithm. You will need to complete its constructor and destructor, and override the functions load_page and replace_page. 

**lifo_replacement.h and .cpp**: LIFOReplacement is a subclass of the Replacement, and implements the LIFO(Last in first out) page replacement algorithm. It replaces a page that was last loaded into the memory. It isn't a good replacement algorithm and Let's see how bad it is. You will need to complete its constructor and destructor, and override the functions load_page and replace_page. 

**lru_replacement.h and .cpp**: LRUReplacement is a subclass of the Replacement, and implements the LRU page replacement algorithm. You will need to complete its constructor and destructor, and override the functions touch_page, load_page and replace_page. 

**main.cpp**: The driver program tests the implementation of the page table and replacement algorithms. Test 1 using a "small_refs.txt" file has been written. You need to complete test 2 for the three replacement algorithms using a "large_refs.txt" file.  See below for more info about the tests. The results of tests should match example outputs in the "example_out.txt".
# Overview
Your program should support at least three page-replacement policies: FIFO, LIFO, and LRU. Assume that when it starts, the physical memory is empty, i.e. all page table entries are invalid. As they are brought in, the program should ensure that the total number of pages in memory should never exceed the physical memory size.

Your program should keep track of pages in the memory and free frames. Therefore, you need to maintain a page-table data structure, which can be easily implemented as an array of page entries. The size of the array equals the number of pages in the logical memory. The page entry data structure may contain the mapped frame number of the page, valid bit, and dirty bit, etc. For each memory reference, calculate its page number and check whether this page is in the main memory by looking up the page table. If this page is not in the main memory, a page fault is generated, the missing page is loaded into the main memory, and the page table is updated. However, if the main memory is full, i.e., no more free frames, a victim page must be selected and evicted according to a page replacement algorithm. Your program compares different page replacement algorithms in terms of the total number of page faults. Notice you will need to keep track of additional information in the implementations, such as the last page access time for the LRU (least recently used) algorithm.

The program should accept the page size and physical memory size (# of address bits) as command-line arguments. The page size must be a power of 2 between 256 (2^8) and 8192 (2^13) bytes inclusively. The physical memory size is also a power of 2 between 4 (2^22) and 64 (2^26) MB. Using the provided Makefile, you just type "make" to build the executable "prog5". Then run "prog5" with command-line arguments, for example
    
    ./prog5 1024 32
    
simulates a system with page size = 1024 bytes and 32 MB physical memory. You should thoroughly test your program with multiple configurations of different page sizes (256 - 8192 bytes) and physical memory sizes (e.g. 4 MB, 16 MB, 32 MB, 64 MB), and then present and analyze the data results in the report.

The program reads a sequence of logical memory references from a text file, which contains virtual (logical) byte addresses. In this assignment, the maximum virtual memory address is assumed to be 128 MB (2^27 bytes). Given a byte address, the page number can be computed by dividing it with the page size.  For example, given logical address 2000 and page size 1024,

     page number = 2000/1024 = 2000/2^(10) = 1

with a page offset = 976, which is irrelevant for this simulation. Since page sizes are always a power of 2, the page number can be quickly calculated using the shift operator. 
# Required Output
 - The first test checks the implementation of the page table.  It reads and runs the simulation for a small list of logical addresses (“small_refs.txt”). Assuming an initial empty physical memory, for each logical address in the list, it prints out its logical page #, physical frame #, and whether it caused a page fault or not. The output should match with that in "example_out.txt" for the example parameters for the page size and physical memory size.
 - In the second test, assuming an initial empty physical memory, your program should read and run the simulation for a large list of logical addresses (“large_refs.txt”), and collect and print the following statistics for different algorithms:
      - The total number of memory references.
      - The total number of page faults.
      - The total number of page replacements.
      - The total time it took to produce the results.
      - The number of page faults and replacements should match with that in "example_out.txt" for the example parameters.
  
In the report, you should discuss your implementation and present the results of simulations for multiple configurations of page sizes (256 - 8192 bytes) and physical memory sizes (e.g. 4 MB, 16 MB, 32 MB, 64 MB). You can use tables or graphs to compare the number of page faults and run time of simulated page replacement algorithms.

# Extra Credits
You can earn 10-point extra credits if you have an efficient implementation of the LRU replacement algorithm that runs correctly and under 1 second. We will use a page size of 1024 bytes and a physical memory size of 32 MB to measure the performance of the submitted programs.
# Submission
-  fifo_replacement.h  
-  lru_replacement.h  
-  lifo_replacement.h  
-  replacement.h
-  fifo_replacement.cpp  
-  lru_replacement.cpp  
-  lifo_replacement.cpp  
-  replacement.cpp
-  pagetable.h
-  pagetable.cpp
-  main.cpp
-  Report
