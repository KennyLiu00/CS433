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
  while(!plist.empty()) // pops everything in queue until empty
    {
      plist.pop_back();
      final.pop_back();
    }
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
      plist.push_back(process_list[index]); // first PCB (first index) in vector gets pushed into another vector
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
    sort(final.begin(), final.end(), [](const PCB& lhs, const PCB& rhs) {
    return lhs.id < rhs.id;
     }); // sorts by process - T1, T2, etc
  int done_size = final.size();
  for(int i=0; i<done_size; i++)
    {
      cout << final[i].name << " turn-around time = " << final[i].turnaround;
      cout << ", waiting time = " << final[i].wait << endl;
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
  /*
    inside a loop that goes thru each index of plist:
    
    curr_priority will start at 10 since highest priority goes first
    index = 0 to track which index we are in

    while curr_priority is == 10
    push to Q and run
    index++
  */
  vector<PCB> Q;
  int index = 0; // starts at front of vector
  unsigned int p = 10;  // highest priority starts at 10
  bool done = false;

  Q.push_back(plist.front());
 /*
  while(done != true)
    {
      while(plist[index].priority == p) // while current PCB's p is equal to curr_priority
      {
        Q.push_back(plist[index]); // gets pushed to ready queue
        copy.push_back(plist[index]);
        cout << plist[index].priority << " pushed to RQ" << endl;
        index++; 
        }
      p--;
    
      // PROCESS IN Q, RUN USING ROUND ROBIN

      int curr_turnaround = 0;
      int curr_burst; // tracks current burst
      int curr_wait; // tracks current waiting time
      
      while(!Q.empty()) // run until queue is empty
      {      
        curr_burst = Q.front().burst_time; // contains burst time of PCB in front of queue
      
        if(curr_burst > quantum) // current burst is greater than quantum
        {
          Q.front().burst_time = curr_burst - quantum; // burst time updated (leftover units)
          curr_burst = quantum; // only runs for certain amount of units, which is the quantum
          Q.push_back(Q.front()); // push back PCB into queue
          copy.push_back(copy.front()); // push back PCB into vector
      
          curr_turnaround += curr_burst; // calculates turnaround
        }
        else // when burst is less than quantum
        {
          curr_turnaround += curr_burst; // calculates turnaround
          curr_wait = curr_turnaround - copy.front().burst_time; // calculates wait
      
          // running sum that adds up all the process turnaround/wait
          total_turnaround += curr_turnaround;
          total_wait += curr_wait;
      
          // saving turnaround and waiting times into PCB
          copy.front().turnaround = curr_turnaround;
          copy.front().wait = curr_wait; 
      
          // putting PCB into done vector
          final.push_back(copy.front());
        }
        Q.pop_back(); // remove PCB in front
    }

        // display "Running Process [name] for x time units"
        cout << "Running Process " << final[index].name << " for "  << curr_burst << " time units" << endl;

    int s = plist.size();
    if(index == s) // index is equal to vector size, stop running
    {
      done = true;
    }
  }
*/
}


  
  /*
  unsigned int curr_turnaround = 0; // will start at 0
  int counter = 10;//start with current priority
  while(counter) // run until queue is empty
  {
    //int curr_burst; // tracks current burst
    int curr_wait; // tracks current waiting time
    // pushes same priority PBCs into RQ
    //int curr_priority1 = Q.front().priority;
    //int curr_priority2 = Q.back().priority;
    bool same_priority = true;
    //some processes that have time left
    int curr_burst = Q.front().burst_time;
    //bool do_rr = false;
    for(int i = 0; i < counter; i++) //goes through the whole list of processes
    {
      if(counter == i)//counter is the same privilege as the counter of for loop
      {
          int curr_burst; // tracks current burst
          int curr_wait; // tracks current waiting time
      
          curr_burst = Q.front().burst_time; // contains burst time of PCB in front of queue
      
          if(curr_burst > quantum) // current burst is greater than quantum
          {
            Q.front().burst_time = curr_burst - quantum; // burst time updated (leftover units)
            curr_burst = quantum;
            Q.push_back(Q.front()); // push back PCB into queue
            copy.push_back(copy.front()); // push back PCB into vector
      
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
           Q.pop_back(); // remove PCB in front
           copy.pop_back(); 
    }
    counter--;
  }
*/

/*
int curr_turnaround = 0;
  int counter = 10;
  while(counter && !Q.empty())
    {
      if(Q.front().priority > Q.back().priority)
{
        int back_high = Q.front().priority;
        Q.front().priority = Q.back().priority;
        Q.back().priority = back_high;

        if(Q.front().priority == counter)
        {
          int curr_burst; // tracks current burst
          int curr_wait; // tracks current waiting time
      
          curr_burst = Q.front().burst_time; // contains burst time of PCB in front of queue
      
          if(curr_burst > quantum) // current burst is greater than quantum
          {
            Q.front().burst_time = curr_burst - quantum; // burst time updated (leftover units)
            curr_burst = quantum; // only runs for certain amount of units, which is the quantum
            Q.push(Q.front()); // push back PCB into queue
            copy.push(copy.front()); // push back PCB into vector
      
            curr_turnaround += curr_burst; // calculates turnaround
          }
          else // when burst is less than quantum
          {
            curr_turnaround += curr_burst; // calculates turnaround
            curr_wait = curr_turnaround - copy.front().burst_time; // calculates wait
      
            // running sum that adds up all the process turnaround/wait
            total_turnaround += curr_turnaround;
            total_wait += curr_wait;
      
            // saving turnaround and waiting times into PCB
            copy.front().turnaround = curr_turnaround;
            copy.front().wait = curr_wait; 
      
            // putting PCB into done vector
            done.push_back(copy.front());
          }
        }
        
      }
      else if(Q.back().priority > Q.front().priority)
{
        int front_high = Q.back().priority;
        Q.back().priority = Q.front().priority;
        Q.front().priority = front_high;

        if(Q.back().priority == counter)
        {
          int curr_burst; // tracks current burst
          int curr_wait; // tracks current waiting time
      
          curr_burst = Q.front().burst_time; // contains burst time of PCB in front of queue
      
          if(curr_burst > quantum) // current burst is greater than quantum
          {
            Q.front().burst_time = curr_burst - quantum; // burst time updated (leftover units)
            curr_burst = quantum; // only runs for certain amount of units, which is the quantum
            Q.push(Q.front()); // push back PCB into queue
            copy.push(copy.front()); // push back PCB into vector
      
            curr_turnaround += curr_burst; // calculates turnaround
          }
          else // when burst is less than quantum
          {
            curr_turnaround += curr_burst; // calculates turnaround
            curr_wait = curr_turnaround - copy.front().burst_time; // calculates wait
      
            // running sum that adds up all the process turnaround/wait
            total_turnaround += curr_turnaround;
            total_wait += curr_wait;
      
            // saving turnaround and waiting times into PCB
            copy.front().turnaround = curr_turnaround;
            copy.front().wait = curr_wait; 
      
            // putting PCB into done vector
            done.push_back(copy.front());
          }
        } 
      }
      else
      {
        unsigned int curr_burst; // tracks current burst
        unsigned int curr_wait; // tracks current waiting time
    
        curr_burst = Q.front().burst_time; // contains burst time of PCB in front of queue
        curr_turnaround += curr_burst; // calculates turnaround
        curr_wait = curr_turnaround - curr_burst; // calculates wait
    
        // running sum that adds up all the process turnaround/wait
        total_turnaround += curr_turnaround;
        total_wait += curr_wait;
    
        // saving turnaround and waiting times into PCB
        Q.front().turnaround = curr_turnaround;
        Q.front().wait = curr_wait;
    
        // putting PCB into done vector
        done.push_back(Q.front());

      }
      cout << "Running Process " << Q.front().name << " for "  << curr_burst << " time units" << endl;
      
      Q.pop();
      copy.pop();
      counter--;
    }
}
*/

/*
curr_index starts at index 0
loop until curr_index priority is not equal to next one (index should stop at last same priority)
  pops front PCB into RQ
  set bool do_rr to true

if do_rr == true
  run round robin until empty

else
  run normally
_______________________________________________________________
It's all in a while loop. I used a counter that starts at 10 since the zybook stated priorities can range from 1-10. In the case where there are no more processes for the current priority, decrement that counter and continue

yes but my outer checks while not done (some processes might have some time left) since I don't delete or empty my list. (I used a vector instead of a queue). The inner is a for loop that goes through, searching for the corresponding priorites and then doing all the math
so if the priority is at 10, the inner for loop does all the math for whatever has the priority and so on

If it doesn't match, it will be ignored

once the loop goes around without doing any math(no more left for the current priority), the counter will decrement by one
so I use two booleans, one checks the procceses for the current priority, and the other checks the entire vector as a whole (since i dont delete anything).
*/
