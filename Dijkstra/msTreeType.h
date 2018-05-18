//
// Created by steph on 5/17/2018.
//

#ifndef DIJKSTRA_MSTREETYPE_H
#define DIJKSTRA_MSTREETYPE_H

#include <cfloat>
#include "graphType.h"

class msTreeType: public graphType {
public:
    void createSpanningGraph() {

    }

    void minimalSpanningTree( int sVertex ) {
        int start, end;
        double minWeight;

        source = sVertex;

        bool *mstv = new bool[gSize];

        for( int i = 0; i < gSize; ++i ) {
            mstv[i] = false;
            edges[i] = source;
            edgeWeights[i] = weights[source][i];
        }

        mstv[source] = true;
        edgeWeights[source] = 0;

        for( int i = 0; i < gSize; ++i ) {
            minWeight = DBL_MAX;

            for( int j = 0; i < gSize; ++j )
                if( mstv[i] )
                    for( int k = 0; k < gSize; ++k )
                        if( !mstv[k] && weights[j][k] < minWeight ) {
                            end = k;
                            start = j;
                            minWeight = weights[j][k];
                        }

            mstv[end] = true;
            edges[end] = true;
            edgeWeights[end] = start;
        }
    }

    void printTreeAndWeight() {
        double weight = 0;

        cout << "Source Vertex: " << source << endl;
        cout << "Edges\tWeight" << endl;

        for( int i = 0; i < gSize; ++i ) {
            if( edges[i] != i ) {
                weight = weight + edgeWeights[i];
                cout << "(" << edges[i] << ", " << i << ")\t" << edgeWeights[i] << endl;
            }
        }

        cout << endl;
        cout << "Minimal Spanning Tree Weight: " << weight << endl;
    }

    msTreeType( int size = 0 ) {
        weights = new double*[size];
        for( int i = 0; i < gSize; ++i ) {
            weights[i] = new double[size];
        }

        edges = new int[size];
        edgeWeights = new double[size];
    }

    ~msTreeType() {
        for( int i = 0; i < gSize; ++i ) {
            delete [] weights[i];
        }

        delete [] weights;
        delete [] edges;
        delete [] edgeWeights;
    }

protected:
    int source;
    double **weights;
    int *edges;
    double *edgeWeights;
};

#endif //DIJKSTRA_MSTREETYPE_H
