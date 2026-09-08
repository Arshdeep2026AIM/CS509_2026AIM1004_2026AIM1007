#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "../src/data.h"
#include "../../utility/testing_utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    int choice;
    string runMode = "ALL";
    bool isBenchmarkMode = false;
    if (argc >= 3) {
        choice = stoi(argv[1]);
        runMode = argv[2];
        if (argc >= 4 && string(argv[3]) == "--test") {
            isBenchmarkMode = true;
        }
    } else {
        cout << "=================================================\n";
        cout << "      CS509 Assignment 4 Automated Driver        \n";
        cout << "=================================================\n\n";
        cout << "Select Algorithm:\n";
        cout << "1. K-Means Clustering\n";
        cout << "2. FastMap\n";
        cout << "Enter choice (1-2): ";
        cin >> choice;
        char modeFlag;
        cout << "Run in Benchmark mode? (y/n - averages 5 runs): ";
        cin >> modeFlag;
        if (modeFlag == 'y' || modeFlag == 'Y') isBenchmarkMode = true;
        cout << "\n";
    }
    
    if (choice < 1 || choice > 2) {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }
    
    int iterations = isBenchmarkMode ? 5 : 1;
    
    if (choice == 1) {
        vector<string> testCases = (runMode == "ALL") ? vector<string>{"01", "02", "03", "04"} : vector<string>{runMode};
        for (const string& testNum : testCases) {
            cout << ">>> Running Test Case: km_" << testNum << " <<<\n";
            string testFilePath = "tests/km_" + testNum + ".txt";
            string outFilePath = "outputs/output_km_" + testNum + ".txt";

            int n, d, k, maxIter;
            double tol;
            vector<vector<double>> points;
            
            readKMeans(testFilePath, points, n, d, k, maxIter, tol);
            
            vector<int> assignments;
            vector<vector<double>> centroids;
            int actualIter;
            bool converged;
            double wcss;
            
            auto algoLambda = [&]() {
                kMeans(n, d, k, maxIter, tol, points, assignments, centroids, actualIter, converged, wcss);
            };
            
            double avgTimeMs = measureAverageExecutionTime(algoLambda, iterations);
            ofstream outFile(outFilePath);
            if (outFile.is_open()) {
                outFile << "Algorithm: K-Means Clustering\n";
                outFile << "K: " << k << "\n";
                outFile << "Point assignments:\n";
                for (int i = 0; i < n; i++) {
                    outFile << i << " " << assignments[i] << "\n";
                }
                outFile << "Final centroids:\n";
                outFile << fixed << setprecision(2);
                for (int c = 0; c < k; c++) {
                    outFile << c << ":";
                    for (int j = 0; j < d; j++) {
                        outFile << " " << centroids[c][j];
                    }
                    outFile << "\n";
                }
                outFile << fixed << setprecision(2); 
                outFile << "WCSS: " << wcss << "\n";
                outFile << "Iterations: " << actualIter << "\n";
                outFile << "Converged: " << (converged ? "true" : "false") << "\n";
                outFile << "\n" << METRICS_ESCAPE_TOKEN << "\n"; 
                outFile << "Execution time: " << avgTimeMs << " ms\n";
                if (isBenchmarkMode) outFile << "(Averaged over " << iterations << " runs)\n";
                outFile.close();
            }
            cout << "--- K-Means TEST SUMMARY (km_" << testNum << ") ---\n";
            string expectedFilePath = "outputs/expected_km_" + testNum + ".txt";
            if (compareFilesWithEscape(outFilePath, expectedFilePath)) {
                cout << "Status: PASSED\n";
            } else {
                cout << "Status: FAILED (Check " << outFilePath << " against expected)\n";
            }
            cout << (isBenchmarkMode ? "Avg Time: " : "Time: ") << avgTimeMs << " ms\n";
            cout << "=================================================\n\n";
        }
    }
    else if (choice == 2) {
        vector<string> testCases = (runMode == "ALL") ? vector<string>{"10", "100", "1000", "10000"} : vector<string>{runMode};
        for (const string& testNum : testCases) {
            cout << ">>> Running Test Case: fm_" << testNum << " <<<\n";
            string testFilePath = "tests/fm_" + testNum + ".txt";
            string outFilePath = "outputs/output_fm_" + testNum + ".txt";

            int n, k;
            vector<vector<double>> distanceMat;
            readFastMap(testFilePath, distanceMat, n, k);
            auto algoLambda = [&]() {
                fastMap(n, k, distanceMat);
            };
            double avgTimeMs = measureAverageExecutionTime(algoLambda, iterations);

            ofstream outFile(outFilePath);
            if (outFile.is_open()) {
                outFile << "Algorithm: FastMap\n";
                outFile << "Target dimensions: " << k << "\n";
                outFile << "Pivots per dimension:\n";
                for (int i = 0; i < k; i++) {
                    outFile << "Dim " << i+1 << ": " << pivots[i][0] << " " << pivots[i][1] << endl;
                }
                outFile << "Object coordinates:\n";
                outFile << fixed << setprecision(6);
                for (int i = 0; i < n; i++) {
                    outFile << i << ":";
                    for (int j = 0; j < k; j++) {
                        outFile << " " << result[i][j];
                    }
                    outFile << endl;
                }
                outFile << "\n" << METRICS_ESCAPE_TOKEN << "\n";
                outFile << "Execution time: " << avgTimeMs << " ms\n";
                if (isBenchmarkMode) outFile << "(Averaged over " << iterations << " runs)\n";
                outFile.close();
            }

            cout << "--- FastMap TEST SUMMARY (fm_" << testNum << ") ---\n";
            string expectedFilePath = "outputs/expected_fm_" + testNum + ".txt";
            if (compareFilesWithEscape(outFilePath, expectedFilePath)) {
                cout << "Status: PASSED\n";
            } else {
                cout << "Status: FAILED (Check " << outFilePath << " against expected)\n";
            }
            cout << (isBenchmarkMode ? "Avg Time: " : "Time: ") << avgTimeMs << " ms\n";
            cout << "=================================================\n\n";
        }
    }

    return 0;
}