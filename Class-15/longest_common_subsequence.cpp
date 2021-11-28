#include<bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------
vector<vector<int>> memo;

// Considering s1[i ... n-1] and s2[j ... m-1].
int lcs_util(string &s1, string &s2, int i, int j) {

    if (i == s1.length() or j == s2.length()) { // If any of the strings become empty.
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int res = max(lcs_util(s1, s2, i + 1, j), lcs_util(s1, s2, i, j + 1));
    if (s1[i] == s2[j]) {
        res = max(res, 1 + lcs_util(s1, s2, i + 1, j + 1));
    }

    return memo[i][j] = res;
}

int lcs(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    memo = vector<vector<int>> (n, vector<int> (m, -1));

    return lcs_util(s1, s2, 0, 0);
}
// ---------------------------------------------------------------

int lcs_bottom_up(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

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