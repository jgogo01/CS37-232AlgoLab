#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Bottom-Up LIS
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    return *max_element(dp.begin(), dp.end());
}


int main() {
  vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
  int n = arr.size();
  
  int len = lis(arr);
  cout << "Length of LIS: " << len << endl;
  return 0;
}
