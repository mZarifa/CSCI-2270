#include "BST.hpp"
#include <iostream>

using namespace std;

/* ----------------------------------------
TODO: Complete the method below.
      You may add helpers, headers (if necessary)
      Helper functions should not be part of the class.
*/

Node* print_depths_recursive(Node *n, int val, int counter) //I spent 3 hours on this cuz im dumb but then I realized I can just use the search function you gave
{
    if (n == nullptr)                                       //so I literally stole the given search function and just told it to give me cout statements.
    {
        return n;
    }

    if (val == n->key)
    {
        cout << counter << " ";
        counter = counter+1; //set counter to counter +1
        return print_depths_recursive(n->right, val, counter); //add 1 to the counter, run it again from the right
    }
    else if (val > n->key)
    {
        counter = counter+1;
        return print_depths_recursive(n->right, val, counter); //add 1 to the counter, run it again from the right
    }
    else
    {
        counter = counter+1;
        return print_depths_recursive(n->left, val, counter); //add 1 to the counter, run it again from the left
    }
}

void BST::print_depths(int val)
{
    root = print_depths_recursive(root, val, 0); //aight its big recursive hours
}

// ----------------------------------------

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    recursive_destroy(root);
    root = nullptr;
}

void BST::print()
{
    print2DUtil(root);
}

void BST::insert(int val)
{
    root = recursive_insert(root, val);
}

Node *BST::search(int val)
{
    return recursive_search(root, val);
}

void BST::inorder()
{
    recursive_inorder(root);
}

// -----------------
// RECURSIVE HELPERS
// -----------------
void recursive_destroy(Node *n)
{
    if (n)
    {
        recursive_destroy(n->left);
        recursive_destroy(n->right);
        delete n;
    }
}

Node *recursive_insert(Node *n, int val)
{
    if (n == nullptr)
    {
        Node *tmp = new Node({val, nullptr, nullptr});
        return tmp;
    }
    else if (val >= n->key)
    {
        n->right = recursive_insert(n->right, val);
    }
    else
    {
        n->left = recursive_insert(n->left, val);
    }

    return n;
}

Node *recursive_search(Node *n, int val)
{
    if (!n)
    {
        return nullptr;
    }

    if (val == n->key)
    {
        return n;
    }
    else if (val > n->key)
    {
        return recursive_search(n->right, val);
    }
    else
    {
        return recursive_search(n->left, val);
    }
}

void recursive_inorder(Node *n)
{
    if (n)
    {
        recursive_inorder(n->left);
        cout << n->key << " ";
        recursive_inorder(n->right);
    }
}

void print2DUtil(Node *n, int space, int COUNT)
{
    if (n == NULL)
        return;

    space += COUNT;

    print2DUtil(n->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << n->key << "\n";

    print2DUtil(n->left, space);
}