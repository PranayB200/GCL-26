#include <bits/stdc++.h>
using namespace std;

bool check_zero_sum_subarray(vector<int> arr) {

    unordered_map<int, bool> prefix_sum;
    int sum = 0;

    prefix_sum[0] = true;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (prefix_sum[sum]) {
            return true;
        }
        prefix_sum[sum] = true;
    }

    return false;
}

// Return the number of subarrays with sum = 0.
int count_zero_sum_subarray(vector<int> arr) {

    unordered_map<int, int> prefix_sum;
    int sum = 0;

    int result = 0;

    prefix_sum[0] = 1;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (prefix_sum.find(sum) != prefix_sum.end()) {
            result += prefix_sum[sum];
        }
        prefix_sum[sum]++;
    }

    return result;
}

int main() {
    cout << check_zero_sum_subarray({4, 2, -3, 1, 6}) << endl;
    cout << check_zero_sum_subarray({4, -4, 1, 2}) << endl;
    cout << check_zero_sum_subarray({4, 2, 1, 4}) << endl;

    cout << count_zero_sum_subarray({1, 1, -1, 0, 4, -4, 1});                                    
}