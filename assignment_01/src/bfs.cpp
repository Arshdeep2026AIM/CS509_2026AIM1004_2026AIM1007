#include <iostream>
#include <vector>
#include <queue>

#include "csr.h"

using namespace std;

void bfs(Csr graph) {

    queue<int> forBfs;
    vector<int> traversal, distances(graph.csrGraph.numVertices, -1);
    int distance = 0;

    forBfs.push(graph.csrGraph.sourceVertex);
    distances[graph.csrGraph.sourceVertex] = 0;
    do {
        int vertice, neighbors;
        vertice = forBfs.front();
        forBfs.pop();
        traversal.push_back(vertice);
        
        neighbors = graph.csrGraph.rowPtr[vertice + 1] - graph.csrGraph.rowPtr[vertice];

        for (int i = graph.csrGraph.rowPtr[vertice]; i < graph.csrGraph.rowPtr[vertice] + neighbors; i++) {
            int neighbor = graph.csrGraph.colIdx[i];
            
            if (distances[neighbor] == -1) {
                forBfs.push(neighbor);
                distances[neighbor] = distances[vertice] + 1;
            }
        }
        
    }while (!(forBfs.empty()));

    cout << "Source: " << graph.csrGraph.sourceVertex << "\n";
    cout << "Traversal: ";
    for (int entry : traversal) {
        cout << entry << " ";
    }
    cout << "\n" << "Distances:" << "\n";
    int idx = 0;
    for (int entry : distances) {
        cout << idx << " " << entry << "\n";
        idx++;
    }
}