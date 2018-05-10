//
// Created by steph on 5/7/2018.
//

#ifndef GRAPHS_ADJLISTGRAPH_H
#define GRAPHS_ADJLISTGRAPH_H

#include <vector>
#include <string>
#include <iostream>
#include "AnyList.h"
using namespace std;

class AdjListGraph{
public:
    AdjListGraph() {
        capacity = 5;
        myList = new vector<AnyList>(capacity);
        vertex = new vector<string>(capacity);
        vertCount = 0;
    }


    AdjListGraph( int vert ) {
        capacity = vert;
        myList = new vector<AnyList>(vert);
        vertex = new vector<string>(vert);
        vertCount = 0;
    }

    ~AdjListGraph() { myList->clear(); vertex->clear(); }


    void createGraph( vector<vector<string>> graphData ) {
        int index;
        for( int i = 0;i < graphData.size();i++ ) {
            string position = graphData[i][0];
            if(position == "A") {
                for( int l = 1; l < graphData[i].size();l++ ) {
                    ( *myList )[0].insert( graphData[i][l] );
                }
                ( *vertex )[0] = "A";
            }
            if( position == "B" ) {
                for( int l = 1; l < graphData[i].size();l++ ) {
                    ( *myList )[1].insert( graphData[i][l] );

                }
                ( *vertex )[1] = "B";

            }
            if( position == "C" ) {
                for( int l = 1; l < graphData[i].size();l++ ) {
                    ( *myList )[2].insert( graphData[i][l] );
                }
                ( *vertex )[2] = "C";

            }
            if( position == "D" ) {
                for( int l = 1; l < graphData[i].size();l++ ) {
                    ( *myList )[3].insert( graphData[i][l] );
                }
                ( *vertex )[3] = "D";

            }
            if( position == "E" ) {
                for( int l = 1; l < graphData[i].size();l++ ) {
                    ( *myList )[4].insert(graphData[i][l]);
                }
                ( *vertex )[4] = "E";

            }
        }

    }

    void emptyGraph() {
        for( int i = 0; i < capacity; ++i ) {
            ( *myList )[i].destroyList();
            ( *vertex )[i] = "";
        }
    }


    void insertVertex( string vertex, vector<string> pre, vector<string> suc ){

        //	Pushes successors
        ( *this->vertex )[vertCount] = vertex;
        for(int i = 0; i < suc.size(); ++i){
            ( *myList )[vertCount].push_back(suc[i]);
        }

        //	Pushes successor as current vertex to the precedecessors
        for(int i = 0; i < pre.size(); ++i){
            for(int j = 0; j < vertCount; ++j){
                if(pre[i] == ( *this->vertex )[j]){
                    ( *myList )[j].push_back(vertex);
                }
            }
        }

    }

    void print() {
        for( int i = 0; i < capacity; i++ ) {
            cout << ( *vertex )[i] << ": ";
            ( *myList )[i].printList();
            cout << endl;

        }
    }

private:
    vector<string>  *vertex;
    vector<AnyList> *myList;
    int             vertCount;
    int             capacity;
};

#endif //GRAPHS_ADJLISTGRAPH_H
