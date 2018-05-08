//
// Created by steph on 5/7/2018.
//

#ifndef GRAPHS_ADJLISTGRAPH_H
#define GRAPHS_ADJLISTGRAPH_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AdjListGraph {
public:
    AdjListGraph() {
        vCount = 100;
        capacity = vCount * 2;
        graph = {};
    }

    AdjListGraph( int vCount ) {
        capacity = vCount * 2;
        this->vCount = vCount;
        graph = {};
    }

    void addEdge( vector<vector<string>> graph ) {
        this->graph = graph;
    }

private:
    vector<vector<string>> graph;
    int            vCount;
    int            capacity;
};

#endif //GRAPHS_ADJLISTGRAPH_H
