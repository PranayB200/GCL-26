#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n*n)
Auxiliary Space: O(1)
Space Complexity: O(n)

Space complexity: Input space + Auxiliary space + Output Space
    Input Space = O(n)
    Aux space: O(1)
    Output Space: O(n)
*/
vector<int> array_prod_except_self_brute(vector<int> nums) {

    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        ans[i] = 1;

        // ans[i] = product of all elements except nums[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                ans[i] = ans[i] *nums[j];
            }
        }
    }

    return ans;
}

/*
Time Complexity: O(n)
Auxiliary Space: O(n)
Space Complexity: O(n)

Space complexity: Input space + Auxiliary space + Output Space
    Input Space = O(n)
    Aux space: O(n)
    Output Space: O(n)
*/
vector<int> array_prod_except_self(vector<int> nums) {

    int n = nums.size();
    vector<int> pref_prod(n);
    vector<int> suff_prod(n);

    pref_prod[0] = 1;
    for (int i = 1; i < n; i++) {
        pref_prod[i] = pref_prod[i - 1] * nums[i - 1];
    }

    suff_prod[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suff_prod[i] = suff_prod[i + 1] * nums[i + 1];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = pref_prod[i] * suff_prod[i];
    }

    return ans;
}


int main() {
    vector<int> ans = array_prod_except_self_brute({4, 5, 1, 8, 2});
    for (int i : ans) {
        cout << i << " ";
    }

    cout << endl;

    ans = array_prod_except_self({4, 5, 1, 8, 2});
    for (int i : ans) {
        cout << i << " ";
    }
}