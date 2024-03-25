#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two matrices recursively
vector<vector<int>> matrixMultiplicationRecursive(const vector<vector<int>>& A, const vector<vector<int>>& B, int i, int j, int k) {
    if (i == A.size())
        return vector<vector<int>>(A.size(), vector<int>(B[0].size(), 0)); // Base case: return a zero matrix

    if (j == B[0].size()) {
        vector<vector<int>> result = matrixMultiplicationRecursive(A, B, i + 1, 0, 0); // Move to the next row of A
        return result;
    }

    if (k == B.size()) {
        vector<vector<int>> result = matrixMultiplicationRecursive(A, B, i, j + 1, 0); // Move to the next column of B
        return result;
    }

    vector<vector<int>> result = matrixMultiplicationRecursive(A, B, i, j, k + 1); // Recursive call with incremented k

    result[i][j] += A[i][k] * B[k][j]; // Perform matrix multiplication

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices A and B
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}}; // 2x3 matrix
    vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}}; // 3x2 matrix

    // Perform matrix multiplication recursively
    vector<vector<int>> C = matrixMultiplicationRecursive(A, B, 0, 0, 0);

    // Print the result matrix
    cout << "Result matrix (A x B):" << endl;
    printMatrix(C);

    return 0;
}
