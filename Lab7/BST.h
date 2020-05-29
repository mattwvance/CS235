#pragma once
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST: public BSTInterface
{
public:
    BST() {}
    virtual ~BST() {}

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface
    /*
    *
    */
    Node* inOrder(Node* node, int val) {};
    /*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
    Node* getRootNode() const {};
    /*
    * returns the size of the BST
    */
    int size() const;
    /*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
    bool add(int data) {};
    /*
    * Finds the right node for adding the data by recursion
    */
    Node* recusiveAdd(Node* node, int val) {};
    /*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
    bool remove(int data) {};
    /*
    * Returns the correct Node to remove by recusion it moves down the BST
    */
    Node* recursiveRemove(Node*, int val) {};
    /*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
    void clear() {};
    /*
    * Determines if the value is already in the BST
    */
    bool exists(int val) {};
    /*
    * Checks that the value isn't already in the BST by searching recursively
    * in order
    */
    bool checkExists(Node *node, int val) {};
};