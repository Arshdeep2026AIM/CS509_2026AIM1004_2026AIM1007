#include <iostream>
#include <vector>
#include <stack>

#include "csr.h"

using namespace std;

void dfs(Csr graph) {
    CsrGraph csr = graph.csrGraph;

    stack<int> forDfs;
    vector<int> traversal, visited(csr.numVertices, -1);
}
