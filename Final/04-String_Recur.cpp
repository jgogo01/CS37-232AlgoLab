#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int stringAlignment(string str1, string str2, int m, int n) {
    // Base case: if any of the strings is empty, return the length of the other string
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    // If the last characters of the strings match, no extra operation is needed
    if (str1[m - 1] == str2[n - 1])
        return stringAlignment(str1, str2, m - 1, n - 1);

    // If the last characters are different, consider all operations (insert, remove, replace)
    return 1 + min(stringAlignment(str1, str2, m, n - 1),         // Insert
                   min(stringAlignment(str1, str2, m - 1, n),     // Remove
                       stringAlignment(str1, str2, m - 1, n - 1) // Replace
                       )
               );
}

int main() {
    string str1 = "kitten";
    string str2 = "sitting";

    cout << "Minimum operations required: " << stringAlignment(str1, str2, str1.length(), str2.length()) << endl;

    return 0;
}
