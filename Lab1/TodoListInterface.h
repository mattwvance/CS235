#ifndef TODO_LIST_INTERFACE_H
#define TODO_LIST_INTERFACE_H

#include <iostream>
#include <string>

using namespace std;

class TodoListInterface {
public:
    TodoListInterface() {}
    virtual ~TodoListInterface() {}
    virtual void add(string _duedat, string _task) = 0;
    virtual void remove(string _task) = 0;
    virtual void printTodoList() = 0;
    virtual void printDaysTasts(string _date) = 0;
};

#endif