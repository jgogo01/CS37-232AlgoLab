#include <iostream>
#include <string>
using namespace std;

int calculateGCD(int x, int y) {
    int gcd;
    for(int i = 1; i <= x && i <= y; i++) {
        if(x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;

    for (int x = a; x <= b; x++) {
        int gcd = calculateGCD(x, sumOfDigits(x));
        if (gcd != 1) {
            cout << x << " ";
        }
    }

    return 0;
}