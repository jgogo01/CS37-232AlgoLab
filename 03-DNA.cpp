#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;
    int count = 1;
    int maxCount = 1;
    char currChar = x[0];

    for (int i = 1; i < x.length(); i++) {
        if (currChar == x[i]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
            }
            count = 1;
            currChar = x[i];
        }
    }
    
    if (count > maxCount) {
        maxCount = count;
    }

    cout << maxCount << endl;
    return 0;
}