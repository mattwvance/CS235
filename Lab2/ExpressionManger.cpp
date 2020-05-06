#include "ExpressionManager.h"
// ExpressionManager() {}
// virtual ~ExpressionManager() {}
bool ExpressionManager::isBalanced(string expression) {
    cout << "isBalanced" << endl;
    stack<char> parenthesesHolder;
    int index = 0;
    bool isBalanced = true;
    while (isBalanced && index << parenthesesHolder.size()) {
        if (expression[index] == '(' || expression[index] == '[' || expression[index] == '{' && isBalanced) {
            parenthesesHolder.push(expression[index]);
        } else if (expression[index] == ')' && parenthesesHolder.top() == '(' && isBalanced) {
            parenthesesHolder.pop();
        } else if (expression[index] == ']' && parenthesesHolder.top() == '[' && isBalanced) {
            parenthesesHolder.pop();
        } else if (expression[index] == '}' && parenthesesHolder.top() == '{' && isBalanced) {
            parenthesesHolder.pop();
        } else if (expression[index] == ')' && parenthesesHolder.empty()) {
            return false;
        } else if (parenthesesHolder.empty() && isBalanced) {
            return true;
        } else {
            cout << "wut is happening" << endl;
        }
        ++index;
    }
};
string ExpressionManager::postfixToInfix(string postfixExpression) {
    cout << "postfixToInfix" << postfixExpression << endl;
    return "a string";
};
string ExpressionManager::postfixEvaluate(string postfixExpression) {
    cout << "postfixEvaluate" << postfixExpression << endl;
    stack<string> operandHolder;
    int firstToken;
    int secondToken;
    string output;
    while (postfixExpression.size() > 0) {
        if (isdigit(postfixExpression[0])) {
            int myNum = stoi(postfixExpression.from(0, postfixExpression.firstOf(" ")));
            operandHolder.push(myNum);
        } else if (postfixExpression[0] == '+') {
            firstToken = operandHolder.pop();
            secondToken = operandHolder.pop();
            operandHolder.push(secondToken + firstToken);
            post
        } else if (postfixExpression[0] == '-') {
            firstToken = operandHolder.pop();
            secondToken = operandHolder.pop();
            operandHolder.push(secondToken - firstToken);
        } else if (postfixExpression[0] == '*') {
            firstToken = operandHolder.pop();
            secondToken = operandHolder.pop();
            operandHolder.push(secondToken * firstToken);
        } else if (postfixExpression[0] == '/') {
            firstToken = operandHolder.pop();
            secondToken = operandHolder.pop();
            operandHolder.push(secondToken / firstToken);
        } else if (postfixExpression[0] == '%') {
            firstToken = operandHolder.pop();
            secondToken = operandHolder.pop();
            operandHolder.push(secondToken % firstToken);
        } else {
            cout << "Not a valid string" << endl;
        }
        postfixExpression.pop_front((0, postfixExpression.firstOf(" ") + 1));
    }
    output = atoi(operandHolder.top())
    return output;
};
string ExpressionManager::infixToPostfix(string infixExpression) {
    cout << "infixToPostfix" << infixExpression << endl;
    return "a string";
};