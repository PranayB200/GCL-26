#include <bits/stdc++.h>
using namespace std;



int max_subarray_sum_On(vector<int> arr) {
    
    int n = arr.size();

    vector<int> max_till_here(n);
    max_till_here[0] = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {

        // if (max_till_here[i-1] > 0) {
        //     max_till_here[i] = max_till_here[i - 1] + arr[i];
        // }
        // else {
        //     max_till_here[i] = arr[i];
        // }

        max_till_here[i] = max(0, max_till_here[i - 1]) + arr[i];

        result = max(result, max_till_here[i]);
    }

    return result;
}

int max_subarray_sum_O1(vector<int> arr) {
    
    int n = arr.size();

    // vector<int> max_till_here(n);
    int max_till_previous = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        
        // max_till_here => mth[i]
        // max_till_previous => mth[i - 1] 
        int max_till_here = max(0, max_till_previous) + arr[i];

        result = max(result, max_till_here);
        max_till_previous = max_till_here;
    }

    return result;
}

int main() {
    cout << max_subarray_sum_O1({1, 2, -1, 1, 3, -2});
}