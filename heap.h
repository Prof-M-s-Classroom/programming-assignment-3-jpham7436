#ifndef HEAP_H
#define HEAP_H
using namespace std;

class MinHeap {
public:
    MinHeap(int capacity) {
        this -> capacity = capacity;
        heapArray = new int[capacity];
        keyArray = new int[capacity]();
        position = new int[capacity];
        size = 0;
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        if (size == capacity) {
            cout << "Overflow!!";
            return;
        }

        heapArray[size] = vertex;
        keyArray[vertex] = key;
        position[vertex] = size;
        upHeapify(size);
        size++;
    }

    int extractMin() {
        if ( isEmpty() )
            return -1;

        int minVertex = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        downHeapify(0);
        size--;
        return minVertex;
    }

    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex];
        keyArray[vertex] = newKey;
        upHeapify(i);
    }

    bool isInMinHeap(int vertex);

    bool isEmpty() {
        if (size == 0)
            return true;
        return false;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void swapPositions(int x, int y) {
        int vx = heapArray[x];
        int vy = heapArray[y];

        heapArray[x] = vy;
        heapArray[y] = vx;

        position[vx] = y;
        position[vy] = x;
    }

    void upHeapify(int idx) {
        int i = idx;
        while (i > 0 && keyArray[ heapArray[(i - 1) / 2] ] > keyArray[heapArray[i]]) {
            swapPositions(i, (i - 1) / 2);
            i = (i -1)/2;
        }
    }

    void downHeapify(int idx) {
        int smallestIndex = idx;
        int leftIndex = 2 * idx + 1;
        int rightIndex = 2 * idx + 2;

        if (leftIndex < size && keyArray[heapArray[leftIndex]] < keyArray[heapArray[smallestIndex]])
            smallestIndex = leftIndex;

        if (rightIndex < size && keyArray[heapArray[rightIndex]] < keyArray[heapArray[smallestIndex]])
            smallestIndex = rightIndex;

        if (smallestIndex != idx) {
            swapPositions(idx, smallestIndex);
            downHeapify(smallestIndex);
        }
    }
};

#endif
