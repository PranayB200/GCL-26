#include<bits/stdc++.h>
using namespace std;

int kth_largest(vector<int> arr, int k) {

    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    // Step-1: Push the first K elements into the min heap.
    for (int i = 0; i < k; i++) {
        min_heap.push(arr[i]);
    }

    // Step-2: Pushing and popping after checking.
    for (int i = k; i < n; i++) {
        if (arr[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(arr[i]);
        }
    }

    return min_heap.top();
}

int main() {

    cout << kth_largest({3, 5, 4, 2, 9}, 3) << endl;
    cout << kth_largest({4, 3, 7, 6, 5}, 5) << endl;
}