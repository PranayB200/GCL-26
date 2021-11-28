#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<vector<int>> memo;

int nCr_util(int n, int r) {

    if (n < r) {
        return 0;
    }
    if (r == 0 or n == r) {
        return 1;
    }
    if (memo[n][r] != -1) {
        return memo[n][r];
    }

    return memo[n][r] = (nCr_util(n - 1, r - 1) + nCr_util(n - 1, r)) % mod;
}

int nCr(int n, int r) {
    memo = vector<vector<int>> (n + 1, vector<int> (r + 1, -1));
    return nCr_util(n, r);
}

int main() {
    cout << nCr(100, 50) << endl;
}