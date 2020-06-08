#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct Node3
{
    int key;
    struct Node3* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    Node3* *table;
    int numOfcolision =0;
    Node3* createNode(int key, Node3* next);

public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    Node3* searchItem(int key);
};

#endif
