//
// Created by steph on 5/15/2018.
//

#ifndef DIJKSTRA_GRAPHTYPE_H
#define DIJKSTRA_GRAPHTYPE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <list>
using namespace std;

class graphType {
public:

    // Function to determine whether the graph is empty.
    bool isEmpty() const {
        return gSize == 0;
    }

    // Creates a graph using an adjacency list
    void createGraph(){
        ifstream infile;
        string fileName = "words.txt";
        int index;
        int vertex;
        int adjacentVertex;

        if( gSize != 0 ) {
            clearGraph();
        }

        if( !infile ) {
            cout << "Cannot open the input file";
            return;
        }

        infile >> gSize;

        for( index = 0; index < gSize; ++index ) {
            infile >> vertex;
            infile >> adjacentVertex;

            while( adjacentVertex != -999 ) {
                graph[vertex].push_back(  adjacentVertex );
                infile >> adjacentVertex;
            }
        }

        infile.close();
    }

    // Deletes the graph
    void clearGraph() {
        for( int i = 0; i < gSize; ++i ) {
            graph[i].clear();
        }

        gSize = 0;
    }

    // Prints the graph
    void printGraph() const {
        for ( int i = 0; i < gSize; ++i ) {
            cout << i << " ";
            list<int> :: iterator it;
            for( *it = graph[i].front(); it != graph[i].end(); ++it ) {
                cout << *it << " ";
            }

        }
    }

    // The vertices of the graph are printed using Depth Breadth Traversal
    void depthFirstTraversal() {
        bool *visited = new bool[gSize];

        for( int i = 0; i < gSize; ++i ) {
            visited[i] = false;
        }

        for( int i = 0; i < gSize; ++i ) {
            if( !visited[i] )
                dft( i, visited );
        }

        delete [] visited;
    }

    // Function to perform the Depth First Traversal of the entire graph
    void dfAtVertex( int vertex ) {
        bool *visited = new bool[gSize];
        for( int i = 0; i < gSize; ++i ) {
            visited[i] = false;

            dft( vertex, visited );

            delete [] visited;
        }
    }

    // Function to perform the breadth first traversal of the entire graph
    void breadthFirstTraversal()  {
        list<int> queue;
        bool *visited = new bool[gSize];

        for( int i = 0; i < gSize; ++i ) {
            visited[i] = false;
        }

        list<int> :: iterator graphIt;

        for( int i = 0; i < gSize; ++i )
            if( !visited[i] ) {
                queue.push_front( i );
                visited[i] = true;
                cout << " " << i << " ";

                while( !queue.empty() ) {
                    int u = queue.front();
                    queue.clear();

                    for( *graphIt = graph[u].front(); graphIt != graph[u].end(); ++graphIt ) {
                        int w = *graphIt;

                        if( !visited[w] ) {
                            queue.push_front( w );
                            visited[w] = true;
                            cout << " " << w << " ";
                        }
                    }
                }
            }

        delete [] visited;
    }

    graphType( int size = 0 ) {
        maxSize = size;
        gSize = 0;
        graph = new list<int>[size];
    }

    ~graphType() {
        clearGraph();
    }

protected:
    int maxSize;
    int gSize;
    list<int> *graph;

private:

    // Function to perform the depth first traversal of the graph at a node specified by the parameter vertex
    // This function is used by the public member functions.
    void dft( int v, bool visited[] ) {

    }

};

#endif //DIJKSTRA_GRAPHTYPE_H
