# CS509 Laboratory Repository

## Repository Overview
Buddy Assignments Repository for CS509 - PG Software Lab M.Tech AI 2026-27.

## Student / Pair Details
2026AIM1004 - Arshdeep Singh
2026AIM1007 - Ishtveer Singh Billing

## Language and Environment
C++ Language
g++ compiler
GNU Make

## Directory Structure
```text
CS509_CS1001_AI1002/
|-- common_wrapper/
|   `-- common_wrapper.cpp
|-- assignment_01/
|   |-- src/
|   |-- driver/
|   |-- tests/
|   |   |-- unweighted10.txt
|   |   |-- unweighted100.txt
|   |   |-- unweighted10000.txt
|   |   `-- ...
|   `-- outputs/
|       |-- output_bfs_10.txt
|       |-- output_bfs_100.txt
|       `-- ...
|-- Makefile
`-- README.md
```

## Common Wrapper: Build and Usage
Wrapper is the main program which is used to choose and run the algorithm of choice on input file from any folder.

## Assignment 01 - BFS, DFS and SSSP
### Objective
Program and execute BFS, DFS and SSSP and record their execution times.

### Algorithm / Approach
BFS is implemented using Queue
DFS is implemented using Stack
SSSP, used Djikstra algorithm since the graph weights were positive, using priority Queue
The input file in the format of adjacency list gets converted to CSR format using helper function. From there any algorithm that runs uses the CSR encoding of graph.

### Input Format
Text files in the following format:

#### For Unweighted Adjacency-List
V E
u0 degree neighbor1 neighbor2 ...
u1 degree neighbor1 neighbor2 ...
...
u(V-1) degree neighbor1 neighbor2 ...
SOURCE s
V: number of vertices.
E: number of edges. For an undirected graph, count each graph edge once in E even though it appears in both adjacency lists.
u: vertex whose adjacency list is being written.
degree: number of neighbours listed after u.
s: source vertex for BFS or DFS.

#### For weighted Adjacency-List
V E
u0 degree neighbor1 weight1 neighbor2 weight2 ...
u1 degree neighbor1 weight1 neighbor2 weight2 ...
...
u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
SOURCE s

### Helper Functions / CSR Conversion
CSR Conversion is done using csr.cpp and csr.h file.
The csr format of three arrays, along with number of vertices, edges and the source vertex are combined to be in a single structure CsrGraph.
Class Csr is used to define functions that convert the input txt file, depending on whether it is weighted or not.
The functions convert (overloading) take in filepath as input and fill the struct with correct values.

Graph_algorithms header file contains the initialization of all 3 graph algorithms, with each algorithm implemented in seperate file.


### Compilation
To compile all source files (`driver.cpp`, `csr.cpp`, `bfs.cpp`, `dfs.cpp`, `sssp.cpp`) and generate the executable, run:

```bash
make
```
### Execution
./driver_app

### Test Cases and Result Table
| Algorithm | Test File | Vertices | Edges | Input Type | Source | Expected Output | Actual Output | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| BFS | `unweighted10.txt` | 10 | 23 | Unweighted adjacency list converted to CSR | 0 | `expected_bfs_10.txt` | `output_bfs_10.txt` | 0 ms | Pass |
| BFS | `unweighted100.txt` | 100 | 208 | Unweighted adjacency list converted to CSR | 0 | `expected_bfs_100.txt` | `output_bfs_100.txt` | 0 ms | Pass |
| BFS | `unweighted10000.txt` | 10000 | 20012 | Unweighted adjacency list converted to CSR | 0 | `expected_bfs_10000.txt` | `output_bfs_10000.txt` | 1 ms | Pass |
| BFS | `unweighted50000.txt` | 50000 | 99923 | Unweighted adjacency list converted to CSR | 0 | `expected_bfs_50000.txt` | `output_bfs_50000.txt` | 13 ms | Pass |
| BFS | `unweighted100000.txt` | 100000 | 199709 | Unweighted adjacency list converted to CSR | 0 | `expected_bfs_100000.txt` | `output_bfs_100000.txt` | 26 ms | Pass |
| DFS | `unweighted10.txt` | 10 | 23 | Unweighted adjacency list converted to CSR | 0 | `expected_dfs_10.txt` | `output_dfs_10.txt` | 0 ms | Pass |
| DFS | `unweighted100.txt` | 100 | 208 | Unweighted adjacency list converted to CSR | 0 | `expected_dfs_100.txt` | `output_dfs_100.txt` | 0 ms | Pass |
| DFS | `unweighted10000.txt` | 10000 | 20012 | Unweighted adjacency list converted to CSR | 0 | `expected_dfs_10000.txt` | `output_dfs_10000.txt` | 3 ms | Pass |
| DFS | `unweighted50000.txt` | 50000 | 99923 | Unweighted adjacency list converted to CSR | 0 | `expected_dfs_50000.txt` | `output_dfs_50000.txt` | 17 ms | Pass |
| DFS | `unweighted100000.txt` | 100000 | 199709 | Unweighted adjacency list converted to CSR | 0 | `expected_dfs_100000.txt` | `output_dfs_100000.txt` | 34 ms | Pass |
| SSSP | `sssp10.txt` | 10 | 19 | Positive weighted adjacency list converted to CSR | 0 | `expected_sssp_10.txt` | `output_sssp_10.txt` | 0 ms | Pass |
| SSSP | `sssp100.txt` | 100 | 202 | Positive weighted adjacency list converted to CSR | 0 | `expected_sssp_100.txt` | `output_sssp_100.txt` | 0 ms | Pass |
| SSSP | `sssp10000.txt` | 10000 | 20116 | Positive weighted adjacency list converted to CSR | 0 | `expected_sssp_10000.txt` | `output_sssp_10000.txt` | 19 ms | Pass |
| SSSP | `sssp50000.txt` | 50000 | 99983 | Positive weighted adjacency list converted to CSR | 0 | `expected_sssp_50000.txt` | `output_sssp_50000.txt` | 113 ms | Pass |
| SSSP | `sssp100000.txt` | 100000 | 200304 | Positive weighted adjacency list converted to CSR | 0 | `expected_sssp_100000.txt` | `output_sssp_100000.txt` | 231 ms | Pass |

### System Specification
Processor: AMD Ryzen 7 5800H
RAM: 16 GB
Storage: 512 GB

### Complexity

**Breadth-First Search (BFS) & Depth-First Search (DFS)**
*   **Time Complexity:** $O(V + E)$, where $V$ is the number of vertices and $E$ is the number of edges. We visit every vertex and explore every edge exactly once.
*   **Space Complexity:** $O(V + E)$ to store the graph in Compressed Sparse Row (CSR) format. The auxiliary space for the Queue (in BFS) or Stack (in DFS) and the visited arrays is $O(V)$. Overall Space Complexity is $O(V + E)$.

**Single-Source Shortest Path (SSSP) - Dijkstra's Algorithm**
*   **Time Complexity:** $O((V + E) \log V)$. Using a min-priority queue allows us to extract the minimum distance vertex in $O(\log V)$ time, and each edge relaxation takes $O(\log V)$ time.
*   **Space Complexity:** $O(V + E)$ to store the weighted graph in CSR format. The priority queue and distance tracking arrays require $O(V)$ auxiliary space. Overall Space Complexity is $O(V + E)$.



## Assignment 02: Graph Analytics (Triangle Counting, Betweenness Centrality, Connected Components)

### Objective
Implement structural graph analysis algorithms on unweighted, undirected graphs using Compressed Sparse Row (CSR) format:
1. Triangle Counting using neighbor list intersections.
2. Betweenness Centrality using Brandes' Algorithm.
3. Connected Components labeling via BFS/DFS or Union-Find.

### Algorithm / Approach
1. **Triangle Counting:** Sorts neighbor lists in CSR representation to perform efficient common-neighbor checks for connected pairs. Divides total discovery count by 3.
2. **Betweenness Centrality:** Computes unnormalized Brandes' centrality for unweighted graphs by running BFS from all source vertices and accumulating shortest path dependencies.
3. **Connected Components:** Uses graph traversal (BFS/DFS) or Disjoint Set Union (DSU) to assign unique sequential component IDs to all vertices.

### Input Format
Text files in the following format:

#### For Unweighted Adjacency-List
V E
u0 degree neighbor1 neighbor2 ...
u1 degree neighbor1 neighbor2 ...
...
u(V-1) degree neighbor1 neighbor2 ...
SOURCE s
V: number of vertices.
E: number of edges. For an undirected graph, count each graph edge once in E even though it appears in both adjacency lists.
u: vertex whose adjacency list is being written.
degree: number of neighbours listed after u.
s: source vertex for BFS or DFS.

#### For weighted Adjacency-List
V E
u0 degree neighbor1 weight1 neighbor2 weight2 ...
u1 degree neighbor1 weight1 neighbor2 weight2 ...
...
u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
SOURCE s

### Helper Functions / CSR Conversion
Pre-processes adjacency lists into CSR format (`row_ptr`, `col_idx`) before timer invocation. Neighbor lists are pre-sorted for optimized triangle counting intersections.

### File Structure
* `csr.h` / `csr.cpp`: Adjacency list to CSR conversion and sorting routines.
* `triangle_optimized.cpp`: Intersection-based triangle counting logic.
* `betweenness_centrality.cpp`: Brandes' centrality algorithm.
* `components.cpp`: Component identification routines.
* `driver.cpp`: Dedicated driver module for input validation, CSR construction, timed execution calls, and result printing.

### Test Cases and Result Table

| Algorithm | Test File | Vertices ($V$) | Edges ($E$) | Expected Output | Actual Output | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Triangle Counting | `tc_10.txt` | 10 | 19 | Total Triangles | Total Triangles | 0 ms | PASSED |
| Triangle Counting | `tc_100.txt` | 100 | 292 | Total Triangles | Total Triangles | 0 ms | PASSED |
| Triangle Counting | `tc_10000.txt` | 10000 | 29985 | Total Triangles | Total Triangles | 4.6 ms | PASSED |
| Triangle Counting | `tc_50000.txt` | 50000 | 149989 | Total Triangles | Total Triangles | 30.6 ms | PASSED |
| Triangle Counting | `tc_100000.txt` | 100000 | 299956 | Total Triangles | Total Triangles | 100.557 ms | PASSED |
| Betweenness Centrality | `bc_10.txt` | 10 | 9 | Centrality per vertex | Centrality per vertex | 0 ms | PASSED |
| Betweenness Centrality | `bc_100.txt` | 100 | 99 | Centrality per vertex | Centrality per vertex | 0.992 ms | PASSED |
| Betweenness Centrality | `bc_1000.txt` | 1000 | 999 | Centrality per vertex | Centrality per vertex | 73.399 ms | PASSED |
| Betweenness Centrality | `bc_5000.txt` | 5000 | 4999 | Centrality per vertex | Centrality per vertex | 2117.65 ms | PASSED |
| Betweenness Centrality | `bc_10000.txt` | 10000 | 9999 | Centrality per vertex | Centrality per vertex | 9775.45 ms | PASSED |
| Connected Components | `cc_10.txt` | 10 | 38 | Component per vertex | Component per vertex | 0 ms | PASSED |
| Connected Components | `cc_100.txt` | 100 | 2500 | Component per vertex | Component per vertex | 1 ms | PASSED |
| Connected Components | `cc_10000.txt` | 10000 | 19006 | Component per vertex | Component per vertex | 13 ms | PASSED |

### System Specification
Processor: AMD Ryzen 7 5800H
RAM: 16 GB
Storage: 512 GB

### Complexity
* **Triangle Counting:** Time Complexity: $\mathcal{O}(E \cdot \Delta)$ where $\Delta$ is max degree, Auxiliary Space: $\mathcal{O}(V + E)$
* **Betweenness Centrality:** Time Complexity: $\mathcal{O}(V \cdot E)$, Auxiliary Space: $\mathcal{O}(V + E)$
* **Connected Components:** Time Complexity: $\mathcal{O}(V + E)$, Auxiliary Space: $\mathcal{O}(V)$

## Assignment 03: Gradient Descent and Max-Flow Min-Cut Graph

### Objective
Implement a structural graph algorithm using Compressed Sparse Row (CSR) format alongside a polynomial numerical optimization algorithm:
1. **Gradient Descent:** Optimization of generic one-variable polynomial functions $f(x) = \sum_{i=0}^d c_i x^i$.
2. **Maxflow-Mincut:** Maximum flow computation and residual graph reachability for $s$-$t$ minimum cut on directed capacity CSR graphs (using Dinic's algorithm recommended).

### Algorithm / Approach
1. **Gradient Descent:** Computes numerical minimums for generic $d$-degree polynomial functions $f(x)$ using analytical derivative $f'(x) = \sum_{i=1}^d i \cdot c_i x^{i-1}$. Iteratively updates $x_{new} = x - \alpha f'(x)$ until $|f'(x)| \le \epsilon$ or the maximum iteration limit is met. 
Stops when |f'(x)| <= tolerance, or when the maximum number of iterations has been reached.

2. **Maxflow-Mincut:** Computes the maximum $s$-$t$ network flow from source $s$ to sink $t$ without exceeding edge capacities. Extracts the minimum $s$-$t$ cut from the final residual graph by performing graph traversal to find all vertices reachable from $s$. Solved using Dinic's algorithm, in which the high level procedure goes as follows: First building a level graph using bfs, which will help dfs traverse the shortest edges to reach sink. Then dfs is applied on a single fixed level graph, until no more paths can be augmented (essentially in the main residual graph, augmenting means passing flow via a certain path from source to sink). This keeps happening until a level graph cannot be built using bfs. The above steps help calculate max flow. For minimum cut capacity, the final residual graph is used, by performing bfs on it and finding partitions by traversing edges from source where the difference between capacity adn flow is > 0, ultimately finding and comparing that the max flow is equal to the min cut (based on theorem). This algorithm uses current pointer optimization, which skips dead-end edges.

### Input Format
Text files in the following formats:

#### For Directed Capacity Adjacency-List (Maxflow-Mincut)
```text
V E
u0 degree neighbor1 capacity1 neighbor2 capacity2 ...
u1 degree neighbor1 capacity1 neighbor2 capacity2 ...
...
u(V-1) degree neighbor1 capacity1 neighbor2 capacity2 ...
SOURCE s
SINK t
```
* **V:** Number of vertices.
* **E:** Number of directed capacity edges.
* **s, t:** Source and sink vertex IDs.

#### For Polynomial Optimization (Gradient Descent)
```text
DEGREE d
COEFFICIENTS c0 c1 c2 ... cd
INITIAL_X x0
LEARNING_RATE alpha
TOLERANCE epsilon
MAX_ITERATIONS n
```
* **d:** Polynomial degree.
* **c0...cd:** $d+1$ floating-point coefficients in ascending power order.

### Helper Functions / CSR Conversion
Pre-processes adjacency lists into CSR format (`row_ptr`, `col_idx`, `values`) before invoking timers for Maxflow-Mincut routines. Gradient Descent reads parameters directly and bypasses CSR. Execution timing begins **only after** CSR creation is completed.

### File Structure
* `csr.h` / `csr.cpp`: Adjacency list to CSR conversion routines (reused from Assignment 1/2).
* `testing_utils.h` / `testing_utils.cpp`: Function to calculate time of various algorithms.
* `gradientDescent.cpp`: Generic variable-degree polynomial Gradient Descent solver.
* `maxflowMincut.cpp`: Maxflow and $s$-$t$ min-cut residual reachability solver (e.g., Dinic's Algorithm).
* `driver.cpp`: Dedicated driver module for input parsing, validation, CSR setup, timing measurements, and output display.

---

### Test Cases and Result Tables

#### 1. Gradient Descent
| File | Degree | Initial $x_0$ | Rate ($ lpha$) | Tol ($\epsilon$) | Max Iter. | Exp. $x^*$ | Exp. $f(x^*)$ | Actual $x$ | Actual $f(x)$ | Iter. / Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `gd_01.txt` | 2 | 0 | 0.10 | 1e-6 | 5,000 | 3 | 0 | 3.000000 | 0.000000 | 71 / 0 ms | PASSED |
| `gd_02.txt` | 4 | 2 | 0.02 | 1e-6 | 10,000 | 0 | 0 | 0.000000 | 0.000000 | 181 / 0 ms | PASSED |
| `gd_03.txt` | 6 | 2 | 0.02 | 1e-6 | 20,000 | 0 | 0 | 0.000000 | 0.000000 | 350 / 0 ms | PASSED |
| `gd_04.txt` | 8 | 2 | 0.01 | 1e-8 | 50,000 | 0 | 0 | 0.000000 | 0.000000 | 949 / 0.4016 ms | PASSED |
| `gd_05.txt` | 10 | 2 | 0.005 | 1e-10 | 100,000 | 0 | 0 | 0.000000 | 0.000000 | 2365 / 0.998 ms | PASSED |

#### 2. Maxflow-Mincut
| File | Vertices ($V$) | Edges ($E$) | Source ($s$) | Sink ($t$) | Exp. Flow | Actual Flow | Cut Capacity | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `maxflow_10.txt` | 10 | 40 | 0 | 9 | 117 | 117 | 117 | 0 ms | PASSED |
| `maxflow_100.txt` | 100 | 400 | 0 | 99 | 201 | 201 | 201 | 0.7988 ms | PASSED |
| `maxflow_1000.txt` | 1000 | 4000 | 0 | 999 | 94 | 94 | 94 | 4.7792 ms | PASSED |
| `maxflow_10000.txt` | 10000 | 70000 | 0 | 9999 | 17579 | 17579 | 17579 | 94.3042 ms | PASSED |
| `maxflow_50000.txt` | 50000 | 350000 | 0 | 49999 | 7543 | 7543 | 7543 | 469.617 ms | PASSED |
| `maxflow_100000.txt` | 100000 | 700000 | 0 | 99999 | 21901 | 21901 | 21901 | 929.802 ms | PASSED |

---

### System Specification
Processor: AMD Ryzen 7 5800H
RAM: 16 GB
Storage: 512 GB

### Complexity
* **Gradient Descent:** Time Complexity: $\mathcal{O}(I \cdot d)$ where $I$ is total iterations and $d$ is polynomial degree, Auxiliary Space: $\mathcal{O}(d)$
* **Maxflow-Mincut (Dinic's Algorithm):** Time Complexity: $\mathcal{O}(V^2 E)$, Auxiliary Space: $\mathcal{O}(V + E)$

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
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| `fm_01.txt` | 10 | 2 | 2 | 0 ms | PASSED |
| `fm_02.txt` | 100 | 3 | 2 | 0.4 ms | PASSED |
| `fm_03.txt` | 1,000 | 3 | 2 | 30.1652 ms | PASSED |
| `fm_04.txt` | 10,000 | 3 | 2 | 2949.55 ms | PASSED |


---

### Complexity
* **K-Means Clustering:**
  * **Time Complexity:** $\mathcal{O}(I \cdot N \cdot K \cdot D)$, where $I$ is the number of iterations, $N$ is the number of data points, $K$ is the number of clusters, and $D$ is the dimensionality.
  * **Auxiliary Space:** $\mathcal{O}(N \cdot D + K \cdot D)$ for storing data points and cluster centroids.
* **FastMap:**
  * **Time Complexity:** $\mathcal{O}(k \cdot N)$, where $k$ is the target output dimensionality and $N$ is the number of objects (assuming distances are evaluated/retrieved in $\mathcal{O}(1)$ time).
  * **Auxiliary Space:** $\mathcal{O}(N \cdot k)$ for storing the embedded coordinates across $k$ target dimensions.