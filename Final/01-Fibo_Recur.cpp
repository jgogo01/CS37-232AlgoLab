#include <iostream>
using namespace std;

int FiboRecursive(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return FiboRecursive(n - 1) + FiboRecursive(n - 2);
}

int main() {
  int n = 6;
  cout << "Recursive: " << FiboRecursive(n) << endl;
  return 0;
}
