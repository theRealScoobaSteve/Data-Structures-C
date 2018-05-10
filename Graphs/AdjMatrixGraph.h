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
        vertex = new vector<string>( 7, "" );
        matrix = new vector<vector<int>>( 7, vector<int>( 7, 0 ) );
        vertCount = 0;
    }

    AdjMatrixGraph( int capacity ) {
        this->capacity = capacity;
        vertex = new vector<string>( capacity );
        matrix = new vector<vector<int>>( capacity, vector<int>( capacity, 0 ) );
        vertCount = 0;
    }

    AdjMatrixGraph( vector<vector<string>> graphData ) {
        capacity = 5;
        vertex = new vector<string>( 7, "" );
        matrix = new vector<vector<int>>( 7, vector<int>( 7, 0 ) );
        vertCount = 0;
    }

    ~AdjMatrixGraph() {
        vertex->clear();
        matrix->clear();
    }

    void createGraph( vector<vector<string>> &hold ) {
        vertCount = hold.size();
        for( int i = 0; i < hold.size(); ++i ){
            ( *vertex )[i] = hold[i][0];
        }

        for( int i = 0; i < hold.size(); ++i ){
            for( int n = 1; n < hold[i].size(); ++n ){
                int j = getIndex(hold[i][n]);
                ( *matrix )[i][j] = 1;
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

        return -1;
    }

    void insertVertex(string vertex, vector<string>pre, vector<string>suc){

        ( *this->vertex )[vertCount] = vertex;

        //	Shove it in by row for successors
        for( int i = 0; i < suc.size(); ++i ){
            int j = getIndex( suc[i] );
            ( *matrix )[vertCount][j] = 1;
        }

        //	Shove it in by col for predecessors
        for( int i = 0; i < pre.size(); ++i ){
            int j = getIndex( pre[i] );
            ( *matrix )[j][vertCount] = 1;
        }

        ++vertCount;
    }

    void print() {
        for(int i = 0; i < vertCount; ++i){
            cout << "VERTEX: " << ( *vertex )[i] << endl;
            cout << "LEADS TO: " << endl;
            for(int j = 0; j < vertCount; ++j){
                if(( *matrix )[i][j]){
                    cout << ( *vertex )[j] << endl;
                }
            }
            cout << endl;
        }
    }

private:
    vector<string>          *vertex;
    vector<vector<int>>     *matrix;
    int                      vertCount;
    int                      capacity;

};

#endif //GRAPHS_ADJMATRIXGRAPH_H
