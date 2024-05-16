#include "Graph.h"
#include <iostream>

const int MAX_INT = 2147483647;

// Constructor to initialize the Graph object with the given number of vertices
Graph::Graph(int numVertices)
{
    // The below line initializes the number of vertices
    this->numVertices = numVertices;

    // Allocate memory for the adjacency matrix
    adjacencyMatrix = new int *[numVertices];
    for (int i = 0; i < numVertices; ++i)
    {
        adjacencyMatrix[i] = new int[numVertices];
        // Initialize the adjacency matrix with zeros
        for (int j = 0; j < numVertices; ++j)
        {
            // The below line initializes the adjacency matrix entry to 0
            adjacencyMatrix[i][j] = 0;
        }
    }
}

// Destructor to deallocate memory used by the Graph object
Graph::~Graph()
{
    // Deallocate memory for each row of the adjacency matrix
    for (int i = 0; i < numVertices; ++i)
    {
        delete[] adjacencyMatrix[i];
    }
    // Deallocate memory for the adjacency matrix itself
    delete[] adjacencyMatrix;
}

// Function to add an edge between two vertices
void Graph::addEdge(int fromVertex, int toVertex)
{
    // Set the adjacency matrix entries corresponding to the edge to 1 (assuming an undirected graph)
    adjacencyMatrix[fromVertex][toVertex] = 1;
    adjacencyMatrix[toVertex][fromVertex] = 1;
}

// Function to print the adjacency matrix of the graph
void Graph::printAdjacencyMatrix()
{
    std::cout << "The adjacency matrix of G:" << std::endl;
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            // Print each entry of the adjacency matrix
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to get the weight of the edge between two vertices
int Graph::getEdge(int fromVertex, int toVertex) const
{
    // Return the value of the corresponding entry in the adjacency matrix
    return adjacencyMatrix[fromVertex][toVertex];
}

// Function to find the shortest paths from a source vertex using Dijkstra's algorithm
void Graph::dijkstraShortestPaths(int source)
{
    // Array to store the shortest distance from the source to each vertex
    int *distance = new int[numVertices];
    // Array to track if each vertex is included in the shortest path tree
    bool *visited = new bool[numVertices];

    // Initialize all distances as infinite and all vertices as not visited
    for (int i = 0; i < numVertices; ++i)
    {
        // The below line initializes the distance to each vertex as maximum integer value
        distance[i] = MAX_INT;
        // The below line initializes the visited status of each vertex as false
        visited[i] = false;
    }

    // Distance from source vertex to itself is 0
    distance[source] = 0;

    // Find shortest paths for all vertices
    for (int count = 0; count < numVertices - 1; ++count)
    {
        // Find the vertex with the minimum distance from the source among the vertices not yet processed
        int minDistance = MAX_INT;
        int minIndex = -1;
        for (int v = 0; v < numVertices; ++v)
        {
            if (!visited[v] && distance[v] <= minDistance)
            {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        // Mark the picked vertex as visited
        visited[minIndex] = true;

        // Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; ++v)
        {
            if (!visited[v] && adjacencyMatrix[minIndex][v] &&
                distance[minIndex] != MAX_INT &&
                distance[minIndex] + adjacencyMatrix[minIndex][v] < distance[v])
            {
                distance[v] = distance[minIndex] + adjacencyMatrix[minIndex][v];
            }
        }
    }

    // Print the shortest path lengths from the source vertex
    std::cout << "Single source shortest path lengths from node " << source + 1 << std::endl;
    for (int i = 0; i < numVertices; ++i)
    {
        std::cout << "  " << i + 1 << ": ";
        if (distance[i] == MAX_INT)
        {
            // Print "INF" for vertices not reachable from the source
            std::cout << "INF" << std::endl;
        }
        else
        {
            // Print the shortest distance for reachable vertices
            std::cout << distance[i] << std::endl;
        }
    }

    // Clean up allocated memory
    delete[] distance;
    delete[] visited;
}
