#include<bits/stdc++.h>
using namespace std;

vector<int> merge_k_sorted_arrays(vector<vector<int>> arr) {

    int k = arr.size();

    // pair<int, pair<int,int>> // {-value, {i, j}}
    priority_queue<pair<int, pair<int,int>>> min_heap; // Hacky min heap.

    // Push the 0th element of all K arrays.
    for (int i = 0; i < k; i++) {
        min_heap.push({-arr[i][0], {i, 0}});
    }

    vector<int> result;
    while (!min_heap.empty()) {

        auto current = min_heap.top();
        min_heap.pop();

        int value = -current.first;

        // current.second = {i, j}
        // Therefore, current.second.first = i and current.second.second = j.
        int i = current.second.first;
        int j = current.second.second;

        result.push_back(value);
        if (j + 1 < k) {
            min_heap.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> res = merge_k_sorted_arrays({{1, 2, 3},
                                             {4, 5, 6},
                                             {7, 8, 9}});

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res2 = merge_k_sorted_arrays({{1, 5, 10},
                                              {2, 7, 8},
                                              {0, 3, 5}});

    for (int i : res2) {
        cout << i << " ";
    }
    cout << endl;
}