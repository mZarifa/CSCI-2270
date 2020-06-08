#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <queue>


using namespace std;

void Graph::addEdge(string source, string target){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == target && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == vName){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = vName;
        vertices.push_back(v);
    }
}

void Graph::display(){
    cout<<"vertex"<<":"<<"color"<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<vertices[i]->color<<endl;

    }
}


void Graph::color(string source)
{
    vertex *startPoint; //create vertex called startPoint
    for(unsigned i = 0; i < vertices.size(); i++) //run through the size of the verticies
    {
        if(vertices[i] -> name == source) //if the name of verticies at position i is the same as the source string...
        {
            startPoint = vertices[i]; //that must be the startPoint vertex
        }
    }
    startPoint -> visited = true; //set the start point's status of whether it's visited or not to true.
    queue<vertex*> tempQueue; //create a queue called tempQueue
    tempQueue.push(startPoint); //add the startPoint vertex to the queue
    vertex *nextVertex; //create a vertex called nextVertex.
    // standard BFS
    startPoint -> color = "black"; //set the startPoint's color to black.
    while(!tempQueue.empty()) //while the tempQueue isn't empty
    {
        nextVertex = tempQueue.front();
        tempQueue.pop();
        for(unsigned i = 0; i < nextVertex -> adj.size(); i++)
        {
            if(nextVertex -> adj[i].v -> visited == false)// If the adjacent has not been visited
            {
                nextVertex -> adj[i].v -> visited = true; //mark as visited, then enqueue it
                nextVertex -> adj[i].v -> distance = nextVertex -> distance + 1; //update distance of nextVertex variable
                tempQueue.push(nextVertex -> adj[i].v); // Stop when you reach the destination vertex
                if(nextVertex->adj[i].v->distance % 2 == 0)
                {
                    nextVertex->adj[i].v->color = "black"; //if the distance divided by 2 is 0, make it black
                }
                else
                {
                    nextVertex->adj[i].v->color = "red"; //else it's red 4head
                }
            }
        }
    }
}
