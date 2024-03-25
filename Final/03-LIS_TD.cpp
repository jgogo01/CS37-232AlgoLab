#include <vector>
#include <iostream>
using namespace std;

// Top-Down LIS
int lis(vector<int>& arr, int n, vector<int>& dp) {
    if (dp[n] != -1)
        return dp[n];
    dp[n] = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[n])
            dp[n] = max(dp[n], 1 + lis(arr, i, dp));
    }
    return dp[n];
}

int main() {
  vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
  int n = arr.size();
  
  vector<int> dp_td(n, -1);
  int len = lis(arr, n - 1, dp_td);
  cout << "Length of LIS: " << len << endl;
  return 0;
}
