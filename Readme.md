[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jason Pham

## Description
This program implements Prim's algorithm by converting a graph into a 2D array (the adjacency matrix) and using a heap to find the shortest weighted paths from the starting vertex.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Operation  and Time Complexity Analysis

| Insert in MinHeap  - <b>Big O (log n)<b> (where n is the number of elements) because inserting requires us to heapify up to find the correct position for the data. Since the structure of a heap is a binary tree, instead of iterating over every single position, we are cutting the number of positions in half every time. This leads to a time complexity of log n rather than n. 

| Extract Min - <b>Big O (log n)<b> (where n is the number of elements) because removing the root of a heap means we have to replace the root with the last value that was added into the heap and downheapify. This is because of the inherent binary tree structure of a heap. Every time we bubble down, we are cutting the number of potential spots in half.

| Decrease Key - <b>Big O (log n)<b> (where n is the number of elements). This is because after we update the key of a vertex to a smaller value, we have to upheapify again to ensure the structure of the heap is maintained. 

| Prim’s MST Overall 0 <b>Big O (V<sup>2<sup>logV)<b> where V is the number of vertices. This is because building the MSP requires us to check all the neighbors (V) of every vertex (V again). Thus, checking V neighbors of V vertices gets us that V<sup>2<sup> part. But also, when we're checking these neighbors, we are inserting and lowering the keys of certain vertices within the heap, which both cost log(n) time. This makes the final time complexity <b>V<sup>2<sup>logV.

## Test Case Description

Input:  
