#include <bits/stdc++.h>
using namespace std;

vector<int> first_last_occ(vector<int> arr, int x) {

    // First occurrence
    int low = 0, high = arr.size() - 1;
    int first_occ = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            first_occ = mid;
            // Discard the right half and search in left half.
            high = mid - 1;
        }
        else if (arr[mid] < x) {
            // Search in the right half.
            low = mid + 1;
        }
        else {
            // Search in the left half.
            high = mid - 1;
        }
    }

    low = 0, high = arr.size() - 1;
    int last_occ = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            last_occ = mid;
            // Discard the left half and search in right half.
            low = mid + 1;
        }
        else if (arr[mid] < x) {
            // Search in the right half.
            low = mid + 1;
        }
        else {
            // Search in the left half.
            high = mid - 1;
        }
    }

    return {first_occ, last_occ};
}

int main() {

    vector<int> res = first_last_occ({1, 3, 5, 5, 5, 5, 67, 123}, 5);
    cout << res[0] << " " << res[1];
}