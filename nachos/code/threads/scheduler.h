// scheduler.h 
//	Data structures for the thread dispatcher and scheduler.
//	Primarily, the list of threads that are ready to run.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef SCHEDULER_H
#define SCHEDULER_H
#define MAX_THREAD_COUNT 1000

#include "copyright.h"
#include "list.h"
#include "thread.h"

// The following class defines the scheduler/dispatcher abstraction -- 
// the data structures and operations needed to keep track of which 
// thread is running, and which threads are ready but not running.

class NachOSscheduler {
  public:
    NachOSscheduler();			// Initialize list of ready threads 
    ~NachOSscheduler();			// De-allocate ready list

    void ThreadIsReadyToRun(NachOSThread* thread);	// Thread can be dispatched.
    NachOSThread* FindNextThreadToRun();		// Dequeue first thread on the ready 
					// list, if any, and return thread.
    void Schedule(NachOSThread* nextThread);	// Cause nextThread to start running
    void Print();			// Print contents of ready list
    
    void Tail();                        // Used by fork()

    double alpha;   // SJF estimation
    int schedulerCode = 1;

    int quantum;
    int cpuCount[MAX_THREAD_COUNT];

  private:
    List *readyThreadList;  		// queue of threads that are ready to run,
				// but not running
};

#endif // SCHEDULER_H
