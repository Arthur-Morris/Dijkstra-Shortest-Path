#include <iostream>
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>
#include <vector>
#include <ctime>
#include <time.h>
using namespace std;
/* TODO
the synced vectors in vertex sould be replaced with a single struct vector
the vector should be an array 
the input file sould be read from input not hardcoded
*/
class vertex {
public:
    vector <int> neighbours;
    vector <int> NeighboursLength;
    int weight;
    int last;
};

void load(int* GraphSize,int* edgeCount,vector <vertex*> &vertices) {
    ifstream input("soc-sign-bitcoinotc.csv", ifstream::in);    
    if (input.is_open())
    {
        input>> *GraphSize;
        input.ignore(256,'\n');
        input>>*edgeCount;
        input.ignore(256,'\n');
        cout<<*GraphSize<<"\n";
        cout<<*edgeCount<<"\n";
        for (int x=0;x<*GraphSize;x++)
        {
            vertices.push_back(new vertex());
        }
        for(int x =0;x<10000;x++)
        {
            int from,to,weight;
            input>>from;
            from--;
            input.ignore(256,',');
            input>>to;
            to--;
            input.ignore(256,',');
            input>>weight;
           // cout<<from<<" "<<to<<" "<<weight<<"\n";
            vertices[from]->neighbours.push_back(to);
            vertices[from]->NeighboursLength.push_back(weight);
            vertices[to]->neighbours.push_back(from);
            vertices[to]->NeighboursLength.push_back(weight);
        }
        
            cout<<vertices[1]->neighbours[0]<<"\n";
    }
    else
    {
        cout<<"could not open file "<<"\n";
    }
    
}

void Dijkstra(int* GraphSize,int* edgeCount,vector <vertex*> &vertices)
{
    
}

int main() {
    int* GraphSize=new int();
    int* edgeCount=new int();
    vector <vertex*> vertices;
    load(GraphSize,edgeCount,vertices);
    
        cout<<*GraphSize<<"\n";
        cout<<*edgeCount<<"\n";
            cout<<vertices[1]->neighbours[0]<<"\n";
    return 0;
}
