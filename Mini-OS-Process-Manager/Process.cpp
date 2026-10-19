#include "Process.h"

int Process::nextPid = 1;

Process::Process(string name, string state)
{
    pid = nextPid++;
    parentPid = -1;
    this->name = name;
    this->state = state;
}

Process::Process(string name, string state, int parentPid)
{
    pid = nextPid++;
    this->parentPid = parentPid;
    this->name = name;
    this->state = state;
}

int Process::getPid()
{
    return pid;
}

int Process::getParentPid()
{
    return parentPid;
}

void Process::printInfo()
{
    cout << "PID : " << pid << endl;
    cout << "Name : " << name << endl;
    cout << "State : " << state << endl;
    cout << "Parent PID : " << parentPid << endl;
}

string Process::getState()
{
    return state;
}

void Process::exec(string newName)
{
    name = newName;
}

void Process::changeState(string newState)
{
    if (state == "New" && newState == "Ready")
    {
        state = newState;
    }
    else if (state == "Ready" && newState == "Running")
    {
        state = newState;
    }
    else if (state == "Running" && newState == "Waiting")
    {
        state = newState;
    }
    else if (state == "Running" && newState == "Ready")
    {
        state = newState;
    }
    else if (state == "Waiting" && newState == "Ready")
    {
        state = newState;
    }
    else if (state == "Running" && newState == "Terminated")
    {
        state = newState;
    }
}
