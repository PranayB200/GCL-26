#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------------------------------

vector<vector<int>> memo;

// Returns the maximum value we can achieve with the first n number of items considering that
// the remaining capacity of knapsack is W.
int max_value_util(vector<int> &vals, vector<int> &wts, int n, int W) {

    // If no items are left or W == 0.
    if (n == 0 or W == 0) {
        return 0;
    }
    if (memo[n][W] != -1) {
        return memo[n][W];
    }

    // Discarding the current item.
    int res = max_value_util(vals, wts, n - 1, W); 

    // Trying to consider the current item.
    if (wts[n - 1] <= W) {
        res = max(res, vals[n - 1] + max_value_util(vals, wts, n - 1, W - wts[n - 1]));
    }

    return memo[n][W] = res;
}

int max_value(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    memo = vector<vector<int>> (n + 1, vector<int> (W + 1, -1));
    return max_value_util(vals, wts, n, W);
}

// ----------------------------------------------------------------------------------------

int max_value_bottom_up(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1));

    // If n == 0, or W == 0, dp[n][W] should be 0. 
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {

            dp[i][j] = dp[i - 1][j];
            if (wts[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], vals[i - 1] + dp[i - 1][j - wts[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int main() {

    cout << max_value({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value({60, 100, 120}, {10, 20, 50}, 50) << endl;

    cout << max_value_bottom_up({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value_bottom_up({60, 100, 120}, {10, 20, 50}, 50) << endl;
}