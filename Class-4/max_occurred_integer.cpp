#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n + maxx)
Auxiliary Space: O(maxx)
Space Complexity: O(n + maxx)

Space complexity: Input space + Auxiliary space + Output Space
    Input Space = O(n)
    Aux space: O(maxx)
    Output Space: O(1)
*/

int max_occurred_integer(vector<int> L, vector<int> R) {    

    int maxx = R[0];
    for (int i = 1; i < R.size(); i++) {
        maxx = max(maxx, R[i]);
    }

    // Prefix Sum Technique.
    vector<int> cumm_freq(maxx + 2, 0);
    for (int i = 0; i < L.size(); i++) {
        cumm_freq[L[i]]++;
        cumm_freq[R[i] + 1]--;
    }

    // Computing the prefix sum array.
    for (int i = 1; i < cumm_freq.size(); i++) {
        cumm_freq[i] += cumm_freq[i - 1];
    }

    int max = cumm_freq[0];
    int result = 0;

    for (int i = 1; i < maxx + 1; i++) {
        if (max < cumm_freq[i]) {
            max = cumm_freq[i];
            result = i;
        }
    }
    
    return result;
}

int main() {
    cout << max_occurred_integer({2, 1, 3}, {5, 3, 9});
}