#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------
vector<int> memo;
int fib_top_down_util(int n) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fib_top_down_util(n - 1) + fib_top_down_util(n - 2);
    return memo[n];
}

int fib_top_down(int n) {
    memo = vector<int> (n + 1, -1);
    return fib_top_down_util(n);
}
// ------------------------------------------------------------------------

int fib_bottom_up(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}



int main() {

    cout << fib_top_down(6) << endl;
    cout << fib_bottom_up(6) << endl;
}