#ifndef LL_HPP
#define LL_HPP

using namespace std;

struct Node2
{
    int key;
    Node2 *next;
};

class LL
{
public:
    void addNode(int newKey);
    void insert(Node2 *prev, int newKey);
    Node2 *searchList(int key);
    void printList();

private:
    Node2 *head;
};

#endif