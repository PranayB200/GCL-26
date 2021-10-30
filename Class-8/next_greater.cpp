#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater(vector<int> arr) {
    int n = arr.size();

    vector<int> res(n);
    stack<int> helper;

    for (int i = n - 1; i >= 0; i--) {

        while (!helper.empty() and helper.top() <= arr[i]) {
            helper.pop();
        }

        if (helper.empty()) {
            res[i] = -1;
        }
        else {
            res[i] = helper.top();
        }

        helper.push(arr[i]);
    }

    return res;
}

int main() {

    vector<int> res = next_greater({6, 8, 0, 1, 3});
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    
}