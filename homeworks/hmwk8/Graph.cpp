#include "Graph.hpp"
#include <iostream>
using namespace std;

void Graph::addVertex(string n)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == n)
        {
            found = true;
        }
    }
    if(found == false)
    {
        vertex * v = new vertex;
        v->name = n;
        vertices.push_back(v);
    }
}

void Graph::addEdge(string v1, string v2)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j]->name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::displayEdges()
{

    //loop through all vertices and adjacent vertices
    for(int i = 0; i < (int)vertices.size(); i++){
        cout<<vertices[i]->name<<" --> ";
        for(int j = 0; j < (int)vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout<<endl;
    }

}

void Graph::breadthFirstTraverse(string sourceVertex){

    // Need to find the source vertex since we only have it's key 'src'
    // A pointer for source vertex
    vertex *vStart;
    cout<< "Starting vertex (root): " << sourceVertex << "->";
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            vStart = vertices[i];
        }
    }

    vStart->visited = true;

    // Use the queue to keep track of visited vertices
    queue<vertex*> q;

    // Enqueue the source vertex
    q.push(vStart);

    vertex *n;

    // standard BFS
    while(!q.empty()){

        n = q.front();
        q.pop();

        // go to all the adjacent vertices of
//cout << n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " ";
        for( unsigned x = 0; x < n->adj.size(); x++ )
        {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            // Stop when you reach the destination vertex and return the needful
            if(n->adj[x].v->visited == false){
              n->adj[x].v->visited = true;
              n->adj[x].v->distance = n->distance + 1;
              //n->adj[x].v->pred = n;
            // for other vertex traversed from source vertex with distance
            cout <<" " <<n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " ";

              q.push(n->adj[x].v);
              //Then throw it inside of the queue
              //q.push(n->adj[x].v)
            }
            //if(n->adj[x].v->key==dest){
             // return n->adj[x].v->distance;
           // }
        }
    }
    return;
}

void dft( vertex *vurt)
{
  vurt->visited = true;
  for(unsigned x = 0; x < vurt->adj.size(); x++){
    if(!vurt->adj[x].v->visited){
      dft(vurt->adj[x].v);
    }
  }
}


int Graph::getConnectedComponents(){
  int oof = 0;
  for(unsigned x = 0; x < vertices.size(); x++){
    if(!vertices[x]->visited){
      dft(vertices[x]);
      oof++;
    }
  }
  return oof;
}

bool Graph::checkBipartite(){
    vertex *Starter;
for(unsigned int i = 0; i<vertices.size(); i++){
  Starter = vertices[i];
  if(!Starter->visited){

  Starter->visited = true;
  Starter->color = "red";
  queue<vertex*> q;
  q.push(Starter);
  vertex *n;
  // standard BFS
  while(!q.empty()){
      n = q.front();
      q.pop();
      // go to all the adjacent vertices of n
      for(unsigned int x = 0; x < n->adj.size(); x++ )
      {
        if(n->adj[x].v->visited==false){
          n->adj[x].v->visited=true;
          if(n->color=="red"){
            n->adj[x].v->color="blue";
          }
          if(n->color=="blue"){
            n->adj[x].v->color="red";
          }
          q.push(n->adj[x].v);
        }
      }
    }
  }
}
  for(unsigned int i= 0; i<vertices.size(); i++){
    //n=vertices[i];
      for(unsigned int j=0;j<vertices[i]->adj.size();j++){
        if(vertices[i]->color==vertices[i]->adj[j].v->color){
          return 0;
        }
    }
  }
  return 1;
}
