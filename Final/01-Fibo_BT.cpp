#include <iostream>
using namespace std;

int FiboTopDown(int n, int lookup[]) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (lookup[n] == -1) { // Check if value already calculated
    lookup[n] = FiboTopDown(n - 1, lookup) + FiboTopDown(n - 2, lookup);
  }
  return lookup[n];
}

int main() {
  int n = 6;
  int lookup[n + 1];
  fill(lookup, lookup + n + 1, -1);
  cout << "Top-Down: " << FiboTopDown(n, lookup) << endl;

  return 0;
}
