#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

int n;
long long k, x[MAX_N];

long long area(long long l, long long r) {
    long long b = r - l + 1;
    if (b <= 0) return 0;
    if (b % 2 != 0) return (b + 1) * (b + 1) / 4;
    return b * (b + 2) / 4;
}

long long calculate(long long T) {
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += area(x[i] - T, x[i] + T);
        sum -= area(x[i + 1] - T, x[i] + T);
    }
    sum += area(x[n] - T, x[n] + T);
    return sum;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);

    long long first = 0, last = 400000000, ans = 0;
    while (first <= last) {
        long long mid = (first + last) / 2;
        long long cnt = calculate(mid);

        if (cnt >= k) {
            last = mid - 1;
            ans = mid;
        } else {
            first = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
