#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two matrices
vector<vector<int>> matrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size();    // Number of rows in A
    int n = A[0].size(); // Number of columns in A (same as rows in B)
    int p = B[0].size(); // Number of columns in B

    // Initialize the result matrix with size m x p and fill it with 0s
    vector<vector<int>> C(m, vector<int>(p, 0));

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
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

    // Perform matrix multiplication
    vector<vector<int>> C = matrixMultiplication(A, B);

    // Print the result matrix
    cout << "Result matrix (A x B):" << endl;
    printMatrix(C);

    return 0;
}
