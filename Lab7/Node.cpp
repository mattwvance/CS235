#include "Node.h"

Node::Node(int value) {
    data = value;
    leftChild = NULL;
    rightChild = NULL;
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