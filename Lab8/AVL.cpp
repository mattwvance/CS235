#include "AVL.h"
#include <iostream>

using namespace std;
int treeSize = 0;

AVL::AVL() {
    root = NULL;
    increased = false;
    changed = false;
};

AVL::~AVL() {
    this->clear();
};

Node * AVL::getRootNode() const {
    return root;
};

int AVL::size() const {
    return treeSize;
}

bool AVL::add(const int data) {
    increased = false;
    bool added = recursiveAdd(this->root, data);
    do {
        changed = false;
        if (root != NULL) {
            root->reset();
        }
        rebalance(root);
    } while (changed);
    return added;
};

bool AVL::recursiveAdd(Node* &node, const int val) {
    if (node == NULL) {
        treeSize++;
        node = new Node(val);
        increased = true;
        return true; 
    } 
    bool isAdded = false;
    int currHeight = node->getHeight();
    //cout << currHeight << endl;
    if (node->getData() == val) {
        return false;
    } else if (val < node->getData()) {
        isAdded = recursiveAdd(node->leftChild, val);
        if (increased) {
            --node->balance;
            //cout << val << "getting left" << node->balance << node->getLeftChild()->balance << endl;
            if (node->balance < -1) {
                if (node->getLeftChild()->balance > 0 ) { //}== 1) {
                    rotateLeft(node->leftChild);
                }
                increased = false;
                rotateRight(node);
            } else if (node->balance == 0) {
                increased = false;
            }
        }
    } else if (val > node->getData()) {
        isAdded = recursiveAdd(node->rightChild, val);
        //cout << val << "getting right" << node->balance << node->getRightChild()->balance << endl;
        if (increased) {
            ++node->balance;
            if (node->balance > 1) {
                if (node->getRightChild()->balance < 0) {
                    rotateRight(node->rightChild);
                }
                rotateLeft(node);
                increased = false;
            } else if (node->balance == 0) {
                increased = false;
            }
        }
    }
    return isAdded;
};

void AVL::rotateLeft(Node*& node) {
    Node *pivot = node->getRightChild();
    node->setRightChild(pivot->getLeftChild());
    pivot->setLeftChild(node);
    node = pivot;
    --node->balance;
    --node->getLeftChild()->balance;
};

void AVL::rotateRight(Node*& node) {
    Node* pivot = node->getLeftChild();
    node->setLeftChild(pivot->getRightChild());
    pivot->setRightChild(node);
    node = pivot;
    ++node->balance;
    ++node->getRightChild()->balance;
};

void AVL::rebalance(Node*& node) {
    if (node == NULL) { return; }
    if (node->getLeftChild()) { rebalance(node->leftChild); }
    if (node->getRightChild()) { rebalance(node->rightChild); }
    if (node->balance < -1) {
        if (node->getLeftChild()->balance == 1) {
            rotateLeft(node->leftChild);
        }
        rotateRight(node);
        changed = true;
    }
    if (node->balance > 1) {
        if (node->getRightChild()->balance == -1) {
            rotateRight(node->rightChild);
        }
        rotateLeft(node);
        changed = true;
    }
};

bool AVL::remove(int data) {
    bool removed = recursiveRemove(this->root, data);
    do {
        changed = false;
        if (root != NULL) {
            root->reset();
        }
        rebalance(root);
    } while (changed);
    return removed;
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