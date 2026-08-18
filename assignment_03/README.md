# CS509 Laboratory - Assignment 03

## Student Details

| Field                 | Information       |
| --------------------- | ------------------ |
| Student Name          | Akash Maurya       |
| Entry Number          | 2026CSM1024        |
| Buddy Name            | Aryan Shrivastva    |
| Buddy Entry Number    | 2026CSM1007         |
| Programming Language  | C++                 |

---

## 1. Assignment Overview

This assignment is completed as a **Buddy/Pair Assignment** by two students in a shared repository.

The assignment implements two algorithms:

### Gradient Descent

- An iterative optimization algorithm used to find a minimum of a mathematical function.
- Uses the derivative of the function to determine the direction of movement.
- Updates the current value of `x` using a learning rate.
- Stops when the magnitude of the derivative becomes smaller than the given tolerance or when the maximum number of iterations is reached.

### Maxflow-Mincut

- Computes the maximum amount of flow that can be sent from a source vertex to a sink vertex.
- Uses directed edges with positive integer capacities.
- The implementation uses **Dinic's Maximum Flow algorithm**.
- After computing maximum flow, the minimum cut is obtained from the final residual graph.
- The source side contains vertices reachable from the source in the residual graph.
- The sink side contains the remaining vertices.
- The maximum-flow value must be equal to the minimum-cut capacity.

---

## 2. Language and Environment

The complete repository has been implemented using C++.

```text
Programming Language : C++
Compiler              : GNU g++ Compiler
Operating System      : Windows 11
Build Tool             : Makefile
```

---

## 3. Repository Structure

The Assignment 03 directory follows the required CS509 laboratory organization.

```text
assignment_03/
│
├── driver/
│   ├── driver_gradient_descent.cpp
│   └── driver_maxflow_mincut.cpp
│
├── src/
│   ├── gradient_descent.hpp
│   ├── gradient_descent.cpp
│   ├── Maxflow_Mincut.hpp
│   └── Maxflow_Mincut.cpp
│
├── tests/
│   ├── gradient_descent/
│   │   ├── gd_01.txt
│   │   ├── gd_02.txt
│   │   ├── gd_03.txt
│   │   └── ...
│   │
│   └── maxflow_mincut/
│       ├── mf_01.txt
│       ├── mf_02.txt
│       ├── mf_03.txt
│       └── ...
│
├── outputs/
│   ├── gradient_descent/
│   │   ├── gd_01_output.txt
│   │   ├── gd_02_output.txt
│   │   └── ...
│   │
│   └── maxflow_mincut/
│       ├── mf_01.txt
│       ├── mf_02.txt
│       └── ...
│
├── executables/
│   ├── gradient_descent.exe
│   └── maxflow_mincut.exe
│
└── README.md
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

The Maxflow-Mincut implementation uses the common CSR component to store the input directed capacity graph.

The Gradient Descent implementation does not require CSR because its input is a mathematical function rather than a graph.

---

## 5. Directory and File Responsibilities

### 5.1 `src/`

Contains the main algorithm implementations.

#### `gradient_descent.hpp`

Stores the declarations of the Gradient Descent functions.

#### `gradient_descent.cpp`

Implements:

- Function evaluation.
- Derivative calculation.
- Gradient Descent iterations.
- Convergence checking.
- Final `x` and function value calculation.

#### `Maxflow_Mincut.hpp`

Stores the declarations and structures required by the Maxflow-Mincut implementation.

#### `Maxflow_Mincut.cpp`

Implements:

- Residual graph construction.
- Dinic's BFS level graph.
- DFS-based flow augmentation.
- Maximum-flow calculation.
- Residual graph traversal.
- Minimum-cut partition.
- Minimum-cut edge identification.

---

### 5.2 `driver/`

Contains a dedicated driver for each algorithm.

#### `driver_gradient_descent.cpp`

Used for:

- locating Gradient Descent test files,
- reading function coefficients,
- reading the initial `x` value,
- reading the learning rate,
- reading the tolerance,
- reading the maximum number of iterations,
- calling Gradient Descent,
- measuring algorithm execution time,
- writing results to output files.

#### `driver_maxflow_mincut.cpp`

Used for:

- locating Maxflow-Mincut test files,
- generating CSR representations,
- reading source and sink vertices,
- reading the CSR graph,
- calling Maxflow-Mincut,
- measuring algorithm execution time,
- printing the maximum-flow value,
- printing the minimum-cut capacity,
- printing the two sides of the cut,
- printing cut edges,
- creating output files.

---

### 5.3 `tests/`

Stores all Assignment 03 test cases.

The test cases are divided into:

```text
tests/
├── gradient_descent/
└── maxflow_mincut/
```

---

### 5.4 `outputs/`

Stores the generated output files.

```text
outputs/
├── gradient_descent/
└── maxflow_mincut/
```

---

### 5.5 `executables/`

Contains the compiled Assignment 03 executables.

```text
gradient_descent.exe
maxflow_mincut.exe
```

---

## 6. Assignment Objectives

The objectives of this assignment are:

1. Implement Gradient Descent for numerical optimization.
2. Calculate the value of a polynomial function.
3. Calculate the derivative of the polynomial function.
4. Perform iterative Gradient Descent updates.
5. Detect convergence using the specified tolerance.
6. Implement the Maxflow-Mincut problem.
7. Use Dinic's algorithm for maximum flow.
8. Use a residual graph internally during the flow computation.
9. Obtain the minimum cut from the final residual graph.
10. Ensure that maximum-flow value equals minimum-cut capacity.
11. Use CSR representation for the Maxflow-Mincut input graph.
12. Measure only algorithm execution time.
13. Test the algorithms on the prescribed test cases.
14. Generate separate output files for every test case.

---

## 7. Algorithm Comparison

| Property             | Gradient Descent                     | Maxflow-Mincut                     |
| --------------------- | ------------------------------------- | ------------------------------------ |
| Problem               | Numerical optimization                | Maximum flow and minimum cut         |
| Input                 | Polynomial coefficients and parameters | Directed capacity graph             |
| Main Technique        | Iterative gradient update              | Dinic's algorithm                    |
| Graph Required        | No                                     | Yes                                  |
| CSR Used              | No                                     | Yes                                  |
| Main Operation        | Derivative-based update                | BFS + DFS on residual graph          |
| Output                | Minimum/final `x` and `f(x)`          | Maximum flow and minimum cut         |
| Stopping Condition    | Tolerance / max iterations             | No augmenting path remains           |
| Main Working Space    | O(1) apart from input                  | O(V + E) approximately               |
| Execution             | Iterative numerical method             | Network-flow algorithm               |

---

## 8. Gradient Descent

Gradient Descent is an iterative optimization method used to find a minimum of a function.

For a function `f(x)`, the derivative `f'(x)` determines the direction in which the function changes.

The implementation updates `x` using:

```text
x = x - learningRate × derivative
```

A positive derivative causes `x` to move in the negative direction, while a negative derivative causes `x` to move in the positive direction.

### 8.1 Gradient Descent Algorithm

For every test case:

1. Read the polynomial degree.
2. Read the polynomial coefficients.
3. Read the initial value of `x`.
4. Read the learning rate.
5. Read the convergence tolerance.
6. Read the maximum number of iterations.
7. Calculate the derivative at the current `x`.
8. Check whether the absolute derivative is smaller than or equal to the tolerance.
9. If the condition is satisfied, mark the algorithm as converged.
10. Otherwise, update `x` using the Gradient Descent formula.
11. Increment the iteration count.
12. Repeat until convergence or the maximum number of iterations is reached.
13. Calculate the final function value.
14. Report the final `x`, final `f(x)`, number of iterations, convergence status, and execution time.


## 9. Maxflow-Mincut

The Maxflow-Mincut problem determines the maximum amount of flow that can be sent from a source vertex `s` to a sink vertex `t` without exceeding the capacity of any directed edge.

The corresponding minimum cut divides the vertices into two sets:

- Source side
- Sink side

such that the source belongs to the source side and the sink belongs to the sink side.

The implementation uses Dinic's Maximum Flow algorithm.

### 9.1 Dinic Algorithm Steps

1. Convert the CSR graph into a residual graph.
2. Add every original directed edge with its capacity.
3. Add a reverse residual edge with initial capacity zero.
4. Run BFS from the source.
5. Construct the level graph.
6. If the sink is unreachable, maximum flow has been obtained.
7. Initialize the current-edge array.
8. Use DFS to send flow through the level graph.
9. Update forward and reverse residual capacities.
10. Repeat DFS until no more flow can be sent.
11. Construct another level graph using BFS.
12. Repeat until the sink becomes unreachable.
13. The accumulated flow is the maximum-flow value.

---

## 10. Minimum Cut

After the maximum flow has been calculated, the final residual graph is used to determine the minimum cut.

A BFS/graph traversal starts from the source and follows only edges with:

```text
capacity > 0
```

All reachable vertices form the source side.

All unreachable vertices form the sink side.

### 10.1 Minimum Cut Edges

An original edge is a cut edge when:

```text
u is in the source side
```

and

```text
v is in the sink side
```

The capacity of every such original edge is added to obtain the minimum-cut capacity.

The implementation therefore reports:

- Source side
- Sink side
- Cut edges
- Minimum cut capacity

### 10.2 Max-Flow Min-Cut Theorem

For every valid flow network:

```text
Maximum Flow = Minimum Cut Capacity
```

Therefore, the implementation verifies the correctness of the result by ensuring that:

```text
maxFlow == cutCapacity
```

For the example graph, the expected result is:

```text
Maximum flow: 23
Minimum cut capacity: 23
```

---


## 11. Gradient Descent Result Table

The following table can be filled with the measured results obtained from the test cases.

| Test File     | Degree | Initial x | Learning Rate  | Iterations | Final x | Final f(x)  | Converged | Algorithm Time |
| ------------- | :----: | :-------: | :------------: | :--------: | :-----: | :---------: | :-------: | -------------- |
| `gd_01.txt`   |    2   |     0     |     0.10       |     5000   |    3    |     0       |    true   |   0.014100 ms  |
| `gd_02.txt`   |    4   |     2     |     0.02       |    10000   |    0    |     0       |    true   |   0.047400 ms  |
| `gd_03.txt`   |    6   |     2     |     0.02       |    20000   |    0    |     0       |    true   |   0.040300 ms  |
| `gd_04.txt`   |    8   |     2     |     0.01       |    50000   |    0    |     0       |    true   |   0.184300 ms  |
| `gd_05.txt`   |   10   |     2     |    0.005       |   100000   |    0    |     0       |    true   |   0.454200 ms  |

---

## 12. Maxflow-Mincut Result Table

The following table summarizes the measured Maxflow-Mincut results.

| Test File         | Vertices (V)   | Edges (E) | Source | Sink     | Maximum Flow   | Minimum Cut | Algorithm Time | Status |
| -------------     | :-----------:  | :-------: | :----: | :--:     | :-----------:  | :---------: | --------------- | ------ |
| `mf_06.txt`       |        6       |     10    |   0    |     5    |    23          |    23       |     0.0086 ms   | Pass   |
| `mf_10.txt`       |       10       |     15    |   0    |     9    |     8          |     8       |     0.0348 ms   | Pass   |
| `mf_100.txt`      |      100       |    200    |   0    |    99    |    83          |    83       |     0.0971 ms   | Pass   |
| `mf_1000.txt`     |     1000       |   1500    |   0    |   999    |    36          |    36       |     0.8122 ms   | Pass   |
| `mf_10000.txt`    |    10000       |  12000    |   0    |  9999    |    17          |    17       |     6.1367 ms   | Pass   |
| `mf_50000.txt`    |    50000       |  55000    |   0    | 49999    |     3          |     3       |    13.6148 ms   | Pass   |
| `mf_100000.txt`   |   100000       | 120000    |   0    |999999    |    40          |    40       |    100.234 ms   | Pass   |

Status is `Pass` when:

```text
Maximum Flow = Minimum Cut Capacity
```

---
## 13. Observations 
 
### 13.1 Gradient Descent 
 
- Gradient Descent successfully converged for all the test cases listed in the result table.
- The number of iterations increases across the test cases, from **5,000 iterations** in `gd_01.txt` to **100,000 iterations** in `gd_05.txt`.
- The execution time also generally increases as the number of iterations increases, from **0.014100 ms** for `gd_01.txt` to **0.454200 ms** for `gd_05.txt`.
- The polynomial degree increases from **2** to **10** across the test cases, which also increases the amount of computation required for calculating the function derivative.
- The learning rate decreases from **0.10** to **0.005** as the test cases become larger.
- Despite the different polynomial degrees, learning rates, and iteration limits, all the listed test cases reached a converged solution.
- Overall, the results show that the execution time increases with the computational workload while the implementation successfully converges for the tested configurations.

### 3.2 Maxflow-Mincut 
 
- Maxflow-Mincut successfully passed all the test cases listed in the result table.
- The test size increases from **6 vertices and 10 edges** in `mf_06.txt` to **100,000 vertices and 120,000 edges** in `mf_100000.txt`.
- The execution time generally increases as the number of vertices and edges increases, from **0.0086 ms** for `mf_06.txt` to **100.234 ms** for `mf_100000.txt`.
- The maximum-flow value is equal to the minimum-cut capacity for every test case in the result table.
- For example, the maximum flow and minimum cut are both **23** for `mf_06.txt`, both **83** for `mf_100.txt`, and both **40** for `mf_100000.txt`.
- The results demonstrate that the implementation is able to process the larger test case containing **100,000 vertices and 120,000 edges**.
- The increase in execution time for larger networks is expected because more vertices and edges must be processed during BFS, DFS, and residual-graph operations.
- Overall, the results show that the Maxflow-Mincut implementation maintains the required correctness condition while handling increasingly large flow networks.

