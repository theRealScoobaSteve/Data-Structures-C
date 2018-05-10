//
// Created by steph on 5/9/2018.
//

#ifndef GRAPHS_ADJMATRIXGRAPH_H
#define GRAPHS_ADJMATRIXGRAPH_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AdjMatrixGraph {

public:
    AdjMatrixGraph() {
        capacity = 5;
        vertex = new vector<string>( 5 );
        matrix = new vector<vector<int>>( 5 );
        vertCount = 0;
    }

    AdjMatrixGraph( int capacity ) {
        this->capacity = capacity;
        vertex = new vector<string>( capacity );
        matrix = new vector<vector<int>>( capacity );
        vertCount = 0;
    }

    AdjMatrixGraph( vector<vector<string>> graphData ) {
        capacity = 5;
        vertex = new vector<string>( 5 );
        matrix = new vector<vector<int>>( 5 );
        vertCount = 0;
    }

    ~AdjMatrixGraph() {
        vertex->clear();
        matrix->clear();
    }

    void createGraph( vector<vector<string>> graphData ) {
        for( int i = 0; i < graphData.size(); ++i ) {
            ( *vertex )[i] = ( graphData )[i][0] ;
        }

        for( int i = 0; i < graphData.size(); ++i ) {
            for( int j = 1; j < graphData[i].size(); ++j ) {
                int row = getIndex( ( graphData )[i][j] );
                ( *matrix )[i][row] = 1;
            }
        }
    }

    void emptyGraph() {
        matrix->clear();
    }

    int getIndex( string val ) {
        for( int i = 0; i < vertex->size(); ++i ) {
            if( ( *vertex )[i] == val ) {
                return i;
            }
        }
    }

private:
    vector<string>          *vertex;
    vector<vector<int>>     *matrix;
    int                      vertCount;
    int                      capacity;

};

#endif //GRAPHS_ADJMATRIXGRAPH_H
