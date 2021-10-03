#include <bits/stdc++.h>
using namespace std;

    /*
    Brute force:    Iterate to find 1, 2, 3 ... n one by one. 
                    TC: O(n*n), Auxiliary space: O(1)
    
    Map-based solution: Store the occurrences of all the elements => O(n)
                        One by one check if [1, n] are present or not. => O(n)
                    TC : O(n), Auxiliary space: O(n)
    */

//    [1, n + 1] 
//    [1, n]

    /*
    Bucketing technique.
    Since the answer will be in range [1, n+1], we will use the index-i of the array to
    check whether the element i + 1 is present in the array or not.
    */
    // indexes:    0   1   2   3   4
    // array:      -1 -4  -3  -2   1   => Output = 5.

    // indexes:    0   1   2   3   4
    // array:      -7  -7  1   7   2   => Output = 3.

    // Replace all the elements outside the range [1, n+1] with n+2.

    /*
    Bucketing technique solution:
        TC: O(n), Aux Space: O(1)
    */

int smallest_positive_missing(vector<int> arr) {

    int n = arr.size();
    // Answer will be in range [1, n + 1].

    // Step-1: Remove all the out-of-range elements.
    for (int i = 0; i < n; i++) {
        if (arr[i] < 1 or arr[i] > n) {
            arr[i] = n + 1;
        }
    }

    // Step-2: Bucketing
    for (int i = 0; i < n; i++) {

        // Bucket for abs(arr[i]) is the index = (abs(arr[i]) - 1).
        if (abs(arr[i]) >= 1 and abs(arr[i]) <= n and arr[abs(arr[i]) - 1] > 0) {
            arr[abs(arr[i]) - 1] *= -1;
        }
    }

    // Step-3: Find the first positive missing number.
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {

    cout << smallest_positive_missing({0, 10, 1, 3, -20});
}