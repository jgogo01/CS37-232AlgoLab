#include <iostream>
using namespace std;

int FiboButtomUp(int n) {
  int Fibo[n + 1]; // Allocate enough space
  Fibo[0] = 0;
  Fibo[1] = 1;
  for (int i = 2; i <= n; i++) {
    Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
  }
  return Fibo[n];
}

int main() {
  int n = 6;
  int lookup[n + 1];
  fill(lookup, lookup + n + 1, -1);
  cout << "Top-Down: " << FiboButtomUp(n) << endl;

  return 0;
}
