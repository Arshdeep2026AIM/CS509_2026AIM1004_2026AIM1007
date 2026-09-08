#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <string>
#include "data.h"

using namespace std;

void readKMeans(string inputFile, vector<vector<double>>& points, int& n, int& d, int& k, int& maxIter, double& tol) {
    ifstream file(inputFile);
    if (!file.is_open()) {
        cerr << "Error: Could not open " << inputFile << endl;
        exit(1);
    }
    
    file >> n >> d >> k;
    points.assign(n, vector<double>(d, 0.0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            file >> points[i][j];
        }
    }
    
    string dummy;
    file >> dummy >> maxIter;
    file >> dummy >> tol;
    file.close();
}

void kMeans(int n, int d, int k, int maxIter, double tol, const vector<vector<double>>& points, vector<int>& assignments, vector<vector<double>>& centroids, int& actualIter, bool& converged, double& wcss) {
    
    assignments.assign(n, -1);
    centroids.assign(k, vector<double>(d, 0.0));
    for (int i = 0; i < k; i++) {
        centroids[i] = points[i];
    }
    
    converged = false;
    actualIter = 0;
    
    while (actualIter < maxIter) {
        bool assignmentChanged = false;
        for (int i = 0; i < n; i++) {
            double minDist = numeric_limits<double>::max();
            int bestCluster = -1;
            
            for (int c = 0; c < k; c++) {
                double distSq = 0.0;
                for (int j = 0; j < d; j++) {
                    double diff = points[i][j] - centroids[c][j];
                    distSq += diff * diff;
                }
                if (distSq < minDist) {
                    minDist = distSq;
                    bestCluster = c;
                }
            }
            if (assignments[i] != bestCluster) {
                assignments[i] = bestCluster;
                assignmentChanged = true;
            }
        }
        vector<vector<double>> newCentroids(k, vector<double>(d, 0.0));
        vector<int> counts(k, 0);
        for (int i = 0; i < n; i++) {
            int c = assignments[i];
            counts[c]++;
            for (int j = 0; j < d; j++) {
                newCentroids[c][j] += points[i][j];
            }
        }
        double maxShift = 0.0;
        for (int c = 0; c < k; c++) {
            if (counts[c] > 0) {
                double shiftSq = 0.0;
                for (int j = 0; j < d; j++) {
                    newCentroids[c][j] /= counts[c];
                    double diff = newCentroids[c][j] - centroids[c][j];
                    shiftSq += diff * diff;
                }
                maxShift = max(maxShift, sqrt(shiftSq));
                centroids[c] = newCentroids[c];
            }
        }
        actualIter++;
        if (maxShift <= tol || !assignmentChanged) {
            converged = true;
            break;
        }
    }
    wcss = 0.0;
    for (int i = 0; i < n; i++) {
        int c = assignments[i];
        for (int j = 0; j < d; j++) {
            double diff = points[i][j] - centroids[c][j];
            wcss += diff * diff;
        }
    }
}