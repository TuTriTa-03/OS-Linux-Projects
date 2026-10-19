#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

using namespace std;

class Process
{
private:
    static int nextPid;
    int pid;
    int parentPid;
    string name;
    string state;

public:
    Process(string name, string state);
    Process(string name, string state, int parentPid);

    int getPid();
    int getParentPid();
    string getState();

    void printInfo();
    void changeState(string newState);

    void exec(string newName);
};

#endif