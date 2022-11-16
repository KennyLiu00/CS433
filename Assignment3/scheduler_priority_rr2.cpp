/**
* Assignment 3: CPU Scheduler
 * @file scheduler_priority_rr.cpp
 * @author  Kyrstn Hall & Elaeth Lilagan
 * @brief This Scheduler class implements the Priority RR scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_priority_rr.h"

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

SchedulerPriorityRR::SchedulerPriorityRR(int time_quantum) 
{
  count = 0;
  total_turnaround = 0.0;
  total_wait = 0.0;
  quantum = time_quantum;
}

/**
* @brief Destroy the SchedulerFCFS object
*/
SchedulerPriorityRR::~SchedulerPriorityRR()
{
  while(!Q.empty()) // pops everything in queue until empty
    {
      Q.pop();
    }
  Q = {}; // to ensure Q will be empty
}

/**
* @brief This function is called once before the simulation starts.
*        It is used to initialize the scheduler.
* @param process_list The list of processes in the simulation.
*/
void SchedulerPriorityRR::init(std::vector<PCB>& process_list) 
{
   // sorts the vector so PCB with highest priority is at the front (higher number)
  sort(process_list.begin(), process_list.end(), [](const PCB& lhs, const PCB& rhs) {
      return lhs.priority > rhs.priority;
     });
  
  int index = 0; // to track which index we are in the vector
  int v_size = process_list.size();
  while(index != v_size) // runs until index reaches end of the process_list vector
    {
      Q.push(process_list[index]); // first PCB (first index) in vector gets pushed into queue
      copy.push(process_list[index]); 
      count++;
      index++;
    }
}

/**
* @brief This function is called once after the simulation ends.
*        It is used to print out the results of the simulation.
*/
void SchedulerPriorityRR::print_results() 
{
    sort(done.begin(), done.end(), [](const PCB& lhs, const PCB& rhs) {
    return lhs.id < rhs.id;
     }); // sorts by process - T1, T2, etc
  int done_size = done.size();
  for(int i=0; i<done_size; i++)
    {
      cout << done[i].name << " turn-around time = " << done[i].turnaround;
      cout << ", waiting time = " << done[i].wait << endl;
    }
  cout << "Average turn-around time = " <<  total_turnaround/count;
  cout << ", Average waiting time = " << total_wait/count << endl;
}

  /**
  * @brief This function simulates the scheduling of processes in the ready queue.
  *        It stops when all processes are finished.
  */
void SchedulerPriorityRR::simulate()
{
  int curr_turnaround = 0;
  while(!Q.empty()) // run until queue is empty
  {
    int curr_burst; // tracks current burst
    int curr_wait; // tracks current waiting time
    int curr_priority1, curr_priority2;
    
    curr_priority1 = Q.front().priority;
    curr_priority2 = Q.back().priority;
    curr_burst = Q.front().burst_time; // contains burst time of PCB in front of queue
    
    while(curr_priority1 > curr_priority2)
      {
        int i = Q.size() - 1; //get the last index of queue
        if(curr_priority1)
        {
          curr_burst;//output the whole burst time of curr_priority1
        }
        if(curr_priority2)
        {
          ;//output the whole burst time of curr_priority2
        }
      
          if(curr_burst > quantum) // current burst is greater than quantum
          {
            Q.front().burst_time = curr_burst - quantum; // burst time updated (leftover units)
            curr_burst = quantum;
            Q.push(Q.front()); // push back PCB into queue
            copy.push(copy.front()); // push back PCB into queue
      
            curr_turnaround += curr_burst; 
          }
          else // when burst is less than quantum
          {
            curr_turnaround += curr_burst; 
            curr_wait = curr_turnaround - copy.front().burst_time;
      
            // running sum that adds up all the process turnaround/wait
            total_turnaround += curr_turnaround;
            total_wait += curr_wait;
      
            // saving turnaround and waiting times into PCB
            copy.front().turnaround = curr_turnaround;
            copy.front().wait = curr_wait; 
      
            // putting PCB into done vector
            done.push_back(copy.front());
          }
         i--; //decrementing the whole size of queue
        }
    // display "Running Process [name] for x time units"
    cout << "Running Process " << Q.front().name << " for "  << curr_burst << " time units" << endl;

    Q.pop(); // remove PCB in front
    copy.pop(); 
  }
}