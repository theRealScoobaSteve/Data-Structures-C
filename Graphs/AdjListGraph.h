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
        capacity = 6;
        myList = new vector<AnyList>(6);
        vertex = new vector<string>(6);
        vertCount = 0;
    }


    AdjListGraph( int vert ) {
        capacity = vert;
        myList = new vector<AnyList>(vert);
        vertex = new vector<string>(vert);
        vertCount = 0;
    }

    // copy constructor
    AdjListGraph( const AdjListGraph &temp ) {
        capacity = temp.capacity;
        vertCount = temp.vertCount;
        myList = new vector<AnyList>( capacity );
        vertex = new vector<string>( capacity );

        for( int i = 0; i < temp.capacity; i++ ) {
            myList[i] = temp.myList[i];
            vertex[i] = temp.vertex[i];

        }

    }

    // move constructor
    AdjListGraph( AdjListGraph&& copy ):
            vertCount( copy.vertCount ), capacity( copy.capacity ),
            vertex( copy.vertex ), myList( copy.myList ){
        copy.myList = nullptr;
        copy.vertex = nullptr;
    }

    //copy assignment almost got it to work
    AdjListGraph& operator=( AdjListGraph& copy ){
        emptyGraph();

        vertCount = copy.vertCount;
        capacity = copy.capacity;

        for(int i = 0; i < capacity; ++i){

//            if(copy.myList[i]){
//                myList[i] = new AnyList( copy->myList[i] );
//            }
//
//            else{
//                myList[i] = nullptr;
//            }

            myList[i] = copy.myList[i];
        }
    }

    // move assignment
    AdjListGraph& operator=( AdjListGraph&& copy ){
        emptyGraph();
        vertCount = copy.vertCount;
        capacity = copy.capacity;
        vertex = copy.vertex;
        myList = copy.myList;
        copy.vertex = nullptr;
        copy.myList= nullptr;
    }

    ~AdjListGraph() { myList->clear(); vertex->clear(); }


    void createGraph( vector<vector<string>> graphData ) {

        for( int i = 0; i < graphData.size(); i++ ) {
            ( *vertex )[i] = graphData[i][0];
        }

        for( int i = 0;i < graphData.size(); i++ ) {
            string position = graphData[i][0];
            if( position == ( *vertex )[0] ) {
                for( int l = 1; l < graphData[i].size(); l++ ) {
                    ( *myList )[0].insert( graphData[i][l] );
                }

            }
            if( position == ( *vertex )[1] ) {
                for( int l = 1; l < graphData[i].size();l++ ) {
                    ( *myList )[1].insert( graphData[i][l] );

                }

            }
            if( position == ( *vertex )[2] ) {
                for( int l = 1; l < graphData[i].size(); l++ ) {
                    ( *myList )[2].insert( graphData[i][l] );
                }

            }
            if( position == ( *vertex )[3] ) {
                for( int l = 1; l < graphData[i].size(); l++ ) {
                    ( *myList )[3].insert( graphData[i][l] );
                }

            }
            if( position == ( *vertex )[4] ) {
                for(int l = 1; l < graphData[i].size();l++) {
                    ( *myList )[4].insert( graphData[i][l] );
                }

            }
        }
        vertCount++;

    }

    void emptyGraph() {
        for( int i = 0; i < capacity; ++i ) {
            ( *myList )[i].destroyList();
            ( *vertex )[i] = "";
        }
    }


    void insertVertex( string vert, vector<string> predecessor, vector<string> successor )
    {
        AnyList temp;
        ( *vertex ).push_back(vert);
        vertCount++;
        capacity++;

        //find predecessors and insert the new vertex into them
        for( int i = 0; i < predecessor.size(); i++ ) {
            if( predecessor[i] == ( *vertex )[0] ) {
                ( *myList )[0].insert(vert);

            }
            if( predecessor[i] == ( *vertex )[1]) {
                ( *myList )[1].insert( vert );

            }
            if( predecessor[i] == ( *vertex )[2] ) {
                ( *myList )[2].insert(vert);

            }
            if(predecessor[i] == ( *vertex )[3]) {
                ( *myList )[3].insert(vert);

            }
            if( predecessor[i] == ( *vertex )[4] )
            {
                ( *myList )[4].insert( vert );
            }
        }

        //insert successors
        for( int i = 0; i < successor.size();i++ ) {
            temp.insert( successor[i] );
        }
        ( *myList ).push_back( temp );

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
