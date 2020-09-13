#include <iostream>
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>
#include <vector>
using namespace std;
/* TODO
i have realised it is not very useful to test against random graphs this in not useful, i am keeping it just in case
the synced vectors in vertex sould be replaced with a single struct vector
*/
class vertex {
public:
    int degree;
    vector <vertex> neighbours;
    vector <int> NeighboursLength;
};

int main() {
    int GraphSize=1000;
    fstream output;
    const char* OutputFileName="graph.txt";
    output.open(OutputFileName,ios::out);
    int seed = (int) time(0);
    output<<seed<<"\n";
    srand(seed);
    vector <vertex*> vertices;
    for (int x=0;x<GraphSize;x++)
    {
        vertices.push_back(new vertex());
    }
    return 0;
}
