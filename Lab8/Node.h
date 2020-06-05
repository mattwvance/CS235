#pragma once

#include <iostream>
#include "NodeInterface.h"

class Node: public NodeInterface
{
	friend class AVL;
public:
    Node(int value);
    virtual ~Node();

    /*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
    int getData() const;

    /*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
    Node* getLeftChild() const;

    /*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
    Node* getRightChild() const;
	/*
	* Sets the right child
	*/
	void setRightChild(Node* ptr);
	/*
	* Sets the left child
	*/
	void setLeftChild(Node* ptr);
	/*
	* sets data value
	*/
	void setData(int val);

	int getHeight();

	int reset();

protected:
	int data;
	Node *leftChild;
	Node *rightChild;
	int height;
	int balance;
};