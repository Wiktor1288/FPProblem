#ifndef Task_h
#define Task_h
#include "Operation.h"
class Task{

    static int TaskID;      // Id of Task
    Operation *OperationsTab;   // Pointer to create array of operations
    int TermintaionTime;    // Time of termination task termination == Time of termination all operations contained 
    int StartTime;              // Time of start task and first operation
    int AmountOfOperations;   // Amount of operation == amount of machines

    /*
    SetStartTime
    used to set value of start time. It can be called by Task::Add_StartTime_Operation only.
    */
    void SetStartTime(int Value);

    /*
    SetStartTime
    used to set value of start time. It can be called by Task::Add_TerminationTime_Operation only.
    */
    void SetTerminationTime(int Value);

    public:
    Task(){
        ++TaskID;
        OperationsTab=nullptr;
        TermintaionTime=0;
        StartTime=0;
        AmountOfOperations=0;
        std::cout << "essa" << std::endl;
    }

    ~Task(){
        if(AmountOfOperations!=0)
        {
            delete [] OperationsTab;
        }
        else{
            delete OperationsTab;
        }
    }

    int ReturnValue(char IDValue);
    void TaskInit(int AmountOfOperations);
    void Add_PerformedTime_Operation(int Value, int OperatorID);
    void Add_StartTime_Operation(int Value, int OperatorID);
    void Add_TerminationTime_Operation(int Value, int OperatorID);
    int Return_PerformedTime_Operation(int OperatorID);
    int Return_StartTime_Operation(int OperatorID);
    int Return_TerminationTime_Operation(int OperatorID);
    int ReturnID();


};

#endif