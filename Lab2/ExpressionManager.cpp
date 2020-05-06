#include "ExpressionManager.h"
// ExpressionManager() {}
// virtual ~ExpressionManager() {}
bool ExpressionManager::isBalanced(string expression) {
    stack<char> parenthesesHolder;
    int index = 0;
    bool isBalanced = true;
    cout << "isBalanced"  << endl;
    while (isBalanced && index < expression.length()) {
        if (expression[index] == '(' || expression[index] == '[' || expression[index] == '{' && isBalanced) {
            parenthesesHolder.push(expression[index]);
        } else if (!parenthesesHolder.empty()) {
            if (expression[index] == ')' && parenthesesHolder.top() == '(' && isBalanced) {
                parenthesesHolder.pop();
            } else if (expression[index] == ']' && parenthesesHolder.top() == '[' && isBalanced) {
                parenthesesHolder.pop();
            } else if (expression[index] == '}' && parenthesesHolder.top() == '{' && isBalanced) {
                parenthesesHolder.pop();
            } 
        } else if (expression[index] == ')' || expression[index] == ']' || expression[index] == '}' && parenthesesHolder.empty()) {
                isBalanced = false;
        }
        ++index;
    }
    if (isBalanced && parenthesesHolder.empty()) {
        return true;
    } else {
        return false;
    }
};
string ExpressionManager::postfixToInfix(string postfixExpression) {
    cout << "postfixToInfix" << postfixExpression << endl;
    stack<string> expression;
    vector<string> tokens = expressionToString(postfixExpression);
    string rightToken;
    string leftToken;
    for (int i = 0; i < tokens.size(); ++i) {
        string nextToken = tokens[i];
        if (isdigit(nextToken.at(0))) {
            expression.push(tokens[i]);
        } else if (nextToken.at(0) == '+' | '-' | '/' | '*' | '%') {
            rightToken = expression.top(); expression.pop();
            leftToken = expression.top(); expression.pop();
            expression.push("( " + leftToken + " " + nextToken + " " + rightToken + " )");
        }
    }
    if (expression.size() == 1) {
        return expression.top();
    } else {
        return "Invalid";
    }
};
string ExpressionManager::postfixEvaluate(string postfixExpression) {
    cout << "postfixEvaluate" << endl;
    stack<int> operandHolder;
    vector<string> tokens = expressionToString(postfixExpression);
    int firstToken;
    int secondToken;
    string output;
    while (tokens.size() > 0) {
        if (isdigit(tokens[0].at(0))) {
            int myNum = stoi(tokens[0]);
            operandHolder.push(myNum);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '+') {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken + firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '-') {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken - firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '*') {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken * firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '/') {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken / firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '%') {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken % firstToken);
            tokens.erase(tokens.begin());
        } else {
            cout << "Not a valid string" << endl;
        }
    }
    output = to_string(operandHolder.top());
    return output;
};
string ExpressionManager::infixToPostfix(string infixExpression) {
    cout << "infixToPostfix" << infixExpression << endl;
    string postfix;
    stack<int> operators;
    vector<string> tokens = expressionToString(infixExpression);
    for (int i = 0; i < tokens.size(); ++i) {
        if (i+1 << tokens.size() && isdigit(tokens[i+1].at(0))) {
            postfix + tokens[i] + " ";
        }
    }
    return "a string";
};
vector<string> ExpressionManager::expressionToString(string expression) {
    stringstream ss(expression);
    string token;
    vector<string> tokens;
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}