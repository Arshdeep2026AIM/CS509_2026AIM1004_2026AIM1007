#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Internal K-Means implementation to compute the exact expected outputs
void computeKMeans(int n, int d, int k, int maxIter, double tol, const vector<vector<double>>& points, 
                   vector<int>& assignments, vector<vector<double>>& centroids, 
                   int& actualIter, bool& converged, double& wcss) {
    assignments.assign(n, -1);
    centroids.assign(k, vector<double>(d, 0.0));
    for (int i = 0; i < k; i++) centroids[i] = points[i];
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
            for (int j = 0; j < d; j++) newCentroids[c][j] += points[i][j];
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

int main() {
    // Configuration for km_01, km_02, km_03, km_04 based on the assignment rules
    struct Config { string id; int n; int d; int k; };
    vector<Config> configs = {
        {"01", 100, 2, 3},
        {"02", 1000, 2, 5},
        {"03", 10000, 5, 8},
        {"04", 100000, 5, 10}
    };

    mt19937 gen(42); // Fixed seed for reproducibility
    uniform_real_distribution<double> dist(0.0, 100.0);

    int maxIter = 300;
    double tol = 0.0001;

    for (const auto& cfg : configs) {
        cout << "Generating test case km_" << cfg.id << " (N=" << cfg.n << ")...\n";
        
        // 1. Generate random points
        vector<vector<double>> points(cfg.n, vector<double>(cfg.d));
        for (int i = 0; i < cfg.n; i++) {
            for (int j = 0; j < cfg.d; j++) {
                points[i][j] = dist(gen);
            }
        }

        // 2. Write the input test file
        string testFile = "tests/km_" + cfg.id + ".txt";
        ofstream tOut(testFile);
        tOut << cfg.n << " " << cfg.d << " " << cfg.k << "\n";
        tOut << fixed << setprecision(6);
        for (int i = 0; i < cfg.n; i++) {
            for (int j = 0; j < cfg.d; j++) {
                tOut << points[i][j] << (j == cfg.d - 1 ? "" : " ");
            }
            tOut << "\n";
        }
        tOut << "MAX_ITERATIONS " << maxIter << "\n";
        tOut << "TOLERANCE " << tol << "\n";
        tOut.close();

        // 3. Compute expected output
        vector<int> assignments;
        vector<vector<double>> centroids;
        int actualIter;
        bool converged;
        double wcss;
        computeKMeans(cfg.n, cfg.d, cfg.k, maxIter, tol, points, assignments, centroids, actualIter, converged, wcss);

        // 4. Write the expected output file
        string expFile = "outputs/expected_km_" + cfg.id + ".txt";
        ofstream eOut(expFile);
        eOut << "Algorithm: K-Means Clustering\n";
        eOut << "K: " << cfg.k << "\n";
        eOut << "Point assignments:\n";
        for (int i = 0; i < cfg.n; i++) {
            eOut << i << " " << assignments[i] << "\n";
        }
// ... (inside the file writing block)
        eOut << "Final centroids:\n";
        eOut << fixed << setprecision(2);
        for (int c = 0; c < cfg.k; c++) {
            eOut << c << ":";
            for (int j = 0; j < cfg.d; j++) {
                eOut << " " << centroids[c][j];
            }
            eOut << "\n";
        }
        
        // Lower precision to 4 here too!
        eOut << fixed << setprecision(2); 
        eOut << "WCSS: " << wcss << "\n";
        eOut << "Iterations: " << actualIter << "\n";
        eOut << "Converged: " << (converged ? "true" : "false") << "\n";
        eOut.close();
    }

    cout << "\nSuccess! Generated 4 input files in tests/ and 4 expected files in outputs/.\n";
    return 0;
}