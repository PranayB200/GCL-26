#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n*n)
Auxiliary Space: O(1)
Space Complexity: O(n)

Space complexity: Input space + Auxiliary space + Output Space
    Input Space = O(n)
    Aux space: O(1)
    Output Space: O(1)
*/

bool check_triplet_sum(vector<int> arr, int X) {

    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {

        // Two-pointer based approach on arr[i + 1 .... n - 1]
        int low = i + 1, high = n - 1;
        int sum_to_find = X - arr[i];

        while (low < high) {
            if (arr[low] + arr[high] == sum_to_find) {
                return true;
            }
            if (arr[low] + arr[high] > sum_to_find) { // Decrease the current pair sum.
                high--;
            }
            else { // Increase the current pair sum.
                low++;
            }
        }
    }

    return false;
}

int main() {
    cout << check_triplet_sum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << check_triplet_sum({1, 4, 45, 6, 10, 8}, 45) << endl;
}


/*
HOMEWORK

    check_k_element_sum(arr, k, X):
        Returns true if there exists k elements in the array that sums up to X.
        Return false otherwise.

    Expected TC: O(n^(k-1))
*/