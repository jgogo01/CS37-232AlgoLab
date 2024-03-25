#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive LIS
int lis(vector<int>& arr, int n) {
    if (n == 1)
        return 1;
    int res, max_ending_here = 1;
    for (int i = 1; i < n; i++) {
        res = lis(arr, i);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
    return max_ending_here;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = arr.size();

    // Recursive LIS
    cout << "LIS Recursive: " << lis(arr, n) << endl;

    return 0;
}
