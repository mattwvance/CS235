#include "AVL.h"
#include <iostream>

using namespace std;
int treeSize = 0;

Node * AVL::getRootNode() const {
    return root;
};

int AVL::size() const {
    return treeSize;
}

bool AVL::add(const int data) {
    return recursiveAdd(this->root, data);
};

bool AVL::recursiveAdd(Node* &node, const int val) {
    if (node == NULL) {
        treeSize++;
        node = new Node(val);
        return true; 
    } else if (node->getData() == val) {
        return false;
    } else if (val < node->getData()) {
        return recursiveAdd(node->leftChild, val);
    } else if (val > node->getData()) {
        return recursiveAdd(node->rightChild, val);
    }
};

bool AVL::remove(int data) {
    return recursiveRemove(this->root, data);
};

bool AVL::recursiveRemove(Node*& node, int val) {
    if (node == NULL) {
        return false;
    } 
    if (val < node->getData()) {
        return recursiveRemove(node->leftChild, val);
    }
    if (val > node->getData()) {
        return recursiveRemove(node->rightChild, val);
    }
    if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {
        treeSize--;
        delete node;
        node = NULL;
        return true;
    }
    if (node->getLeftChild() && node->getRightChild()) {
        inOrder(node->leftChild, node);
        return recursiveRemove(node->leftChild, val);
    }
    if (node->getLeftChild() && !node->getRightChild()) {
        treeSize--;
        Node* temp = node;
        node = node->getLeftChild();
        delete temp;
        temp = NULL;
        return true;
    }
    if (!node->getLeftChild() && node->getRightChild()) {
        treeSize--;
        Node* temp = node;
        node = node->getRightChild();
        delete temp;
        temp = NULL;
        return true;
    }
    return true;
};

void AVL::inOrder(Node*& node, Node*& parent) {
    Node *temp = node;
    while (temp->getRightChild() != NULL) {
        temp = temp->getRightChild();
    }
    int tData = parent->data;
    parent->setData(temp->getData());
    temp->setData(tData);
};

void AVL::clear() {
    recursiveClear(this->root);
    this->root = NULL;
};

void AVL::recursiveClear(Node* n) {
    if (n != NULL) {
        recursiveClear(n->getLeftChild());
        recursiveClear(n->getRightChild());
        delete n;
        n = NULL;
    }
};