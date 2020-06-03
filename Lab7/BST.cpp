#include "BST.h"
#include <iostream>

using namespace std;

int treeSize = 0;

void BST::inOrder(Node* node, Node*& parent) {
    if (node == NULL && parent->rightChild == NULL) {
        parent == NULL;
        return;
    }
    Node *temp = findRightMost(node);
    int tData = parent->getData();
    parent->setData(temp->data);
    temp->setData(tData);
};

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
    if (node == NULL || node->getData() == NULL) {
        return false;
    } else if (node->data == val) {
        Node* check = NULL;
        if (node->getLeftChild()) {
            check = node->leftChild;
        }
        if (check == NULL && node->getRightChild() == NULL) {
            treeSize--;
            delete node;
            node = NULL;
            return true;
        } else if (check && node->getRightChild()) {
            inOrder(check, node);
            recursiveRemove(check, val);
        } else if (check != NULL) {
            treeSize--;
            Node* temp = node;
            node = node->getLeftChild();
            delete temp;
            temp = NULL;
            return true;
        } else if (check == NULL) {
            treeSize--;
            Node* temp = node;
            node = node->getRightChild();
            delete temp;
            temp = NULL;
            return true;
        }
    } else if (val < node->getData()) {
        return recursiveRemove(node->leftChild, val);
    } else if (val > node->getData()) {
        return recursiveRemove(node->rightChild, val);
    } 
};

Node* BST::findRightMost(Node*& check) {
    while(check->getRightChild()) {
        check = check->getRightChild();
    }
    return check;
};

void BST::clear() {
    recursiveClear(this->root);
    root = NULL;
    delete root;
};

void BST::recursiveClear(Node* root) {
    if (root != NULL) {
        recursiveClear(root->getLeftChild());
        recursiveClear(root->getRightChild());
    }
};

bool BST::checkExists(Node *node, int val) const {
    if (node == NULL) { return false; }
    else if (node->getData() == val) { return true; }
    else if (val < node->getData()) {
        checkExists(node->getLeftChild(), val);
    } else if(val > node->getData()) {
        checkExists(node->getRightChild(), val);
    }
};