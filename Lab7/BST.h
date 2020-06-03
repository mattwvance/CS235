#pragma once
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST: public BSTInterface
{
public:
    BST() { root = NULL; };
    virtual ~BST() { this->clear(); };

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface
    /*
    *
    */
    void inOrder(Node* node, Node*& parent);
    /*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
    Node * getRootNode() const;
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
    bool add(const int data);
    /*
    * Finds the right node for adding the data by recursion
    */
    bool recursiveAdd(Node*& node, const int val);
    /*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
    bool remove(int data);
    /*
    * Returns the correct Node to remove by recusion it moves down the BST
    */
    bool recursiveRemove(Node*& node, int val);
    /*
    * Finds right most Node from local root
    */
    Node* findRightMost(Node*& val);
    /*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
    void clear();
    /*
    * clears the entire tree
    */
    void recursiveClear(Node* root);

protected:
    Node *root;
};