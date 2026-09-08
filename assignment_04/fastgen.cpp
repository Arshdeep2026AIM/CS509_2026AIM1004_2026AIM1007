#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>
#include <iomanip>
#include <string>

// Structure to define test case parameters
struct TestCaseSpec {
    int N;               // Number of data points/objects
    int K;               // Target dimensionality
    std::string filename;// Output text file name
};

// Generates a valid metric distance matrix from synthetic N-dimensional points
void generate_fastmap_file(int N, int K, const std::string& filename) {
    std::cout << "Generating " << filename << " (N = " << N << ", K = " << K << ")..." << std::flush;

    // Use a fixed seed for reproducible test datasets across runs
    std::mt19937_64 rng(42 + N);
    std::uniform_real_distribution<double> dist(0.0, 100.0);

    // 1. Generate N points in a 5D synthetic feature space
    int feature_dims = 5;
    std::vector<std::vector<double>> points(N, std::vector<double>(feature_dims));
    for (int i = 0; i < N; ++i) {
        for (int d = 0; d < feature_dims; ++d) {
            points[i][d] = dist(rng);
        }
    }

    // 2. Compute symmetric pairwise Euclidean distance matrix
    std::vector<std::vector<double>> matrix(N, std::vector<double>(N, 0.0));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double sum_sq = 0.0;
            for (int d = 0; d < feature_dims; ++d) {
                double diff = points[i][d] - points[j][d];
                sum_sq += diff * diff;
            }
            double d = std::sqrt(sum_sq);
            matrix[i][j] = d;
            matrix[j][i] = d;
        }
    }

    // 3. Write to file matching the exact standard format in a.txt
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "\nError opening file " << filename << " for writing!" << std::endl;
        return;
    }

    // Standard header line: N K
    outfile << N << " " << K << "\n";

    // Standard matrix rows: N x N matrix with 1 decimal precision
    outfile << std::fixed << std::setprecision(1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            outfile << matrix[i][j] << (j == N - 1 ? "" : " ");
        }
        outfile << "\n";
    }

    outfile.close();
    std::cout << " Done!" << std::endl;
}

int main() {
    // Test case specifications as requested
    std::vector<TestCaseSpec> tests = {
        {10000, 3, "tests/fm_10000.txt"}
    };

    std::cout << "========================================\n";
    std::cout << " FastMap Test File Generator\n";
    std::cout << "========================================\n\n";

    for (const auto& test : tests) {
        generate_fastmap_file(test.N, test.K, test.filename);
    }

    std::cout << "\nAll FastMap test files generated successfully!" << std::endl;
    return 0;
}