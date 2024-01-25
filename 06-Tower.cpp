#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int top[n];
  int count = 1;
  top[0] = a[0];

  for (int i = 1; i < n; i++) {
    int low = 0, high = count - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (a[i] < top[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (low == count) {
      count++;
    }
    top[low] = a[i];
  }

  cout << count << endl;

  return 0;
}
