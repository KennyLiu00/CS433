# Scheduling Algorithms

First, you should get the starter code for the assignment from the GitHub repository csusm-cs/cs433_assign_starter (github.com) (Links to an external site.). The starter code of assignment 3 is under the directory "assign3". Your program should be based on the starter code. 

# Starter Code

  - **pcb.h**: A class representing a single task. Add your names to the file header. No other changes are needed for this file.

  - **scheduler.h**: A base class for different schedulers. It defines several pure virtual functions, init, print_results, and simulate, which are implemented in the subclasses. You don't need to make changes to this file. 

  - **scheduler_fcfs.h and .cpp**: A subclass of Scheduler implements the FCFS scheduling algorithm. You need to implement its constructor, and destructor, and override the init, print_results and simulate functions. The init function initializes the scheduler with an array of incoming processes. The simulate function simulates the scheduling of processes in an FCFS ready-queue. The print_results function prints out the statistics, including the turn-around and waiting time of each process and the average turn-around and waiting time. 

  - **driver_fcfs.cpp**: A driver program tests the SchedulerFCFS class. It calls the member functions init, print_results and simulate. You don't need to change this file.
driver_sjf.cpp, scheduler_sjf.h and .cpp: Files for SJF scheduling. Use the similar instructions as the FCFS scheduling algorithm.

  - **driver_priority.cpp, scheduler_priority.h and .cpp**: Files for priority scheduling. 
  
  - **driver_rr.cpp, scheduler_rr.h and .cpp**: Files for RR scheduling.

  - **driver_priority_rr.cpp, scheduler_priority_rr.h and .cpp**: Files for priority based RR scheduling (extra credits).

# Required Output

This assignment is based on the programming project “Scheduling Algorithms” in chapter 5 the textbook Links to an external site.. Your program should implement the following scheduling algorithms:

  - First-come, first-served (FCFS), which schedules tasks in the order in which they request the CPU. 

  - Shortest-job-first (SJF), which schedules tasks in order of the length of the tasks' next CPU burst.

  - Priority scheduling, which schedules tasks based on priority. A bigger number means higher priority.

  - Round-robin (RR) scheduling, where each task runs for a time quantum (or for the remainder of its CPU burst).

As described in the textbook, you will build separate executables for different scheduling algorithms using a Makefile. For example, type "make fcfs" to build the executable "fcfs", which depends on the "scheduler_fcfs.cpp" and "driver_fcfs.cpp" files. In the "scheduler_fcfs.cpp" file, you need to implement all the member functions defined in the header file "scheduler_fcfs.h".  Complete implementations for other scheduling algorithms similarly. 

Each program should be able to read a text file of tasks, run the corresponding scheduling algorithm and print out the average turnaround and waiting time, for example, 

                   ./fcfs schedule.txt
It is assumed that all tasks arrive at the same time 0, and in the order according to the list in the input text file. An example input file “schedule.txt” is provided for testing your programs. The results of your implementation should match the "example_out.txt" for the example input file. But your program should work for any valid list of tasks following the same format and will be graded using a different input file.  Your program should print out the turn-around and waiting time of each task, and the average turn-around time and average waiting time, for example:

      T1 turn-around time = 20, waiting time = 0
      T2 turn-around time = 45, waiting time = 20
      T3 turn-around time = 70, waiting time = 45
      T4 turn-around time = 85, waiting time = 70
      T5 turn-around time = 105, waiting time = 85
      T6 turn-around time = 115, waiting time = 105
      T7 turn-around time = 145, waiting time = 115
      T8 turn-around time = 170, waiting time = 145
      Average turn-around time = 94.375, Average waiting time = 73.125
The round-robin (RR) scheduling should have another command-line argument for the time quantum, e.g.

                   ./rr schedule.txt 6
# Extra Credits
You can earn 10-point extra credits by implementing

Priority with round-robin, which schedules tasks in order of priority and uses round-robin scheduling for tasks with equal priority.
# Submission:
You need to submit the following required source code files and the report (in PDF format) for Assignment 3 on the GradeScope (Links to an external site.).

  - scheduler_fcfs.h
  - scheduler_fcfs.cpp
  - scheduler_sjf.h
  - scheduler_sjf.cpp
  - scheduler_priority.h
  - scheduler_priority.cpp
  - scheduler_rr.h
  - scheduler_rr.cpp

For the extra credits, you should also submit

  - scheduler_priority_rr.h
  - scheduler_priority_rr.cpp
