# CS509 Laboratory - Assignment 04

## Student Details

| Field                 | Information        |
| --------------------- | ------------------ |
| Student Name          | Akash Maurya        |
| Entry Number          | 2026CSM1024         |
| Buddy Name            | Aryan Shrivastva    |
| Buddy Entry Number    | 2026CSM1007         |
| Programming Language  | C++                 |

---

## 1. Assignment Overview

This assignment is completed as a **Buddy/Pair Assignment** by two students in a shared repository.

The assignment implements two algorithms:

### K-Means Clustering

- An iterative clustering algorithm used to partition a set of data points into K clusters.
- Each data point is assigned to the cluster whose centroid is closest to the point using Euclidean distance.
- The centroids are updated by calculating the mean of all points assigned to each cluster.
- The algorithm continues until the clusters converge, the centroid movement becomes smaller than the specified tolerance, or the maximum number of iterations is reached.
- The implementation uses the first K input points as the initial centroids.
- The within-cluster sum of squared distances (WCSS) is calculated to measure the clustering quality.

### FastMap

- A dimensionality reduction algorithm used to map N objects into a lower-dimensional Euclidean space.
- Uses a pairwise distance matrix between the objects as input.
- Selects approximately farthest pairs of objects as pivots.
- Projects every object onto the line between the selected pivots using the law of cosines.
- Deflates the remaining pairwise distances after every generated dimension.
- Repeats the process until the required number of dimensions is generated.

---

## 2. Language and Environment

The complete repository has been implemented using C++.

```text
Programming Language : C++
Compiler              : GNU g++ Compiler
Operating System      : Windows 11
Build Tool            : Makefile
```

---

## 3. Repository Structure

The Assignment 04 directory follows the required CS509 laboratory organization.

```text
assignment_04/
│
├── driver/
│   ├── driver_kmeans.cpp
│   └── driver_fastmap.cpp
│
├── src/
│   ├── KMeans.hpp
│   ├── KMeans.cpp
│   ├── FastMap.hpp
│   └── FastMap.cpp
│
├── tests/
│   ├── kmeans/
│   │   ├── km_01.txt
│   │   ├── km_02.txt
│   │   ├── km_03.txt
│   │   └── km_04.txt
│   │
│   └── fastmap/
│       ├── fm_5.txt
│       ├── fm_10.txt
│       ├── fm_100.txt
│       ├── fm_1000.txt
|       ├── fm_5000.txt
│       └── fm_10000.txt
│
├── outputs/
│   ├── kmeans/
│   │   ├── km_01_output.txt
│   │   ├── km_02_output.txt
│   │   └── ...
│   │
│   └── fastmap/
│       ├── fm_5.txt
│       ├── fm_10.txt
│       └── ...
│
├── executables/
│   ├── kmeans.exe
│   └── fastmap.exe
│
└── README.md
```

## 4. Directory and File Responsibilities

### 4.1 `src/`

Contains the main algorithm implementations.

#### `KMeans.hpp`

Stores the declarations of the K-Means Clustering functions.

#### `KMeans.cpp`

Implements:

- Point-to-centroid Euclidean distance calculation.
- Initial centroid selection.
- Point assignment to the nearest centroid.
- Centroid update.
- Empty cluster handling.
- Convergence checking.
- WCSS calculation.

#### `FastMap.hpp`

Stores the declarations and structures required by the FastMap implementation.

#### `FastMap.cpp`

Implements:

- Pivot selection.
- Farthest-object calculation.
- Coordinate calculation using the law of cosines.
- Distance deflation.
- Generation of multiple target dimensions.
- Final coordinate calculation.

---

### 4.2 `driver/`

Contains a dedicated driver for each algorithm.

#### `driver_kmeans.cpp`

Used for:

- locating K-Means test files,
- reading the number of points,
- reading the number of dimensions,
- reading the number of clusters,
- reading the input coordinates,
- reading the maximum number of iterations,
- reading the convergence tolerance,
- calling K-Means,
- measuring algorithm execution time,
- printing cluster assignments,
- printing final centroids,
- printing WCSS,
- printing the number of iterations,
- printing convergence status,
- creating output files.

#### `driver_fastmap.cpp`

Used for:

- locating FastMap test files,
- reading the number of objects,
- reading the target dimensionality,
- reading the pairwise distance matrix,
- calling FastMap,
- measuring algorithm execution time,
- printing the selected pivots,
- printing generated coordinates,
- creating output files.

---

### 4.3 `tests/`

Stores all Assignment 04 test cases.

The test cases are divided into:

```text
tests/
├── kmeans/
└── fastmap/
```

The K-Means test cases contain multidimensional points.

The FastMap test cases contain complete pairwise distance matrices.

---

### 4.4 `outputs/`

Stores the generated output files.

```text
outputs/
├── kmeans/
└── fastmap/
```

K-Means output contains:

- Cluster assignments.
- Final centroids.
- WCSS.
- Number of iterations.
- Convergence status.
- Execution time.

FastMap output contains:

- Target dimensions.
- Selected pivots.
- Object coordinates.
- Execution time.

---


## 5. Assignment Objectives

The objectives of this assignment are:

1. Implement K-Means Clustering.
2. Partition N data points into K clusters.
3. Use Euclidean distance to assign points to the nearest centroid.
4. Initialize the first K input points as the initial centroids.
5. Update the centroids after every assignment step.
6. Handle empty clusters by keeping the previous centroid unchanged.
7. Detect convergence using the specified tolerance.
8. Stop the algorithm after the maximum number of iterations if convergence is not achieved.
9. Calculate the within-cluster sum of squared distances (WCSS).
10. Implement the FastMap dimensionality reduction algorithm.
11. Select approximately farthest pivot objects.
12. Calculate object coordinates using the law of cosines.
13. Deflate pairwise distances after every generated dimension.
14. Repeat the FastMap process until the required number of dimensions is generated.
15. Measure only algorithm execution time.
16. Test the algorithms on the prescribed test cases.
17. Generate separate output files for every test case.

---

## 6. Algorithm Comparison

| Property            | K-Means Clustering            | FastMap                          |
| -------------------- | ------------------------------ | ---------------------------------- |
| Problem              | Data clustering                 | Dimensionality reduction           |
| Input                | N points in D dimensions        | N × N pairwise distance matrix     |
| Output               | K clusters and centroids        | k-dimensional coordinates          |
| Main Parameter       | Number of clusters K            | Target dimensions k                |
| Distance             | Euclidean distance              | Pairwise distance                  |
| Approach             | Iterative clustering            | Iterative dimensional mapping      |
| Initialization       | First K input points            | Approximately farthest pivots      |
| Main Operation       | Assignment + centroid update    | Projection + distance deflation    |
| Stopping Condition   | Tolerance / max iterations      | Required target dimensions         |
| Quality Measure      | WCSS                            | Distance preservation              |
| Main Working Space   | O(ND + KD)                      | O(N²) for full distance matrix     |
| Main Limitation      | Repeated distance calculations  | Large pairwise distance matrix     |

---

## 7. K-Means Clustering

K-Means Clustering partitions N data points in D-dimensional space into K clusters.

The objective is to minimize the within-cluster sum of squared distances between each point and the centroid of its assigned cluster.

The general K-Means process is:

```text
Initialize K Centroids
        |
        v
Assign Points to Nearest Centroid
        |
        v
Update Centroids
        |
        v
Check Convergence
        |
        +------ No ------> Next Iteration
        |
       Yes
        |
        v
      Finish
```

### 8.1 K-Means Algorithm Steps

1. Read N, D, and K.
2. Read all N points having D dimensions.
3. Read the maximum number of iterations.
4. Read the convergence tolerance.
5. Use the first K input points as the initial centroids.
6. Calculate the Euclidean distance between every point and every centroid.
7. Assign every point to the nearest centroid.
8. Recalculate every centroid using the mean of the points assigned to that cluster.
9. If a cluster is empty, keep its previous centroid unchanged.
10. Calculate the movement of the centroids.
11. Check whether the maximum centroid movement is smaller than or equal to the tolerance.
12. If the convergence condition is satisfied, stop the algorithm.
13. Otherwise, repeat the assignment and centroid update steps.
14. Stop when the maximum number of iterations is reached.
15. Calculate the final WCSS.
16. Report the cluster assignments, final centroids, WCSS, iterations, convergence status, and execution time.

---


## 9. FastMap

FastMap is a dimensionality reduction algorithm that maps N objects into a k-dimensional Euclidean space.

The algorithm works directly with pairwise distances and generates one coordinate dimension at a time.

For each dimension, two approximately farthest objects are selected as pivots.

Every object is then projected onto the line between the pivots.

After generating the current dimension, the contribution of that dimension is removed from the remaining pairwise distances.

### 9.1 FastMap Algorithm Steps

1. Read N and the target number of dimensions K.
2. Read the complete N × N pairwise distance matrix.
3. Select an initial object.
4. Find an object approximately farthest from the selected object.
5. From that object, find another approximately farthest object.
6. Use the two objects as pivots for the current dimension.
7. Calculate the coordinate of every object using the law of cosines.
8. Store the generated coordinate for the current dimension.
9. Deflate the remaining pairwise distances.
10. Repeat the pivot selection and projection process for the next dimension.
11. Continue until K dimensions have been generated.
12. Report the selected pivots, generated coordinates, and execution time.

---




## 11. FastMap Results Table

The following table summarizes the measured FastMap results, including the pivots selected for every generated dimension.

| File            |       N | Target k | Pivots (per dim)                                              | Avg. Distance Error | Time             | Status |
| ---------------- | ------: | :------: | ---------------------------------------------------------------- | :--------------------: | ----------------- | :----: |
| `fm_5.txt`      |       5 |     2    | Dim 1: 4, 0 · Dim 2: 2, 1                                        | `[ ]`                   | 0.001400 ms        | Pass   |
| `fm_10.txt`     |      10 |     2    | Dim 1: 7, 4 · Dim 2: 6, 0                                        | `[ ]`                   | 0.003300 ms        | Pass   |
| `fm_100.txt`    |     100 |     2    | Dim 1: 53, 88 · Dim 2: 1, 52                                     | `[ ]`                   | 0.069700 ms        | Pass   |
| `fm_1000.txt`   |   1,000 |     2    | Dim 1: 560, 388 · Dim 2: 17, 344                                 | `[ ]`                   | 7.137700 ms        | Pass   |
| `fm_5000.txt`   |   5,000 |     3    | Dim 1: 2908, 4567 · Dim 2: 2040, 4909 · Dim 3: 4672, 4180        | `[ ]`                   | 327.595400 ms      | Pass   |
| `fm_10000.txt`  |  10,000 |     2    | Dim 1: 6115, 4085 · Dim 2: 8062, 7500                            | `[ ]`                   | 1108.417600 ms     | Pass   |

fm_5000.txt & fm_10000.txt cannot be uploades due to it large size

## 12. Observations


### 12.2 FastMap

- FastMap successfully processed the smaller test cases and generated the requested lower-dimensional representations.
- The execution time increases as the number of objects increases.
- The execution time for `fm_5.txt` is `0.001400 ms`.
- The execution time for `fm_10.txt` is `0.003300 ms`.
- The execution time for `fm_100.txt` is `0.069700 ms`.
- The execution time for the larger completed test is `7.137700 ms`.
- The optional large test with `50,000` objects required `1108.417600 ms`.
- The increase in execution time is expected because FastMap repeatedly performs pivot selection, coordinate calculation, and distance deflation.
- The number of target dimensions also affects the execution time because every additional dimension requires another pivot selection and distance-deflation step.
- Since FastMap uses a full N × N distance matrix, the memory requirement increases quadratically with the number of objects.
- The pivot objects can differ depending on the pivot-selection process.
- Overall, FastMap performs efficiently for small and medium-sized datasets, but the full pairwise distance matrix becomes a major scalability limitation for very large datasets.
