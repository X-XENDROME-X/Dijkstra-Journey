#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    // The below line checks if an input file is provided as an argument
    if (argc == 2)
    {
        cout << "Error: Please provide input through redirection (<), not as an argument." << endl;
        return 1;
    }
    else if (argc > 2)
    {
        // The below line prints usage instructions if too many arguments are provided
        cout << "Usage: " << argv[0] << " < input_file" << endl;
        return 1;
    }

    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    Graph graph(numVertices);

    // Read edges from input file and add them to the graph
    while (numEdges--)
    {
        int startVertex, endVertex;
        if (!(cin >> startVertex) || !(cin >> endVertex))
        {
            // The below line prints an error message if invalid input format is detected
            cout << "Error: Invalid input format." << endl;
            return 1;
        }
        graph.addEdge(startVertex - 1, endVertex - 1);
    }

    // Print adjacency matrix
    graph.printAdjacencyMatrix();

    // Find odd-degree vertices and print them
    cout << "\nThe odd degree vertices in G:" << endl;
    cout << "O = { ";
    for (int i = 0; i < numVertices; ++i)
    {
        int degree = 0;
        for (int j = 0; j < numVertices; ++j)
        {
            if (graph.getEdge(i, j) == 1)
                ++degree;
        }
        if (degree % 2 != 0)
            cout << i + 1 << " ";
    }
    cout << "}\n"
         << endl;

    // Perform Dijkstra's algorithm for each odd-degree vertex
    for (int i = 0; i < numVertices; ++i)
    {
        int degree = 0;
        for (int j = 0; j < numVertices; ++j)
        {
            if (graph.getEdge(i, j) == 1)
                ++degree;
        }
        if (degree % 2 != 0)
            graph.dijkstraShortestPaths(i);
    }

    return 0;
}
