#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

class Graph
{
private:
    int numVertices;       // This is the number of vertices in the graph
    int **adjacencyMatrix; // This is the adjacency matrix representing the graph

public:
    Graph(int numVertices);                          // This is the constructor to initialize the Graph object
    ~Graph();                                        // This is the destructor to deallocate memory used by the Graph object
    void addEdge(int fromVertex, int toVertex);      // This is the function to add an edge between two vertices
    void printAdjacencyMatrix();                     // This is the function to print the adjacency matrix of the graph
    void dijkstraShortestPaths(int source);          // This is the function to find the shortest paths from a source vertex
    int getEdge(int fromVertex, int toVertex) const; // This is the function to get the weight of the edge between two vertices
};

#endif
