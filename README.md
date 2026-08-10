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
| Programming Language | C++ |

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
├── README.md                  <- you are here
├── Makefile
│
├── wrapper/                   <- single entry point to run any assignment
│   ├── wrapper.cpp
│   └── wrapper.exe
│
├── common/                    <- reusable code shared across assignments
│   └── csr/                   <- standalone CSR (Compressed Sparse Row) implementation
│
├── assignment_01/              <- Graph traversal & shortest path using CSR
│   ├── README.md
│   ├── driver/
│   ├── src/
│   ├── tests/
│   ├── outputs/
│   └── executables/
│
└── assignment_02/              <- Structural graph algorithms using CSR
    ├── README.md
    ├── driver/
    ├── src/
    ├── tests/
    ├── outputs/
    └── executables/
```

Every assignment folder follows the same convention:
- `src/` – algorithm implementations
- `driver/` – programs that read test input, generate the CSR representation, run the algorithm, time it, and write output
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

---

## How Results Are Measured

Across both assignments, only algorithm execution time is measured — CSR preprocessing, I/O, and memory allocation are excluded from timing. Each algorithm is tested on a range of input sizes, from very small (a handful of vertices) to large (tens of thousands of vertices/edges), to observe how execution time scales with graph size — matching the theoretical time complexity of each algorithm.
