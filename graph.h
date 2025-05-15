#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"
using namespace std;

class Graph {
public:

    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices]();
        }
    }

    ~Graph() {
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        int* weightArray = new int[numVertices];
        int* parent = new int[numVertices];
        bool* inMST = new bool[numVertices];
        MinHeap heap(numVertices);

        for (int i = 0; i < numVertices; i++) {
            weightArray[i] = INT_MAX;
            parent[i] = -1;
            inMST[i] = false;
            heap.insert(i, weightArray[i]); 
        }

        heap.decreaseKey(0, 0); 
        weightArray[0] = 0;


        while (!heap.isEmpty()) {
            int vertex = heap.extractMin();
            inMST[vertex] = true;

            for (int i = 0; i < numVertices; i++) {
                int weight = adjMatrix[vertex][i];

                if (weight != 0 && !inMST[i] && weight < weightArray[i]) {
                    parent[i] = vertex;
                    weightArray[i] = weight;
                    heap.decreaseKey(i, weight);  // ✅ use decreaseKey here
                }
            }
        }

        int totalWeight = 0;
        for (int i = 0; i < numVertices; i++) {
            if (parent[i] != -1) {
                cout << "The parent of " << i << " is " << parent[i] << " and the weight is " << weightArray[i] << endl;
                totalWeight += weightArray[i];
            }
        }
        cout << "Final weight is: " << totalWeight;

        delete[] weightArray;
        delete[] parent;
        delete[] inMST;
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif
