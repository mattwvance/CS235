#include "BST.h"
#include <iostream>

using namespace std;

int treeSize = 0;

void BST::inOrder(Node* node, Node*& parent) {
    if (node == NULL && parent->rightChild == NULL) {
        parent == NULL;
        return;
    }
    Node* temp = findRightMost(node);
    int tData = parent->data;
    parent->data = temp->data;
    temp->data = tData;
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
    } else if (node->getData() == val) {
        Node* check = node->leftChild;
        if (node->leftChild == NULL && node->rightChild == NULL) {
            delete node;
            node = NULL;
            return true;
        } else if (check && node->rightChild) {
            inOrder(check, node);
            recursiveRemove(check, val);
            return true;
        } else if (check != NULL) {
            Node* temp = node;
            node = node->leftChild;
            delete temp;
            temp = NULL;
            return true;
        } else if (check == NULL) {
            Node* temp = node;
            node = node->rightChild;
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
    while(check->rightChild != NULL) {
        check = check->rightChild;
    }
    return check;
};

void BST::clear() {
    do {
        if (root->data) {
            remove(root->data);
        }
    } while (root != NULL);
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
// string BST::BSTtoString(BST* tree) const {
//     cout << "Print BST" << endl;
//     return " ";
// };