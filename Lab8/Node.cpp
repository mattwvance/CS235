#include "Node.h"

Node::Node(int value) {
    data = value;
    leftChild = NULL;
    rightChild = NULL;
    height = 0;
    balance = 0;
};

Node::~Node() {};

int Node::getData() const {
    return data;
};

Node* Node::getLeftChild() const {
    if (leftChild == NULL) { return NULL; }
    else { return leftChild; }
};

Node * Node::getRightChild() const {
    if (rightChild == NULL) { return NULL; }
    else { return rightChild; }
};

void Node::setRightChild(Node* ptr) {
    rightChild = ptr;
};

void Node::setLeftChild(Node* ptr) {
    leftChild = ptr;
};

void Node::setData(int val) {
    data = val;
}

int Node::getHeight() {
    return height;
};

int Node::reset() {
    if (!rightChild && !leftChild) {
        balance = 0;
        height = 1;
    } else if (!rightChild) {
        height = leftChild->reset() + 1;
        balance = 0 - leftChild->getHeight();
    } else if (!leftChild) {
        height = rightChild->reset() + 1;
        balance = rightChild->getHeight();
    } else {
        height = max(leftChild->reset(), rightChild->reset()) + 1;
        balance = rightChild->getHeight() - leftChild->getHeight();
    }
    return height;
}