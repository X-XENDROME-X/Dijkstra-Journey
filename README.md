# Dijkstra Journey

This project implements the single-source Dijkstra's shortest path algorithm using object-oriented programming and modular design in C++. The program reads an input file representing an undirected graph, processes the graph to identify vertices with odd degrees, and calculates the shortest path lengths from each odd-degree vertex to all other vertices.

## Table of Contents
- [Overview](#overview)
- [Input Format](#input-format)
- [Output Format](#output-format)
- [Building and Testing](#building-and-testing)
- [Sample Usage](#sample-usage)
- [Dependencies](#dependencies)
- [License](#license)

## Overview
The program reads a connected undirected graph `G = (V, E)` from a text file specified as a command line parameter. It performs the following tasks:
1. Displays the adjacency matrix of the graph.
2. Lists the vertices with odd degrees.
3. Executes Dijkstra's algorithm from each odd-degree vertex and displays the shortest path lengths to all other vertices.

## Input Format
The input graph is provided in a text file with the following format:
1. The first line contains two positive integers `n` and `m`, where `n` is the number of vertices and `m` is the number of edges.
2. Each of the next `m` lines contains two integers `u` and `v`, representing an edge between vertices `u` and `v`.

## Output Format
The program produces three outputs:
1. The adjacency matrix of the graph.
2. A list of vertices with odd degrees.
3. The shortest path lengths from each odd-degree vertex to all other vertices.

## Building and Testing
To build and test the program, follow these steps:

1. Ensure you have a `Makefile` in your project directory with the appropriate build instructions.
2. Build the program by running:
    ```sh
    make
    ```

3. Run the executable with the sample test case file:
    ```sh
    ./dijkstra < sampletextcase.txt
    ```

## Sample Usage
Assuming you have a graph file named `sampletextcase.txt`, you can run the program as follows:

```sh
./dijkstra < sampletextcase.txt
```

## Dependencies

1. A C++ compiler (e.g., g++)
2. Standard C++ libraries
3. Make utility

## License

This project is licensed under the [MIT License](LICENSE).


