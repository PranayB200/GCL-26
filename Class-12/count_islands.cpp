#include<bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<int>> &arr, int i, int j) {
    
    return (i >= 0 and i < arr.size() and
            j >= 0 and j < arr[0].size());
}

void dfs_util(vector<vector<int>> &arr, int i, int j) {

    if (arr[i][j] == 0) {
        return;
    }

    arr[i][j] = 0; // Marking (i, j) as visited so that it does not get traversed ever again.

    /*
    Make DFS calls to:
    (i - 1, j - 1), (i - 1, j), (i - 1, j + 1), (i, j - 1), 
    (i, j + 1), (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)
    */
    int dx[] = {-1, -1, -1, +0, +0, +1, +1, +1};
    int dy[] = {-1, +0, +1, -1, +1, -1, +0, +1};

    for (int k = 0; k < 8; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (is_safe(arr, new_i, new_j)) {
            dfs_util(arr, new_i, new_j);
        }
    }
}

int count_islands(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {

                result++;
                dfs_util(arr, i, j);
            }
        }
    }

    return result;
}

int main() {

    cout << count_islands( {{0, 1, 0, 0},
                            {0, 0, 0, 0},
                            {1, 1, 0, 1},
                            {1, 0, 0, 1}} );
}