#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>

using namespace std;

extern vector<vector<double>> result;
extern vector<vector<int>> pivots;

void readFastMap(string inputFile, vector<vector<double>>& dist, int& n, int& k);
double getDistance(int pointA, int pointB, int& currDim, vector<vector<double>>& distSq);
int chooseDistantObject(int source, int& n, int& currDim, vector<vector<double>>& distSq);
void fastMap(int& n, int& k, vector<vector<double>>& dist);
void readKMeans(std::string inputFile, std::vector<std::vector<double>>& points, int& n, int& d, int& k, int& maxIter, double& tol);
void kMeans(int n, int d, int k, int maxIter, double tol, const std::vector<std::vector<double>>& points, std::vector<int>& assignments, std::vector<std::vector<double>>& centroids, int& actualIter, bool& converged, double& wcss);
#endif