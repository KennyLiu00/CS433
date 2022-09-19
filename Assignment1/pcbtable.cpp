/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Kyrstn Hall and Elaeth Lilagan
 * @brief This is the implementation file for the PCBTable class.
 * // Remember to add sufficient comments to your code
 */

/*
REFERENCES USED IN THIS ASSIGNMENT

https://en.cppreference.com/w/cpp/container/vector
https://www.tutorialspoint.com/advantages-of-vector-over-the-array-in-cplusplus#:~:text=Vector%20are%20implemented%20as%20dynamic,with%20primitive%20data%20type%20interface.

*/

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
  //setting the capacities for the following elements
  processes.resize(size); //sizes available inside the table (array pointer)
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
  for (int i = 0; i < size; i++) { // deletes PCBs pointed and points to NULL
    delete processes[i]; //delete the following elements inside the array
    processes[i] = NULL; //set to NULL once the array has been deleted
  }
  processes.clear(); //clear the array
  size = 0; //set to 0 since nothing is left
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
  return processes[idx]; // get the following element in given index
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */

void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
  processes.insert(processes.begin()+idx, pcb);  // iterator starts at front and ends at index PCB is to be placed at
  size++; // increment since we are adding a PCB
}
