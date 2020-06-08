#include "ProducerConsumer.hpp"
#include "ProducerConsumer.cpp"
#include <iostream>

using namespace std;

int main()
{
    ProducerConsumer pc;
    pc.enqueue("item1");
    pc.enqueue("item2");
    pc.enqueue("item3");
    pc.enqueue("item4");
    string * q = pc.getQueue();
    cout << "Print queue from front to back:" << endl;
    for(int i=1; i<4; i++) cout << q[i] << endl;
}