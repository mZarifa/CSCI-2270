#include <iostream>
#include "LinkedList.hpp"

using namespace std;

/* ----------------------------------------
TODO: Complete the method below.
      You may add helpers, headers (if necessary)
      Helper functions should not be part of the class.
*/

void LinkedList::moveEvens()
{
    Node *end = head;
    Node *curr = head;
    Node *prev = NULL;

    while (end->next != NULL)
    {
        end = end->next; //iterate through until reaching the node that is NULL. This is the end node.
    }

    Node *new_end = end; //create a node called new_end and set that to the pointer we just got (the one just before NULL)

    while (curr->key % 2 != 0 && curr != end) //first, consider the odd nodes, and the not end node, as long as its odd, do the following...
    {
        new_end->next = curr;       //the next in line is now the current node.
        curr = curr->next;          //set the current value to the next value.
        new_end->next->next = NULL; //set the final node to the NULL.
        new_end = new_end->next;    //our old new end node is now pointing to the old one's next value. THIS A LOOP BABY.
    }

    if (curr->key % 2 == 0) //if the node is even
    {
        head = curr; //change the head to point to the current EVEN node.
        while (curr != end)
        {
            if ((curr->key) % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else
    {
        prev = curr; //break point. Set that previous node to the current one. 
    }

    if (new_end != end && (end->key) % 2 != 0) //If there are more than 1 odd nodes, and end of original list is odd then move to end to maintain the order
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    Node *temp = head;
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::append(int key)
{
    // Function: Creates and inserts a new node at the END of list
    Node *newNode = new Node({key, nullptr});
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

string LinkedList::print()
{
    // Returns the same output as string for testcase verification
    Node *temp = head;
    string s = "";
    while (temp)
    {
        s = s + to_string(temp->key) + " -> ";
        temp = temp->next;
    }
    s = s + "NULL\n";

    cout << s;
    return s;
}