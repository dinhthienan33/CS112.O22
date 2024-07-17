#include <vector>
#include <iostream>
int main(){
// Assuming jobs is defined and is a 2D vector
std::vector<std::vector<int>> jobs = {{1, 2, 3,88}, {4, 5, 6,9}, {7, 8, 9,99}};

// Get the dimensions of jobs
int n = jobs.size();
int m = jobs[0].size();

// Create a 2D vector with dimensions m x n
std::vector<std::vector<int>> transposed(m, std::vector<int>(n));

// Transpose the jobs matrix
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        transposed[j][i] = jobs[i][j];
    }
}
for (const auto &row : transposed) {
        for (const auto &elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

}