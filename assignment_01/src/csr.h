#ifndef CSR_H
#define CSR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct CsrGraph {
    int numVertices = 0;
    int numEdges = 0;
    int sourceVertex = 0;

    vector<int> rowPtr;
    vector<int> colIdx;
    vector<int> values;
};

class Csr {
public:
    CsrGraph csrGraph;

    void convert(string path);
    void convert(string path, bool isWeighted);
};

#endif // CSR_H