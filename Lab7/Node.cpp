#include "Node.h"

Node::Node(int value, Node* leftChild = NULL, Node* rightChild = NULL) {
    data = value;
    left = leftChild;
    right = rightChild;
};

Node::~Node() {};

int Node::getData() const {
    return data;
};

Node* Node::getLeftChild() const {
    if (left == NULL) { return NULL; }
    else { return left; }
};

Node* Node::getRightChild() const {
    if (right == NULL) { return NULL; }
    else { return right; }
};