#include <iostream>
#include "AdjListGraph.h"
#include "AdjMatrixGraph.h"

int main() {
    vector < vector < string > > graphData = {
              { "A" , "B" , "F" } , { "B" , "C" , "D" , "F" } , { "C" , "E" }
            , { "D" , "D" , "F" } , { "E" , "D" }, { "F" }
    };

    AdjListGraph table1;
    AdjMatrixGraph table2;

    table1.createGraph( graphData );
    table2.createGraph( graphData );

    string G = "G";
    vector<string> pre {"D", "F"};
    vector<string> suc {"A", "B"};

    table1.insertVertex(G, pre, suc);
    table2.insertVertex(G, pre, suc);

    cout << "THIS IS ADJLIST GRAPH" << endl;
    table1.print();
    cout << endl << endl;

    cout << "THIS IS ADJMATRIX GRAPH" << endl;
    table2.print();


    return 0;
}