#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[])
{
    TodoList myList;
    string firstArg = argv[1];
    if(firstArg.compare("add") == 0) {
        string date = argv[2];
        string task = argv[3];
        myList.add(date, task);
    } else if(firstArg.compare("remove") == 0) {
        string task = argv[2];
        myList.remove(task);
    } else if(firstArg.compare("printList") == 0) {
        myList.printTodoList();
    } else if(firstArg.compare("printDay") == 0) {
        string day = argv[2];
        myList.printDaysTasts(day);
    } else {
        cout << "Invalid function. Please use one of the following: add, remove, printList, or printDay" << endl;
    }
}