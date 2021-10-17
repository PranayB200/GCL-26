#include <bits/stdc++.h>
using namespace std;

vector<int> fact;

void precompute(int n) {

    fact = vector<int> (n + 1);
    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

int lexicographic_rank(string s) {

    int n = s.length();
    precompute(n - 1);

    string s2 = s;
    sort(s2.begin(), s2.end());

    /*
    HW => Convert O(n*n) solution to O(n). Try to find 'count' at each step using O(1) time.

    HINT:
        // "view" => "eivw"
        // rank[e] = 0
        // rank[i] = 1
        // rank[v] = 2
        // rank[w] = 3
    */

    int res = 0;
    for (int i = 0; i < n - 1; i++) {

        // Count the number of characters smaller than s[i]
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (s2[j] == s[i]) {
                s2[j] = '#';
                break;
            }
            if (s2[j] != '#') count++;
        }

        /*
            i = 0 => string of length n
            i = 1 => string of length n - 1
            i = 2 => string of length n - 2
            ....
        */
        res += (count * fact[n - i - 1]);
    }

    return res + 1;
}

int main() {
    
    cout << lexicographic_rank("bdac") << endl;
    cout << lexicographic_rank("view") << endl;
}
