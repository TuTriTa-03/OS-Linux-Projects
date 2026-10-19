#include "Scheduler.h"

Scheduler::Scheduler()
{
    currentProcess = nullptr;
}

Scheduler::~Scheduler()
{
    for (Process *process : createdProcesses)
    {
        delete process;
    }
}

void Scheduler::addProcess(Process *process)
{
    readyQueue.push(process);
}

void Scheduler::waitCurrentProcess()
{
    if (currentProcess != nullptr)
    {
        currentProcess->changeState("Waiting");
        waitingQueue.push(currentProcess);
        currentProcess = nullptr;
    }
}

void Scheduler::wakeUpProcess()
{
    if (!waitingQueue.empty())
    {
        Process *process = waitingQueue.front();
        waitingQueue.pop();

        process->changeState("Ready");
        readyQueue.push(process);
    }
}

void Scheduler::terminateCurrentProcess()
{
    if (currentProcess != nullptr)
    {
        currentProcess->changeState("Terminated");
        
        int parentPid = currentProcess->getParentPid();

        currentProcess = nullptr;

        queue<Process*> tempQueue;

        while (!waitingQueue.empty())
        {
            Process *process = waitingQueue.front();
            waitingQueue.pop();

            if (process->getPid() == parentPid)
            {
                process->changeState("Ready");
                readyQueue.push(process);
            }
            else
            {
                tempQueue.push(process);
            }
        }

        while (!tempQueue.empty())
        {
            waitingQueue.push(tempQueue.front());
            tempQueue.pop();
        }

    }
}

void Scheduler::forkProcess()
{
    if (currentProcess == nullptr)
    {
        return;
    }

    int parentPid = currentProcess->getPid();

    Process *child = new Process("Child", "Ready", parentPid);

    createdProcesses.push_back(child);

    child->printInfo();

    readyQueue.push(child);
}

void Scheduler::schedule()
{
    if (currentProcess != nullptr)
    {
        currentProcess->changeState("Ready");
        readyQueue.push(currentProcess);
    }

    if (!readyQueue.empty())
    {
        Process *process = readyQueue.front();
        readyQueue.pop();

        process->changeState("Running");
        currentProcess = process;
    }
}

void Scheduler::waitProcess()
{
    if (currentProcess == nullptr)
    {
        return;
    }

    int parentPid = currentProcess->getPid();

    for (Process *process : createdProcesses)
    {
        if (process->getParentPid() == parentPid)
        {
            if (process->getState() == "Terminated")
            {
                cout << "Child has terminated" << endl;
            }
            else
            {
                currentProcess->changeState("Waiting");
                waitingQueue.push(currentProcess);
                currentProcess = nullptr;
            }
        }
    }
}