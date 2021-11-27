#include<bits/stdc++.h>
using namespace std;

int max_tasks(vector<int> arr, int T) {

    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > T) {
            return i;
        }
        T -= arr[i];
    }

    return (int)arr.size();
}

int main() {

    cout << max_tasks({4, 2, 1, 2, 5}, 8) << endl; 
    cout << max_tasks({4, 2, 1, 2, 5}, 80) << endl; 
}