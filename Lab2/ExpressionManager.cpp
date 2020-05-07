#include "ExpressionManager.h"

const string ERR = "invalid";

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
            if (nextToken.find('.') != string::npos) {
                return ERR;
            }
            expression.push(tokens[i]);
        } else if (nextToken.at(0) == '+' | '-' | '/' | '*' | '%' && expression.size() >= 2) {
            rightToken = expression.top(); expression.pop();
            leftToken = expression.top(); expression.pop();
            expression.push("( " + leftToken + " " + nextToken + " " + rightToken + " )");
        } else {
            return ERR;
        }
    }
    if (expression.size() == 1) {
        return expression.top();
    } else {
        return ERR;
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
        } else if (tokens[0].at(0) == '+' && operandHolder.size() >= 2) {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken + firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '-' && operandHolder.size() >= 2) {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken - firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '*' && operandHolder.size() >= 2) {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken * firstToken);
            tokens.erase(tokens.begin());
        } else if (tokens[0].at(0) == '/' && operandHolder.size() >= 2) {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            if (firstToken == 0) {
                return ERR;
            } else {
                operandHolder.push(secondToken / firstToken);
                tokens.erase(tokens.begin());
            }
        } else if (tokens[0].at(0) == '%' && operandHolder.size() >= 2) {
            firstToken = operandHolder.top();
            operandHolder.pop();
            secondToken = operandHolder.top();
            operandHolder.pop();
            operandHolder.push(secondToken % firstToken);
            tokens.erase(tokens.begin());
        } else if(operandHolder.size() < 2 && !isdigit(tokens[0].at(0))) {
            return ERR;
        }
    }
    output = to_string(operandHolder.top());
    return output;
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