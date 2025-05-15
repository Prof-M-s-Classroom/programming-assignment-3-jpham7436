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
  /*      int* key = new int[numVertices];      // Holds min edge weights
        int* parent = new int[numVertices];   // Stores MST edges
        bool* inMST = new bool[numVertices];  // Track vertices added to MST

        MinHeap heap(numVertices);

        for (int v = 0; v < numVertices; ++v) {
            key[v] = INT_MAX;
            parent[v] = -1;
            inMST[v] = false;
            heap.insert(v, key[v]);
        }

        // Start with vertex 0
        key[0] = 0;
        heap.decreaseKey(0, 0);

        while (!heap.isEmpty()) {
            int u = heap.extractMin();
            inMST[u] = true;

            // Check all neighbors
            for (int v = 0; v < numVertices; ++v) {
                int weight = adjMatrix[u][v];
                if (weight != 0 && !inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    heap.decreaseKey(v, weight);
                }
            }
        }

        // Print MST
        int totalWeight = 0;
        std::cout << "Edge   Weight\n";
        for (int i = 1; i < numVertices; ++i) {
            std::cout << parent[i] << " - " << i << "    " << adjMatrix[i][parent[i]] << "\n";
            totalWeight += adjMatrix[i][parent[i]];
        }
        std::cout << "Total weight of MST: " << totalWeight << "\n";

        delete[] key;
        delete[] parent;
        delete[] inMST; */
        int* weightArray = new int[numVertices];
        int* parent = new int[numVertices];
        bool* inMST = new bool[numVertices];
        MinHeap heap(numVertices);

        for (int i = 0; i < numVertices; i++) {
            weightArray[i] = INT_MAX;
            parent[i] = -1;
            inMST[i] = false;
        }

        // Start with vertex 0
        heap.insert(0, 0);
        weightArray[0] = 0;
        parent[0] = -1;

        while (!heap.isEmpty()) {
            int vertex = heap.extractMin();
            inMST[vertex] = true;

            for (int i = 0; i < numVertices; i++) {
                int weight = adjMatrix[vertex][i];

                if (weight != 0 && !inMST[i] && weight < weightArray[i]) {
                    heap.insert(i, weight);
                    parent[i] = vertex;
                    weightArray[i] = weight;
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

    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif
