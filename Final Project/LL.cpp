#include "LL.hpp"

#include <iostream>
using namespace std;

// Add a new node to the list
void LL::addNode(int newKey){
  if(head == nullptr){
    head = new Node2;
    head->key = newKey;
    head->next = NULL;
  }
  else{
    Node2* tempNode = head;
    
    while(tempNode != nullptr && tempNode->next !=nullptr){
      tempNode = tempNode->next;
    }
    Node2* newNode = new Node2;
    tempNode->next = newNode;
    newNode->key = newKey;
    newNode->next = NULL;
  }
}

// Add a new node to the list
void LL::insert(Node2* prev, int newKey){

  //Check if head is Null (list is empty)
  if(head == nullptr){
    head = new Node2;
    head->key = newKey;
    head->next = nullptr;
    
  }

  // if list is not empty, look for prev and append node there
  else if(prev == nullptr){
    Node2* newNode = new Node2;
    newNode->key = newKey;
    newNode->next = head;
    head = newNode;
  }

  else{
    Node2* newNode = new Node2;
    newNode->key = newKey;
    newNode->next = prev->next;
    prev->next = newNode;
  }
  //cout << newKey << " has been added" << endl;
}


// Search for a specified key and return a pointer to that node
Node2* LL::searchList(int key) {

    Node2* ptr = head;
    while (ptr != nullptr && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}


// Print the keys in your list
void LL::printList(){
  Node2* temp = head;

  while(temp->next != nullptr){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}