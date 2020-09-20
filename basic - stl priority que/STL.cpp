#include <iostream>
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>
#include <vector>
#include <ctime>
#include <time.h>
#include <queue>
using namespace std;
/* TODO
the synced vectors in vertex sould be replaced with a single struct vector
the vector should be an array 
the input file sould be read from input not hardcoded
the whole input file function sould be in a seperate file
*/
class vertex {
  public:
  vector <int> neighbours;
  vector <int> NeighboursLength;
    bool seen=false;
  int weight;
  int last=-1;
};
class sortvertexes {
  public:
    bool operator()(vertex * v1, vertex * v2) {
        if(v1->seen&&v2->seen){
      return (v1-> weight > v2-> weight);}
        else if(v1->seen){
      return true;}
        if(v2->seen){
      return false;}
//nither has been see they are equivalent
return false;
    }
};
void load(int * GraphSize, int * edgeCount, vector < vertex * > & vertices) {
  ifstream input("soc-sign-bitcoinotc.csv", ifstream:: in );
  if (input.is_open()) {
    input >> * GraphSize;
    input.ignore(256, '\n');
    input >> * edgeCount;
    input.ignore(256, '\n');
    //cout<<*GraphSize<<"\n";
    //cout<<*edgeCount<<"\n";
    for (int x = 0; x < * GraphSize; x++) {
      vertices.push_back(new vertex());
    }
    for (int x = 0; x < * edgeCount; x++) {
      int from, to, weight;
      input >> from;
      from--;
      input.ignore(256, ',');
      input >> to;
      to--;
      input.ignore(256, ',');
      input >> weight;
      //cout<<x<<"\n";
      //cout<<from<<" "<<to<<" "<<weight<<"\n";
      vertices[from] -> neighbours.push_back(to);
      vertices[from] -> NeighboursLength.push_back(weight);
      vertices[to] -> neighbours.push_back(from);
      vertices[to] -> NeighboursLength.push_back(weight);
    }
  } else {
    cout << "could not open file " << "\n";
  }

}
// sudocode is from wikipeda
void Dijkstra(vector <vertex*> & vertices, int startindex) {
   /*
   1  function Dijkstra(Graph, source):
   
   3      create vertex set Q
   */
  priority_queue <vertex*,vector <vertex*>,sortvertexes> pq;
   /*
   5      for each vertex v in Graph:            
   6          dist[v] ← INFINITY                 
   7          prev[v] ← UNDEFINED                
   8          add v to Q                     
  10      dist[source] ← 0                       
  */
//we dont need to add all the vertexes into the queue at the start, just the first one
    vertices[startindex]->seen=true;
    vertices[startindex]->weight=0;
    vertices[startindex]->last=startindex;
    pq.push(vertices[startindex]);
  /*
  12      while Q is not empty:
  13          u ← vertex in Q with min dist[u]   
  14                                             
  15          remove u from Q
  16         
  17          for each neighbor v of u:           // only v that are still in Q
  18              alt ← dist[u] + length(u, v)
  19              if alt < dist[v]:              
  20                  dist[v] ← alt
  21                  prev[v] ← u
  22
  23      return dist[], prev[]
  */

}

int main() {
  int * GraphSize = new int();
  int * edgeCount = new int();
  vector < vertex * > vertices;
  load(GraphSize, edgeCount, vertices);
  Dijkstra(vertices, 0);
  // cout<<*GraphSize<<"\n";
  //  cout<<*edgeCount<<"\n";
  //      cout<<vertices[1]->neighbours[0]<<"\n";
  return 0;
}

/*  vertex * v1 = new vertex();
  v1 -> weight = 10;
  pq.push(v1);

  vertex * v2 = new vertex();
  v2 -> weight = 20;
  pq.push(v2);
  vertex * v3 = new vertex();
  v3 -> weight = 69;
  pq.push(v3);

  v3 -> weight = 6;
  vertex * vt;
  vt = pq.top();
  pq.pop();
  pq.push(vt);
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();
  cout << pq.top() -> weight << "\n";
  pq.pop();*/

