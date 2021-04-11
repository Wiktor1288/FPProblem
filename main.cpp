#include <iostream>
#include <memory>

#include "RandomNumberGenerator.h"
#include "Task.h"
#include "Machine.h"
#include "Operation.h"
using namespace std;

void SetStartParametrs(RandomNumberGenerator Randomg, shared_ptr <Task[]> Tasks_1, int NTask, int NMaschines);
void ShowParametrs(shared_ptr <Task[]> Tasks_1, int NTask, int NMaschines);
int main(){

    auto NumberTasks{0}, NumberMachines{0}, Seed{0}, i{0}; 

    cout << "Hello! I solve FP problem \n"
    << "Set the number of task: ";
    cin >> NumberTasks;
    cout << "Set the number of machines: ";
    cin >> NumberMachines;
    cout << "Set the seed: ";
    cin >> Seed;
    
    RandomNumberGenerator Random1(Seed);
    shared_ptr <Task []> TaskTab(new Task[NumberTasks]);
    shared_ptr <int []> TabOrder(new int[NumberTasks]);

    for(i=0; i<NumberTasks; i++)
        TabOrder[i]=i;
    for(i=0; i<NumberTasks; i++)
        TaskTab[i].TaskInit(NumberMachines);
    
    SetStartParametrs(Random1, TaskTab, NumberTasks, NumberMachines);
    ShowParametrs(TaskTab, NumberTasks, NumberMachines);




    return 0;
}

void SetStartParametrs(RandomNumberGenerator Randomg, shared_ptr <Task[]> Tasks_1, int NTask, int NMaschines){
    auto i{0}, j{0};
    
    for(i=0; i<NTask; i++){
        for(j=0; j<NMaschines; j++){
            Tasks_1[i].Add_PerformedTime_Operation(Randomg.nextInt(1,29),j);
        }
    }
}

void ShowParametrs(shared_ptr <Task[]> Tasks_1, int NTask, int NMaschines){
    auto i{0}, j{0};

    for(i=0; i<NTask; i++){
        cout << "ID: " << Tasks_1[i].ReturnID() << endl;
        for ( j=0; j<NMaschines; j++){
            cout << j+1 << " Op: p= " << Tasks_1[i].Return_PerformedTime_Operation(j);
            cout << " \n";
        }
        cout << endl;
        
    }
}