#include <bits/stdc++.h>
using namespace std;

void update_matrix(vector<vector<int>> &arr) {

    int n = arr.size();
    int m = arr[0].size();

    bool first_row = false, first_col = false;
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            first_col = true;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (arr[0][i] == 0) {
            first_row = true;
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++) {
            // Updating the buckets when 0 is encountered.
            if (arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++) {
            // Making the updates after checking the corresponding buckets.
            if (arr[i][0] == 0 or arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if (first_row == true) {
        for (int i = 0; i < m; i++) {
            arr[0][i] = 0;
        }
    } 

    if (first_col == true) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {

    vector<vector<int>> arr = {{1, 0, 1},
                                {1, 1, 1},
                                {1, 0, 1}};
    update_matrix(arr);
    
    for (auto i : arr) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}