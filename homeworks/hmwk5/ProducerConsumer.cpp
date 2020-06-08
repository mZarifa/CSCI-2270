#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

ProducerConsumer::ProducerConsumer()
{
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty()
{
    if(queueFront == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ProducerConsumer::isFull()
{
    if(queueFront == queueEnd + 1 || (queueFront == 0 && queueEnd == SIZE-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ProducerConsumer::enqueue(std::string player)
{
    if(!isFull() && !isEmpty())
    {
        queue[queueEnd] = player;
        
        if(queueEnd == SIZE-1)
        {
            queueEnd = 0;
        }
        else
        {
            queueEnd++;
        }
        
    }

    else if(!isFull() && isEmpty())
    {
        queueFront++;
        queueEnd++;
        queue[queueFront] = player;
    }
    else
    {
        cout << "Queue full, cannot add new item" << endl;
    }
}

void ProducerConsumer::dequeue()
{
    if(!isEmpty())
    {
        queue[queueFront] = "";
        if(queueFront == SIZE-1)
        {
            queueFront = 0;
        }
        else
        {
            queueFront++;
        }
    }
    else
    {
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
    if(queue[queueFront] == "")
    {
        queueFront = 0;
        queueEnd = 0;
    }
}

int ProducerConsumer::queueSize()
{
    if(queueEnd > queueFront)
    {
        return queueEnd - queueFront;
    }
    else if(isEmpty())
    {
        return 0;
    }
    else
    {
        return queueEnd + 1 + SIZE - queueFront;
    }
}

string ProducerConsumer::peek()
{
    if(!isEmpty())
    {
        return queue[queueFront];
    }
    else
    {
        cout << "Queue empty, cannot peek" << endl;
        return "";
    }
}