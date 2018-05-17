//
// Created by steph on 5/15/2018.
//

#ifndef DIJKSTRA_WEIGHTEDGRAPHTYPE_H
#define DIJKSTRA_WEIGHTEDGRAPHTYPE_H

#include "graphType.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <list>
#include <cfloat>

using namespace std;



class weightedGraphType : public graphType {
public:
    void createWeightedGraph() {
        ifstream infile;
        string fileName = "words.txt";
        int index;
        int adjacentVertex;
        node data;

        if( gSize != 0 ) {
            clearGraph();
        }

        if( !infile ) {
            cout << "Cannot open the input file";
            return;
        }

        infile >> gSize;

        for( index = 0; index < gSize; ++index ) {
            infile >> data.vertex;
            infile >> data.weight;
            infile >> adjacentVertex;

            while( adjacentVertex != -999 ) {
                graph[data.vertex].push_back( adjacentVertex );
                infile >> adjacentVertex;
            }
        }

        infile.close();
    }

    // Find the shortest path of the given vertex
    void shortestPath( int vertex ) {
        for( int i = 0; i < gSize; ++i ) {
            smallestWeight[i] = weights[vertex][i];
        }

        bool *weightFound = new bool[gSize];

        for( int i = 0; i < gSize; ++i ) {
            weightFound[i] = false;
        }

        weightFound[vertex] = true;
        smallestWeight[vertex] = 0;

        for( int i = 0; i < gSize; ++i ) {
            double minWeight = DBL_MAX;
            int v;

            for( int i = 0; i < gSize; ++i )
                if( !weightFound[i] )
                    if( smallestWeight[i] < minWeight ) {
                        v = i;
                        minWeight = smallestWeight[v];
                    }

            weightFound[v] = true;

            for( int i = 0; i < gSize; ++i )
                if( !weightFound[i] )
                    if( minWeight + weights[v][i] < smallestWeight[i] )
                        smallestWeight[i] = minWeight + weights[v][i];
        }
    }

    // Prints the shortest weight from the vertex
    void printShortestDistance( int vertex ) {
        cout << "Vertex: " << vertex << endl;
        cout << "Shortest distance from the source to each vertex." << endl;
        cout << "Vertex shortest distance" << endl;

        for( int i = 0; i < gSize; ++i )
            cout << setw( 4 ) << i << setw( 12 ) << smallestWeight[i] << endl;

        cout << endl;
    }

    weightedGraphType( int size = 0 ) {
        weights = new double *[size];

        for( int i = 0; i < size; ++i )
            weights[i] = new double[size];

        smallestWeight = new double[size];
    }

    ~weightedGraphType() {
        for( int i = 0; i <gSize; ++i )
            delete [] weights[i];

        delete [] weights;
        delete [] smallestWeight;
    }

protected:
    double **weights;
    double *smallestWeight;
};

#endif //DIJKSTRA_WEIGHTEDGRAPHTYPE_H
