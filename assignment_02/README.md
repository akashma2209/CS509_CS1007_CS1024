# CS509 Laboratory - Assignment 02

# Student Details

| Field                | Information       |
| -------------------- | ----------------- |
| Student Name         | Akash Maurya      |
| Entry Number         | 2026CSM1024       |
| Buddy Name           | Aryan Shrivastva |
| Buddy Entry Number   | 2026CSM1007       |
| Programming Language | C++               |

---

## 1. Assignment Overview

This assignment is completed as a **Buddy/Pair Assignment** by two students in a shared repository.

The assignment implements three graph algorithms for unweighted undirected graphs:

1. **Triangle Counting**
   - Counts the number of triangles in an undirected graph.
   - Uses CSR (Compressed Sparse Row) representation.
   - Checks pairs of neighbours to determine whether they are connected.

2. **Betweenness Centrality**
   - Measures how often a vertex lies on shortest paths between other vertices.
   - Uses Brandes' algorithm for unweighted graphs.
   - Performs BFS from every vertex.
   - Reports raw, unnormalized centrality values.

3. **Connected Components**
   - Finds all connected components of an undirected graph.
   - Uses BFS with CSR representation.
   - Assigns every vertex to exactly one component, including isolated vertices.

---

## 2. Language and Environment

The complete repository has been implemented using C++.

## Programming Language

```text
C++
```

## Compiler

```text
GNU g++ Compiler
```

## Operating System

```text
Windows 11
```

---

## 3. Repository Structure

```text
assignment_02/
│
├── driver/
│   ├── driver_triangle_counting.cpp
│   ├── driver_betweenness.cpp
│   └── driver_connected_components.cpp
│
├── src/
│   ├── Triangle_Counting.hpp
│   ├── Triangle_Counting.cpp
│   ├── betweenness.hpp
│   ├── betweenness.cpp
│   ├── connected_component.hpp
│   └── connected_component.cpp
│
├── tests/
│   ├── triangle_counting/
│   ├── bc_test/
│   └── cc_test/
│
├── outputs/
│   ├── triangle_counting/
│   ├── bc_output/
│   └── cc_output/
│
└── executables/
    ├── triangle_counting.exe
    ├── betweenness.exe
    └── connected_components.exe
```

---

## 4. Common CSR Component

A reusable CSR implementation is maintained separately in the repository and can be reused by different assignments.

```text
common/
└── csr/
    │
    ├── README.md
    │
    ├── src/
    │   ├── CSR.hpp
    │   ├── CSR.cpp
    │   ├── driver_csr.hpp
    │   └── driver_csr.cpp
    │
    ├── test_CSR/
    │   ├── csr_test_01.txt
    │   ├── csr_test_02.txt
    │   ├── csr_test_03.txt
    │   └── ...
    │
    └── outputs/
        └── graph/
```

The graph algorithms in this assignment use the common CSR representation.

---

## 5. Directory and File Responsibilities

### 5.1 `src/`

Contains the main algorithm implementations.

#### `Triangle_Counting.hpp`

Stores the declaration of the Triangle Counting algorithm.

#### `Triangle_Counting.cpp`

Implements Triangle Counting using CSR.

#### `betweenness.hpp`

Stores the declaration of Betweenness Centrality.

#### `betweenness.cpp`

Implements Brandes' algorithm using BFS and CSR.

#### `connected_component.hpp`

Stores the declaration of Connected Components.

#### `connected_component.cpp`

Implements Connected Components using BFS and CSR.

---

### 5.2 `driver/`

Contains a dedicated driver for each algorithm.

#### `driver_triangle_counting.cpp`

Used for:

- reading Triangle Counting test files,
- generating CSR files,
- running Triangle Counting,
- measuring algorithm execution time,
- printing detected triangles,
- creating output files.

#### `driver_betweenness.cpp`

Used for:

- reading Betweenness Centrality test files,
- converting the graph to CSR,
- running Brandes' algorithm,
- measuring algorithm execution time,
- writing centrality values to output files.

#### `driver_connected_components.cpp`

Used for:

- reading Connected Components test files,
- converting the graph to CSR,
- running BFS,
- measuring algorithm execution time,
- writing component information to output files.

---

### 5.3 `tests/`

Stores all Assignment 02 test cases.

### 5.4 `outputs/`

Stores the generated output files for each algorithm.

### 5.5 `executables/`

Contains the compiled executables:

```text
triangle_counting.exe
betweenness.exe
connected_components.exe
```

---

## 6. Assignment Objectives

The objectives of this assignment are:

1. Implement Triangle Counting for undirected graphs.
2. Implement Betweenness Centrality using Brandes' algorithm.
3. Implement Connected Components using BFS.
4. Use CSR representation for graph storage.
5. Support isolated vertices in Connected Components.
6. Measure only algorithm execution time.
7. Test the algorithms on the prescribed graph sizes.
8. Generate output files for every test case.

---

## 7. Algorithm Comparison

| Property | Triangle Counting | Betweenness Centrality | Connected Components |
| -------- | ----------------- | ---------------------- | -------------------- |
| Problem | Count triangles | Measure vertex importance | Find connected groups |
| Graph Type | Undirected | Undirected | Undirected |
| Representation | CSR | CSR | CSR |
| Main Technique | Neighbour-pair checking | Brandes + BFS | BFS |
| Time Complexity | Depends on vertex degree and connectivity checking | O(VE) | O(V + E) |
| Output | Number of triangles | Centrality of every vertex | Component of every vertex |

---

## 8. Triangle Counting

Triangle Counting finds a set of three vertices where every pair of vertices is connected by an edge.

The implementation uses the CSR representation of the graph.

### 8.1 Triangle Counting Algorithm

1. Iterate through every vertex `u`.
2. Read the neighbours of `u` from CSR.
3. Select pairs of neighbours `(v, w)`.
4. Check whether `v` and `w` are connected.
5. If they are connected, a triangle has been found.
6. Vertex ordering is used to avoid counting duplicate triangles.
7. Store the detected triangles up to the supported maximum.
8. Report the total number of triangles.
9. Measure the execution time of the triangle-counting operation.

### Complexity

The implementation checks pairs of neighbours and performs a connectivity search through the CSR neighbour list.

The running time depends on the degree of the vertices and the cost of the connectivity check. High-degree vertices require checking more neighbour pairs.

---

## 9. Betweenness Centrality

Betweenness Centrality measures how frequently a vertex lies on shortest paths between other pairs of vertices.

For the unweighted graph, the implementation uses **Brandes' algorithm**.

### 9.1 Betweenness Centrality Algorithm

For every source vertex `s`:

1. Initialize BFS from `s`.
2. Set the distance of `s` to zero.
3. Maintain the number of shortest paths reaching every vertex.
4. Store predecessor vertices for shortest paths.
5. Perform BFS through the CSR graph.
6. Store vertices in BFS order.
7. Process the stored vertices in reverse order.
8. Accumulate dependency values.
9. Add the dependency to the centrality value of every vertex except the source.
10. Repeat the process for every source vertex.
11. Divide the final values by `2` because the graph is undirected.

The implementation reports raw, unnormalized centrality values.

### Complexity

For an unweighted graph, Brandes' algorithm runs in:

```text
O(VE)
```

The implementation stores BFS-related information including distances, shortest-path counts, predecessors, dependencies, and the CSR graph.

---

## 10. Connected Components

A connected component is a maximal set of vertices where a path exists between every pair of vertices in the set.

The implementation uses BFS with the CSR graph.

### 10.1 Connected Components Algorithm

1. Initialize every vertex as unvisited.
2. Scan vertices in order.
3. Skip vertices already assigned to a component.
4. Start a new BFS from every unvisited vertex.
5. Assign a new component ID to the starting vertex.
6. Visit all reachable neighbours using CSR.
7. Assign the same component ID to every reachable vertex.
8. Increment the component ID after the BFS finishes.
9. Continue until all vertices are assigned.
10. Report the number of components and component ID of every vertex.

An isolated vertex is assigned to its own component.

### Complexity

The BFS-based implementation runs in:

```text
O(V + E)
```

The additional working space is:

```text
O(V)
```

apart from the CSR graph storage.

---

## 11. Triangle Counting Result Table

The following table summarizes the measured Triangle Counting results.

| Test File | Vertices (V) | Edges (E) | Total Triangles | Algorithm Time | Status |
| --------- | ------------: | --------: | --------------: | -------------- | ------ |
| `tc_6.txt` | 5 | 8 | 3 | 0.0005 ms | Pass |
| `tc_10.txt` | 10 | 15 | 5 | 0.0011 ms | Pass |
| `tc_100.txt` | 100 | 120 | 33 | 0.0033 ms | Pass |
| `tc_500.txt` | 500 | 600 | 167 | 0.0115 ms | Pass |
| `tc_1000.txt` | 1000 | 1005 | 101 | 0.0576 ms | Pass |
| `tc_10000.txt` | 10000 | 12000 | 1000 | 0.3924 ms | Pass |
| `tc_30000.txt` | 30000 | 32000 | 1002 | 1.1444 ms | Pass |
| `tc_30000.txt` | 30000 | 55000 | 1000 | 1.6885 ms  | Pass |

---

## 12. Betweenness Centrality Result Table

The following table summarizes the measured Betweenness Centrality results.

| Test File | Vertices (V) | Edges (E) | Algorithm Time | Status |
| --------- | ------------: | --------: | -------------- | ------ |
| `bc_5.txt` | [5] | 4 | 0.01 ms | Pass |
| `bc_10.txt` | [10] | 12 | 0.06 ms | Pass |
| `bc_100.txt` | [100] | 120 | 3.14 ms | Pass |
| `bc_10000.txt` | [1000] | 10050 | 25667.31 ms | Pass |
| `bc_50000.txt` | [1000] | 50500 | 722841.31 ms | Pass |

---

## 13. Connected Components Result Table

The following table summarizes the measured Connected Components results.

| Test File | Vertices (V) | Edges (E) | Number of Components | Algorithm Time | Status |
| --------- | ------------: | --------: | -------------------: | -------------- | ------ |
| `cc_8.txt` | [5] | 4 | 4 | 0.004 ms | Pass |
| `cc_10.txt` | [8] | 15 | 1 | 0.004 ms | Pass |
| `cc_100.txt` | [100] | 130 | 22 | 0.017 ms | Pass |
| `cc_10000.txt` | [1000] | 10500 | 1 | 0.754 ms | Pass |
| `cc_50000.txt` | [1000] | 50500 | 1500 | 3.636 ms | Pass |

---

# 14. Observations

### 14.1 Triangle Counting



### 14.2 Betweenness Centrality

- The execution time increased significantly as the graph size increased.
- The increase is much more noticeable for the larger test cases, which is consistent with the higher computational cost of running shortest-path traversal from every vertex.
- The `bc_10000.txt` and `bc_50000.txt` tests show a very large increase in execution time compared with the smaller graphs.
- Overall, the results show that Betweenness Centrality becomes computationally expensive for larger graphs.

### 14.3 Connected Components

- The execution time generally increased with the number of vertices and edges in the graph.
- Smaller graphs completed in a very short amount of time, while the larger graphs required more computation.
- The number of connected components depends on the structure of the graph and therefore does not necessarily increase with graph size.
- Overall, the Connected Components implementation performs efficiently for the tested graph sizes, with execution time remaining relatively small even for the larger test cases.


