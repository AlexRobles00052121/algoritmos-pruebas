#include <iostream>
#include <ctime>
#include "rb_tree.hpp"
#include "utility.hpp"
#include "pcb.hpp"

using namespace std;

int main()
{
    int const size = 35;
    PCB array[size];

    Red_Black_Tree rbTree;
    PCB pcb;
    

    for(int i = 0; i < size; i++)
    {
        rbTree.Insert(array[i]);
    }

    rbTree.Display(1);

    while(rbTree.GetRoot() != nullptr)
    {
        pcb = rbTree.Minimum(rbTree.GetRoot())->data;

        pcb.DisplayPCB();

        rbTree.Delete(pcb);

        pcb.SetVirtualRuntime(pcb.GetVirtualRuntime() + RandomTimeSlice());
        pcb.SetTimeToComplete(pcb.GetTimeToComplete() - pcb.GetVirtualRuntime());

        if(pcb.GetTimeToComplete() > 0)
        {
            rbTree.Insert(pcb);
        }
        else
        {
            cout << "Process ID: " << pcb.GetProcessID() << " has completed." << endl;
        }
    }

    cout << "empty tree" << endl;
    rbTree.Display(1);

    return 0;
}
