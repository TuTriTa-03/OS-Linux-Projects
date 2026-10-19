#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <vector>
#include "Process.h"

using namespace std;

class Scheduler
{
private:
    queue<Process *> readyQueue;
    queue<Process *> waitingQueue;
    Process *currentProcess;
    vector<Process*> createdProcesses;

public:
    Scheduler();
    ~Scheduler();

    void addProcess(Process *process);
    void waitCurrentProcess();
    void wakeUpProcess();
    void terminateCurrentProcess();
    void schedule();
    void forkProcess();
    void waitProcess();
    
};

#endif 