# CS509 - PG Software Lab

Repository for CS509 (PG Software Lab) — Graph Algorithms. This repository implements and analyzes graph algorithms in C++ using the CSR (Compressed Sparse Row) representation as the common storage backbone across assignments.

Each assignment lives in its own folder with a dedicated README covering full algorithm details, test tables, and observations. This top-level README gives a quick overview of the whole repository so a visitor can understand what's inside without digging through every folder.

---

## Student / Pair Details

| Field | Details |
|-------|---------|
| Assignment Type | Buddy Assignment |
| Student 1 Name | Akash Maurya |
| Entry Number | 2026CSM1024 |
| Student 2 Name | Aryan Shrivastva |
| Entry Number | 2026CSM1007 |


---

## Language and Environment

| Item | Details |
|------|---------|
| Programming Language | C++ |
| Language Standard | C++17 |
| Compiler | GNU g++ |
| Build Tool | Makefile |
| Operating System | Windows 11 |

---

## Repository Structure

```
CS509_CS1007_CS1024
│
├── README.md                  
├── Makefile
│
├── wrapper/                   
│   ├── wrapper.cpp
│   └── wrapper.exe
│
├── common/                    
│   └── csr/                   
│
├── assignment_01/              
│   ├── README.md
│   ├── driver/
│   ├── src/
│   ├── tests/
│   ├── outputs/
│   └── executables/
│
├── assignment_02/              
│   ├── README.md
│   ├── driver/
│   ├── src/
│   ├── tests/
│   ├── outputs/
│   └── executables/
│
└── assignment_03/              
    ├── README.md
    ├── driver/
    ├── src/
    ├── tests/
    ├── outputs/
    └── executables/
```

Every assignment folder follows the same convention:
- `src/` – algorithm implementations
- `driver/` – programs that read test input, generate the CSR representation (where applicable), run the algorithm, time it, and write output
- `tests/` – input test cases
- `outputs/` – results and execution times
- `executables/` – compiled binaries
- `README.md` – full write-up: algorithm details, test tables, and observations

---


## Assignments Overview

### Assignment 01 – Graph Traversal & Shortest Path using CSR

Implements the foundational graph algorithms on top of the CSR representation:

- **CSR Graph Conversion** – converts an adjacency list into `row_ptr`, `col_idx`, and `values` arrays.
- **Breadth First Search (BFS)** – level-by-level traversal from a source vertex; used for unweighted shortest paths and level exploration.
- **Depth First Search (DFS)** – explores as deep as possible along each path before backtracking; used for connectivity and cycle-related analysis.
- **Single Source Shortest Path (SSSP)** – Dijkstra's algorithm on a weighted CSR graph, computing shortest distances from one source to all other vertices.

Full details, algorithm walk-throughs, and test result tables: [`assignment_01/README.md`](./assignment_01/README.md)

### Assignment 02 – Structural Graph Algorithms using CSR

Implements three algorithms for unweighted, undirected graphs, all built on the common CSR representation:

- **Triangle Counting** – counts triangles in the graph by checking connectivity between pairs of a vertex's neighbours.
- **Betweenness Centrality** – measures how often each vertex lies on shortest paths between other vertex pairs, using Brandes' algorithm (BFS from every vertex); reports raw, unnormalized values. Runs in O(VE).
- **Connected Components** – finds all connected components via BFS, assigning every vertex (including isolated ones) to a component. Runs in O(V + E).

Full details, algorithm walk-throughs, and test result tables: [`assignment_02/README.md`](./assignment_02/README.md)

### Assignment 03 – Numerical Optimization and Network Flow

Implements two algorithms with very different input types — one purely numerical, one graph-based on top of the common CSR representation:

- **Gradient Descent** – an iterative optimization method that finds a minimum of a polynomial function by repeatedly moving `x` opposite to the function's derivative, scaled by a learning rate; stops on convergence (derivative below tolerance) or on hitting the maximum iteration count. Does not use CSR, since its input is a mathematical function rather than a graph.
- **Maxflow-Mincut** – computes the maximum flow from a source to a sink on a directed, positive-integer-capacity graph using Dinic's algorithm (BFS level graphs + blocking-flow DFS), then derives the minimum cut from the final residual graph; verifies correctness via the max-flow min-cut theorem (`maxFlow == cutCapacity`). Uses the common CSR component to store the input graph.

Full details, algorithm walk-throughs, and test result tables: [`assignment_03/README.md`](./assignment_03/README.md)

---

## How Results Are Measured

Across all three assignments, only algorithm execution time is measured — CSR preprocessing, I/O, and memory allocation are excluded from timing. Each algorithm is tested on a range of input sizes, from very small (a handful of vertices, or a low-degree polynomial) to large (tens or hundreds of thousands of vertices/edges, or high iteration counts), to observe how execution time scales with input size — matching the theoretical time complexity of each algorithm.
