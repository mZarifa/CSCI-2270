#include "ProducerConsumer.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int bailout = 0;
int input;

void menu()
{
    ProducerConsumer pc;
    while (bailout != 1)
    {
        cout << "*----------------------------------------*" << endl;
        cout << "Choose an option:" << endl;
        cout << "1. Producer (Produce items into the queue)" << endl;
        cout << "2. Consumer (Consume items from the queue)" << endl;
        cout << "3. Return the queue size and exit" << endl;
        cin >> input;
        
        if (input == 1)
        {
            cout << "*----------------------------------------*" << endl;
            cout << "Enter the number of items to be produced:" << endl;
            int numitems;
            cin >> numitems;
            cin.ignore();
            for (int i = 0; i < numitems; i++)
            {
                cout << "Item" << i+1 << ":" << endl;
                string itemName = "";
                getline (cin, itemName);
                pc.enqueue(itemName);
            }
        }
        if (input == 2)
        {
            cout << "*----------------------------------------*" << endl;
            cout << "Enter the number of items to be consumed:" << endl;
            string consumeitem = "";
            int consumeNum;
            cin >> consumeNum;
            for (int j = 0; j < consumeNum; j++)
            {
                cout << "Consumed: " << pc.peek() << endl;
                pc.dequeue();
                if (pc.isEmpty())
                {
                    cout << "No more items to consume from queue" << endl;
                    break;
                }
            }
        }
        if (input == 3)
        {
            cout << "*----------------------------------------*" << endl;
            cout << "Number of items in the queue:" << pc.queueSize() << endl;
            bailout = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    menu();
}

