#pragma once
#include <string>
#include "LinkedListInterface.h"
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList: public LinkedListInterface <T>
{
public:

    Node<T>* head;

    LinkedList(){ head = NULL; };
    ~LinkedList(){};

    /*
        checks that there isn't a duplicate in the list
    */
    bool checkDuplicate(T value) {
        Node<T>* val = head;
        while (val != NULL) {
            if(val->data == value) {
                return true;
            }
            val = val->next;
        }
        return false;
    };

    /*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
    void insertHead(T value) {
        if (checkDuplicate(value)) { return; }
        if (head == NULL) {
            head = new Node<T>(value);
        } else {
            Node<T>* val = new Node<T>(value);
            val->next = head;
            head = val;
        }
    };

    /*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
    void insertTail(T value) {
        if (checkDuplicate(value)) { return; }
        if (head == NULL) {
            insertHead(value);
            return;
        }
        Node<T>* val = head;
        while (val->next != NULL) {
            val = val->next;
        }
        if (val->next == NULL) {
            Node<T>* node = new Node<T>(value);
            val->next = node;
            node->next = NULL;
        }
    };

    /*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
    void insertAfter(T value, T insertionNode) {
        if (checkDuplicate(value)) { return; }
        Node<T>* val = head;
        while(val != NULL) {
            if (val->data == insertionNode) {
                Node<T> *node = new Node<T>(value);
                node->next = val->next;
                val->next = node;
            }
            val = val->next;
        }
    };

    /*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
    void remove(T value) {};

    /*
	clear

	Remove all nodes from the list.
	*/
    void clear() {};

    /*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
    T at(int index) {
        if (index >= size() || index < 0) {
            return NULL;
        } else {
            Node<T>* node = head;
            int j = 0;
            while (node != NULL) {
                if (j == index) {
                    return node->data;
                }
                ++j;
                node = node->next;
            }
        }
    };

    /*
	size

	Returns the number of nodes in the list.
	*/
    int size() {
        Node<T>* node = head;
        int j = 0;
        while (node != NULL) {
            node = node->next;
            ++j;
        }
        return j;
    };

    /*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
    string toString() { 
        return "";
    };
};