#include <iostream>
#include "AdjListGraph.h"
#include "AdjMatrixGraph.h"

int main() {
    vector <vector<string>> graphData = {
            { "A" , "B" , "F" } , { "B" , "C" , "D" , "F" } , { "C" , "E" } ,
            { "D" } , { "E" , "D" , "F" } , { "F" , "D" } ,
    };
    AdjMatrixGraph graph;
    graph.createGraph( graphData );
//    graph.print();


    return 0;
}