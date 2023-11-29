
#ifndef PCB_HPP
#define PCB_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class PCB
{
private:
    int process_id;
    int virtual_runtime;
    int time_to_complete;

    int RandomProcessID();
    int RandomVirtualRuntime();
    int RandomTimeToComplete(int virtual_runtime);

    static const int DEFAULT_VALUE = -1;

public:
    PCB();
    // setters
    void SetProcessID(int process_id) { this->process_id = process_id; }
    void SetVirtualRuntime(int virtual_runtime) { this->virtual_runtime = virtual_runtime; }
    void SetTimeToComplete(int time_to_complete) { this->time_to_complete = time_to_complete; }

    // getters
    int GetProcessID() { return process_id; }
    int GetVirtualRuntime() { return virtual_runtime; }
    int GetTimeToComplete() { return time_to_complete; }

    void DisplayPCB();

    void RecalculateTimeToComplete(int time_slice);
    void RecalculateVirtualRuntime(int time_slice);
};

PCB::PCB()
{
    process_id = RandomProcessID();
    virtual_runtime = RandomVirtualRuntime();
    time_to_complete = RandomTimeToComplete(virtual_runtime);
}

int PCB::RandomProcessID()
{
    return rand() % 10000 + 1;
}

int PCB::RandomVirtualRuntime()
{
    return rand() % 1000 + 1;
}

int PCB::RandomTimeToComplete(int virtual_runtime)
{
    return rand() % 10000 + virtual_runtime;
}

void PCB::DisplayPCB()
{
    cout << "Process ID: " << process_id << endl;
    cout << "Virtual Runtime: " << virtual_runtime << endl;
    cout << "Time to Complete: " << time_to_complete << endl;
}

#endif