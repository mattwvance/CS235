#include "BST.h"
#include <iostream>

using namespace std;

int treeSize = 0;
Node* head = NULL;

BST::BST() {
    head = NULL;
};

BST::~BST() {
    this->clear();
};

Node* BST::inOrder(Node* node, int val) {

};

Node* BST::getRootNode() const {
    return head;
};

int BST::size() const {
    return treeSize;
}

bool BST::add(int data) {

};

Node* BST::recusiveAdd(Node* node, int val) {

};

bool BST::remove(int data) {

};

Node* BST::recursiveRemove(Node* node, int val) {

};

void BST::clear() {
    while (head != NULL) {
        remove (head->data);
    }
};