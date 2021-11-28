#include<bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------
vector<vector<int>> memo;

// Considering s1[0 ... n-1] and s2[0 ... m-1].
int lcs_util(string &s1, string &s2, int n, int m) {

    if (n == 0 or m == 0) { // If any of the strings become empty.
        return 0;
    }
    if (memo[n][m] != -1) {
        return memo[n][m];
    }

    int res = max(lcs_util(s1, s2, n - 1, m), lcs_util(s1, s2, n, m - 1));
    if (s1[n - 1] == s2[m - 1]) {
        res = max(res, 1 + lcs_util(s1, s2, n - 1, m - 1));
    }

    return memo[n][m] = res;
}

int lcs(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    memo = vector<vector<int>> (n + 1, vector<int> (m + 1, -1));

    return lcs_util(s1, s2, n, m);
}
// ---------------------------------------------------------------

int lcs_bottom_up(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // dp[i][j] == LCS(s1[0 ... i - 1], s2[0 ... j - 1])
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Looking at the base-case of top-down, filling some values in the Dp table.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {

    cout << lcs("abc", "acd") << endl;
    cout << lcs_bottom_up("abc", "acd") << endl;
}