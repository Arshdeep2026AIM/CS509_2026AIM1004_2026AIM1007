#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "data.h"

using namespace std;

vector<vector<double>> result;
vector<vector<int>> pivots;

void readFastMap(string inputFile, vector<vector<double>>& dist, int& n, int& k) {
    ifstream File(inputFile);
    if (!File.is_open()) exit(1);

    File >> n >> k;
    for (int i = 0; i < n; i++) {
        vector<double> row;
        double temp;
        for (int j = 0; j < n; j++) {
            File >> temp;
            row.push_back(temp);
        }
        dist.push_back(row);
    }
    result.clear();
    pivots.clear();
    result.assign(n, vector<double>(k, 0.0));
}

double getDistance(int pointA, int pointB, int& currDim, vector<vector<double>>& distSq) {
    double diff = distSq[pointA][pointB];
    for (int i = 0; i < currDim; i++) {
        double distance = result[pointA][i] - result[pointB][i];
        diff -= (distance * distance);
    }
    return max(0.0, diff);
}

int chooseDistantObject(int source, int& n, int& currDim, vector<vector<double>>& distSq) {
    int pivot = 0;
    double maxDist = -1.0;
    for(int i = 0; i < n; i++) {
        double dist = getDistance(source, i, currDim, distSq);
        if (dist > maxDist) {
            maxDist = dist;
            pivot = i;
        }
    }
    return pivot;
}

void fastMap(int& n, int& k, vector<vector<double>>& dist) {
    vector<vector<double>> distSquared(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distSquared[i][j] = dist[i][j] * dist[i][j];
        }
    }
    // From this point all distance variables are squared distances
    for (int dim = 0; dim < k; dim++) {
        int pivotA = chooseDistantObject(0, n, dim, distSquared);
        int pivotB = chooseDistantObject(pivotA, n, dim, distSquared);
        pivots.push_back({pivotA, pivotB});

        double distAtoB = getDistance(pivotA, pivotB, dim, distSquared);
        if (sqrt(distAtoB) <= 1e-12) {
            for (int i = 0; i < n; i++) result[i][dim] = 0;
            continue;
        }

        for (int i = 0; i < n; i++) {
            double distAtoI = getDistance(pivotA, i, dim, distSquared);
            double distBtoI = getDistance(pivotB, i, dim, distSquared);
            double coords = (distAtoI + distAtoB - distBtoI) / (2 * sqrt(distAtoB));
            result[i][dim] = coords;
        }
    }
}

