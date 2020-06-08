#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

/*
PUBLIC METHODS:
*/

// Constructor definitions:
// Default:
BST::BST()
{
    root = nullptr;
}

void BST::addNode(int data)
{
    root = addNodeHelper(root, data);
    cout<< data <<" has been added"<<endl;
}

void BST::print2DUtil(int space)
{
    print2DUtilHelper(root, space);
}

/*
PRIVATE METHODS:
*/


//  TODO:
//  Write a function decrementLeaves that goes through a Binary Search Tree 
//  and subtracts 1 from each of the leaf nodes. Feel free to implement an 
//  additional helper function.


void decrementHelper(Node* leafNode)
{
    if(leafNode != nullptr) //check if nullptr
    {
        if(leafNode -> left != nullptr) //if left isn't null
        {
            decrementHelper(leafNode -> left); //recursion time baby
        }
        if(leafNode -> right != nullptr) //now if right isnt null
        {
            decrementHelper(leafNode -> right); //recursion time baby
        }
        if(leafNode -> left == nullptr && leafNode -> right == nullptr) //so now if the left is null and the right is null
        {
            leafNode -> key = leafNode -> key -1; //subtract 1 from its value.




            if(leafNode -> parent -> left == leafNode) //if the leaf node's parent's left node is the same as it
            {
                if(leafNode -> parent >= leafNode) //if the leaf node's parent is greater or equal to than itself 
                {
                    leafNode -> parent -> left = nullptr;
                    delete leafNode; //delete the left node
                }
            }
            else
            {
                if(leafNode -> key < leafNode -> parent -> key) //if the leaf node's value is less than it's parent's value
                {
                    leafNode -> parent -> right = nullptr;
                    delete leafNode; //delete the right node
                }
            }
        }

    }
}

void BST::decrement()
{
    decrementHelper(root);
} 


//   This function will add the data in the tree rooted at currNode.
//   Call this function from insert().


Node* BST:: addNodeHelper(Node* currNode, int data){
    if(currNode == nullptr){
       return createNode(data);      
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
        currNode->right->parent = currNode;
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
        currNode->left->parent = currNode;
    }
    return currNode;
}


// Create a new node, setting key value to  input data
// and all pointers to null.
Node* BST:: createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* BST::getRoot(){
    return root;
}


/*
   Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space){
    // Base case
    if (currNode == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right leafNode first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left leafNode
    print2DUtilHelper(currNode->left, space);
}





