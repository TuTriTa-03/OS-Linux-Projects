#include <iostream>
#include "Process.h"
#include "Scheduler.h"

using namespace std;

int main()
{
    Process p1("Sensor", "Ready");
    Process p2("Motor", "Ready");
    Process p3("Network", "Ready");

    Scheduler scheduler;

    scheduler.addProcess(&p1);
    scheduler.addProcess(&p2);
    scheduler.addProcess(&p3);

    cout << "===== INITIAL STATE =====" << endl;

    p1.printInfo();
    cout << endl;

    p2.printInfo();
    cout << endl;

    p3.printInfo();
    cout << endl;


    cout << "===== FIRST SCHEDULE =====" << endl;

    scheduler.schedule();

    p1.printInfo();
    cout << endl;


    cout << "===== FORK =====" << endl;

    scheduler.forkProcess();


    cout << "===== PARENT WAIT =====" << endl;

    scheduler.waitProcess();

    p1.printInfo();
    cout << endl;


    cout << "===== SCHEDULE P2 =====" << endl;

    scheduler.schedule();

    p2.printInfo();
    cout << endl;


    cout << "===== SCHEDULE P3 =====" << endl;

    scheduler.schedule();

    p3.printInfo();
    cout << endl;


    cout << "===== SCHEDULE CHILD =====" << endl;

    scheduler.schedule();


    cout << "===== CHILD TERMINATE =====" << endl;

    scheduler.terminateCurrentProcess();


    cout << "===== PARENT AFTER WAKE UP =====" << endl;

    p1.printInfo();
    cout << endl;


    cout << "===== SCHEDULE AGAIN =====" << endl;

    scheduler.schedule();

    p1.printInfo();
    cout << endl;


    system("pause");

    return 0;
}