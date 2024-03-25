#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int stringAlignment(const string& str1, const string& str2, int mismatchPenalty, int gapPenalty) {
    int n = str1.length();
    int m = str2.length();

    // Create DP table and initialize with 0
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize first row and column
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + gapPenalty;
    }
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = dp[0][j - 1] + gapPenalty;
    }

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : mismatchPenalty;
            dp[i][j] = min({dp[i - 1][j - 1] + cost, dp[i - 1][j] + gapPenalty, dp[i][j - 1] + gapPenalty});
        }
    }

    // Return the final score
    return dp[n][m];
}

int main() {
    string str1 = "kitten";
    string str2 = "sitting";
    int mismatchPenalty = 1;
    int gapPenalty = 1;

    int alignmentScore = stringAlignment(str1, str2, mismatchPenalty, gapPenalty);
    cout << "Alignment score: " << alignmentScore << endl;

    return 0;
}
