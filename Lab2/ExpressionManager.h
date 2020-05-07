#pragma once
#include "ExpressionManagerInterface.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class ExpressionManager: public ExpressionManagerInterface {
public:
    ExpressionManager() {};
    virtual ~ExpressionManager() {};
    bool isBalanced(string expression);
    string postfixToInfix(string postfixExpression);
	string postfixEvaluate(string postfixExpression);
    vector<string> expressionToString(string expression);
};