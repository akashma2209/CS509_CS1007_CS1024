# CS509 Laboratory Repository

---

# Repository Overview

# Objective

The objective of this assignment is to understand and implement efficient graph algorithms for large sparse graphs.

The main objectives are:

- Understanding different graph storage representations.
- Converting adjacency list representation into CSR format.
- Implementing graph traversal algorithms using CSR.
- Implementing shortest path computation using weighted CSR graphs.
- Measuring algorithm execution time independently from preprocessing operations.
- Analyzing the computational complexity of graph algorithms.

The implemented algorithms are:

1. CSR Graph Conversion
2. Breadth First Search (BFS)
3. Depth First Search (DFS)
4. Single Source Shortest Path (SSSP) using Dijkstra's Algorithm

---

# Student / Pair Details

| Field | Details |
|------|---------|
| Assignment Type | Buddy Assignment |
| Student 1 Name | Akash Maurya |
| Entry Number | CS1024 |
| Student 2 Name | Aryan Shrivastva |
| Entry Number | 2026CSM1024 |
| Programming Language | C++ |

---


## Development Environment

| Component | Specification |
|-----------|---------------|
| Programming Language | C++ |
| Compiler | GNU g++ |
| Language Standard | C++17 |
| Build Tool | Makefile |
| Runtime Measurement | std::chrono |
| Operating System | Windows |

---


# Repository Structure

The repository follows a structured organization where source code, drivers, test cases, outputs, and executable files are maintained separately.

The structure is:

```
CS509_CS1024
│
├── README.md
│
├── Makefile
│
├── wrapper
│   │
│   ├── wrapper.cpp
│   └── wrapper.exe
│
├── assignment_01
│   │
│   ├── driver
│   │
│   ├── src
│   │
│   ├── tests
│   │
│   ├── outputs
│   │
│   └── executables
│
└── ...
```

---
# Assignment 01 - Graph Algorithms using CSR Representation

---


# Algorithm / Approach

## 1. Graph Representation using CSR

## Overview

A graph can be represented using different data structures such as:

- Adjacency Matrix
- Adjacency List
- Compressed Sparse Row (CSR)

For sparse graphs, adjacency matrices are inefficient because they require memory proportional to the square of the number of vertices.

For a graph containing `V` vertices, an adjacency matrix requires:

```
V × V
```

memory locations even when most connections do not exist.

CSR representation provides a more efficient approach by storing only existing edges.

The graph is initially provided in adjacency list format and is converted into CSR before applying graph algorithms.

---

# CSR Representation

CSR stores graph information using three arrays:

1. Row Pointer Array (`row_ptr`)
2. Column Index Array (`col_idx`)
3. Values Array (`values`)

---

# Row Pointer Array (row_ptr)

The row pointer array identifies the starting and ending locations of neighbours of every vertex.

For a vertex `u`:

```
row_ptr[u]
```

contains the starting index of its neighbour list.

The next value:

```
row_ptr[u+1]
```

contains the ending index.

Therefore, all neighbours of vertex `u` are stored in:

```
row_ptr[u]  to  row_ptr[u+1]-1
```

This allows direct access to the neighbour list of any vertex.

---

# Column Index Array (col_idx)

The column index array stores destination vertices of all edges.

Instead of maintaining separate neighbour lists, all neighbouring vertices are stored continuously.

For example:

```
col_idx = [1,2,3,4,5]
```

represents the destination vertices of stored edges.

---

# Values Array (values)

For weighted graphs, the values array stores edge weights corresponding to the vertices stored in `col_idx`.

Example:

```
col_idx = [2,4,5]

values  = [10,5,7]
```

means:

```
Edge to vertex 2 has weight 10

Edge to vertex 4 has weight 5

Edge to vertex 5 has weight 7
```

For unweighted traversal algorithms such as BFS and DFS, edge weights are not required.

---

# CSR Conversion Algorithm

The adjacency list is converted into CSR using the following approach:

---


# 2. Breadth First Search (BFS)

## Algorithm Overview

Breadth First Search is a graph traversal algorithm that explores vertices level by level.

It starts from a given source vertex and visits all neighbouring vertices before moving to the next level.

BFS is commonly used for:

- Finding shortest path in an unweighted graph.
- Finding connected components.
- Level-based graph exploration.

---

# BFS Working Principle

The BFS algorithm follows:

1. Select a starting source vertex.
2. Mark the source vertex as visited.
3. Insert the source vertex into a queue.
4. Remove a vertex from the front of the queue.
5. Explore all unvisited neighbours.
6. Mark newly discovered vertices as visited.
7. Insert them into the queue.
8. Continue until the queue becomes empty.

The algorithm maintains the distance of each vertex from the source.

The distance represents the minimum number of edges required to reach that vertex.

---


# 3. Depth First Search (DFS)

## Algorithm Overview

Depth First Search is a graph traversal algorithm that explores the graph by moving as deep as possible along a path before returning back.

DFS is useful for:

- Graph connectivity analysis.
- Cycle detection.
- Graph searching.
- Recursive graph exploration.

---

# DFS Working Principle

The DFS algorithm performs:

1. Start from the source vertex.
2. Mark the vertex as visited.
3. Visit an unvisited neighbour.
4. Continue recursively.
5. Backtrack when no unvisited neighbour exists.
6. Continue until all reachable vertices are explored.

---


# 4. Single Source Shortest Path (SSSP)

## Algorithm Overview

Single Source Shortest Path determines the minimum distance from one source vertex to every other vertex in a weighted graph.

This implementation uses:

```
Dijkstra's Algorithm
```

with CSR graph representation.

---

# Dijkstra Algorithm Working Principle

Dijkstra's algorithm maintains:

## Distance Array

Stores the currently known shortest distance from the source.

Initial condition:

```
source distance = 0

other vertices = infinity
```

---



---



# Test Cases and Result Tables



# SSSP Result Table

| Test File | Input Type | Input Size (V,E) | Source Vertex | Expected Output | Actual Output | Algorithm Time | Status |
|-----------|------------|------------------|---------------|-----------------|---------------|----------------|--------|
| sssp_test_01.txt | Weighted CSR Graph | V = 5 , E = 6 | 0 | Shortest distances | Shortest distances | 0.0014 ms | Pass |
| sssp_test_02.txt | Weighted CSR Graph | V = 6 , E = 8 | 0 | Shortest distances | Shortest distances | 0.0018 ms | Pass |
| sssp_test_03.txt | Weighted CSR Graph | V = 5 , E = 100 | 0 | Shortest distances | Shortest distances | 0.002 ms | Pass |
| sssp_test_03.txt | Weighted CSR Graph | V 100 , E = 500 | 0 | Shortest distances | Shortest distances | 0.056 ms | Pass |
| sssp_test_05.txt | Weighted CSR Graph | V = 1000 , E = 3000 | 0 | Shortest distances | Shortest distances | 2.909 ms | Pass |

---

# Complexity Analysis

\
