#include "BST.h"
#include <iostream>

using namespace std;
int treeSize = 0;

Node * BST::getRootNode() const {
    return root;
};

int BST::size() const {
    return treeSize;
}

bool BST::add(const int data) {
    return recursiveAdd(this->root, data);
};

bool BST::recursiveAdd(Node* &node, const int val) {
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

bool BST::remove(int data) {
    return recursiveRemove(this->root, data);
};

bool BST::recursiveRemove(Node*& node, int val) {
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
        // if (!node->getLeftChild()->getRightChild()) {
        //     treeSize--;
        //     Node* temp = node;
        //     node = node->getLeftChild();
        //     node->setRightChild(temp->getRightChild());
        //     delete temp;
        //     temp = NULL;
        //     return true;
        // } else {
        //     treeSize--;
        //     inOrder(node->leftChild, node);
        //     return true;
        // }
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

void BST::inOrder(Node*& node, Node*& parent) {
    Node *temp = node;
    while (temp->getRightChild() != NULL) {
        temp = temp->getRightChild();
    }
    int tData = parent->data;
    parent->setData(temp->getData());
    temp->setData(tData);
};

void BST::clear() {
    recursiveClear(this->root);
    this->root = NULL;
};

void BST::recursiveClear(Node* n) {
    if (n != NULL) {
        recursiveClear(n->getLeftChild());
        recursiveClear(n->getRightChild());
        delete n;
        n = NULL;
    }
};