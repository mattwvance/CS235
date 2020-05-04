#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TodoListInterface.h"

using namespace std;

class TodoList: public TodoListInterface
{
public:
    vector<string> tasks;
    TodoList() {
        ifstream inFile ("TODOList.txt");
        string line;
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                tasks.push_back(line);
            }
            inFile.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    }
    virtual ~TodoList() {
        ofstream outFile ("TODOList.txt", ofstream::out | ofstream::trunc);
        for (int i = 0; i < tasks.size(); ++i) {
            outFile << tasks[i] << endl;
        }
        outFile.close();
    };
    virtual void add(string _duedate, string _task) {
        tasks.push_back(_duedate +" "+ _task);
        cout << _duedate << " " << _task << " added to TODO List." << endl;
    };
    virtual void remove(string _task) {
        for (int i = 0; i < tasks.size(); ++i) {
            if (tasks[i].substr(tasks[i].find(" ") + 1, tasks[i].size()) == _task) {
                string removed = tasks[i];
                tasks.erase(tasks.begin() + i);
                cout << removed << " has been removed" << endl;
            }
        }

    };
    virtual void printTodoList() {
        for (int i = 0; i < tasks.size(); ++i) {
            cout << tasks[i] << endl;
        }
    };
    virtual void printDaysTasts(string _date) {
        for (int i = 0; i < tasks.size(); ++i) {
            if (tasks[i].substr(0, tasks[i].find(" ")) == _date) {
                cout << tasks[i] << endl;
            }
        }
    };
};

#endif