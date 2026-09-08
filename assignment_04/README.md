# CS509 Shared Buddy Assignments Specific Repo

## Student Details
* **Student 1 Name:** Arshdeep Singh
* **Entry Number 1:** 2026AIM1004
* **Student 2 Name:** Ishtveer Singh Billing
* **Entry Number 2:** 2026AIM1007

## Language and Environment
* **Programming Language:** C++
* **Compiler:** `g++` 
* **Timing Method:** `std::chrono::high_resolution_clock`

## Directory Structure
```text
CS509_2026AIM1004_2026AIM1007/
|-- README.md
|-- common_wrapper/
|   `-- wrapper.cpp
`-- assignment_04/
    |-- src/
    |   |-- kmeans.cpp
    |   |-- data.h
    |   `-- fastMap.cpp
    |-- driver/
    |   `-- driver.cpp
    |-- tests/
    |   |-- km_01.txt
    |   |-- km_02.txt
    |   |-- km_03.txt
    |   |-- km_04.txt
    |   |-- fm_01.txt
    |   |-- fm_02.txt
    |   |-- fm_03.txt
    |   `-- fm_04.txt
    |-- outputs/
    |   |-- output_km_01.txt
    |   |-- expected_km_01.txt
    |   |-- output_fm_01.txt
    |   |-- expected_fm_01.txt
    |   `-- ...
    |-- Makefile
    `-- README.md
```

## Assignment 04: K-Means Clustering and FastMap (Buddy Tasks)

### Objective
Implement two unsupervised machine learning / dimensionality reduction algorithms for duo/buddy work mode:
1. **K-Means Clustering:** Partition $N$ data points in $D$-dimensional space into $K$ clusters by minimizing the within-cluster sum of squared distances (WCSS).
2. **FastMap:** Map $N$ objects, described by a pairwise distance function, into a $k$-dimensional Euclidean space using iterative pivot selection, law-of-cosines projection, and distance deflation without explicit full-matrix construct or eigen-decomposition.

---

### Algorithm / Approach

1. **K-Means Clustering:**
   - **Initialization:** Select the first $K$ input points (in input file order) as initial centroids for reproducibility.
   - **Assignment Step:** Assign each point to its nearest centroid based on Euclidean distance.
   - **Update Step:** Recompute each centroid as the mean of all points assigned to it. If a cluster becomes empty, its centroid remains unchanged.
   - **Convergence:** Repeat assignment and update steps until no points change clusters (or max centroid shift $\le 	ext{tolerance}$), or until `MAX_ITERATIONS` is reached.

2. **FastMap:**
   - **Pivot Selection:** For each of the target $k$ dimensions, select a pair of pivot objects $O_a$ and $O_b$ that are approximately farthest apart using a fast heuristic (pick a random object, find the object farthest from it, then find the object farthest from that one).
   - **Projection:** Project each object $O_i$ onto the line connecting the two pivots using the law of cosines to determine its coordinate for the current dimension:
     $$x_i = \frac{d(O_a, O_i)^2 + d(O_a, O_b)^2 - d(O_b, O_i)^2}{2 \cdot d(O_a, O_b)}$$
   - **Deflation:** Update/deflate the remaining pairwise distances to remove the contribution of the newly added dimension before computing the next dimension:
     $$d_{\text{new}}(O_i, O_j)^2 = d_{\text{old}}(O_i, O_j)^2 - (x_i - x_j)^2$$
   - **Iteration:** Repeat until $k$ coordinates have been generated for all $N$ objects.

---

### Input Format

#### 1. For Points Data (K-Means Clustering)
```text
N D K
x0_1 x0_2 ... x0_D
x1_1 x1_2 ... x1_D
...
x(N-1)_1 x(N-1)_2 ... x(N-1)_D
MAX_ITERATIONS n
TOLERANCE epsilon
```
* **N:** Total number of points.
* **D:** Dimensionality of each point.
* **K:** Number of clusters to form.
* **MAX_ITERATIONS:** Maximum allowed iterations.
* **TOLERANCE:** Convergence threshold for maximum centroid shift (Euclidean distance).

#### 2. For Pairwise Distance Matrix (FastMap)
```text
N K
d(0,0) d(0,1) ... d(0,N-1)
d(1,0) d(1,1) ... d(1,N-1)
...
d(N-1,0) d(N-1,1) ... d(N-1,N-1)
```
* **N:** Number of objects.
* **K:** Target embedding dimensionality (typically 2 or 3).
* **d(i,j):** Non-negative symmetric floating-point pairwise distances with zero diagonal ($d(i,i) = 0$).

---

### Helper Functions & Preprocessing Notes
* Both K-Means Clustering and FastMap read coordinates or pairwise distance matrices directly from input text files and are **exempt** from CSR conversion.
* Timing measurements begin **immediately before** calling the core algorithm functions and end **immediately after** completion. Setup, parsing, and I/O execution times are excluded.

---

### File Structure
* `kmeans.cpp`: K-Means clustering algorithm implementation (assignment, centroid updates, WCSS calculation).
* `fastMap.cpp`: FastMap heuristic embedding routine (pivot selection, law of cosines projection, distance deflation).
* `data.h`: Header file for both alogirthms
* `testing_utils.h` / `testing_utils.cpp`: Execution timing utilities using `std::chrono::high_resolution_clock`.
* `driver.cpp`: Main driver program for command-line handling, input parsing, validation, algorithm execution, timing, and formatting output.

---

### Test Cases and Result Tables

#### 1. K-Means Clustering
| File | N | D | K | Max Iter. | Actual Iter. | WCSS | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `km_01.txt` | 100 | 2 | 3 | 300 | 6 | 57552.14 | 0.01 ms | PASSED |
| `km_02.txt` | 1,000 | 2 | 5 | 300 | 14 | 348745.61 | 0.15 ms | PASSED |
| `km_03.txt` | 10,000 | 5 | 8 | 300 | 60 | 21182086.61 | 22.2 ms | PASSED |
| `km_04.txt` | 100,000 | 5 | 10 | 300 | 237 | 189543037.23 | 968.55 ms | PASSED |

#### 2. FastMap
| File | N | Target k | Pivots (per dim) | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `fm_01.txt` | 10 | 2 | 2 | 0 ms | PASSED |
| `fm_02.txt` | 100 | 3 | 2 | 0.4 ms | PASSED |
| `fm_03.txt` | 1,000 | 3 | 2 | 30.1652 ms | PASSED |
| `fm_04.txt` | 10,000 | 3 | 2 | 2949.55 ms | PASSED |


---

### System Specification
* **Processor:** AMD Ryzen 7 5800H
* **RAM:** 16 GB
* **Storage:** 512 GB

---

### Complexity
* **K-Means Clustering:**
  * **Time Complexity:** $\mathcal{O}(I \cdot N \cdot K \cdot D)$, where $I$ is the number of iterations, $N$ is the number of data points, $K$ is the number of clusters, and $D$ is the dimensionality.
  * **Auxiliary Space:** $\mathcal{O}(N \cdot D + K \cdot D)$ for storing data points and cluster centroids.
* **FastMap:**
  * **Time Complexity:** $\mathcal{O}(k \cdot N)$, where $k$ is the target output dimensionality and $N$ is the number of objects (assuming distances are evaluated/retrieved in $\mathcal{O}(1)$ time).
  * **Auxiliary Space:** $\mathcal{O}(N \cdot k)$ for storing the embedded coordinates across $k$ target dimensions.