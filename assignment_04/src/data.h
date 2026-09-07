#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>

using namespace std;

extern vector<vector<double>> result;
extern vector<vector<int>> pivots;

void readFastMap(string inputFile, vector<vector<double>>& dist, int& n, int& k);
double getDistance(int pointA, int pointB, int currDim, vector<vector<double>>& distSq);
int chooseDistantObject(vector<vector<double>>& distSq, int n, int pointA, int pointB); 
void fastMap(int& n, int& k, vector<vector<int>>& dist);

#endif