#include<bits/stdc++.h>
using namespace std;

class item {
    public:
    int value, weight;

    item(int v, int w) {
        value = v; 
        weight = w;
    }
};

bool custom_comp(item &a, item &b) {

    double r1 = a.value / ((double)a.weight);
    double r2 = b.value / ((double)b.weight);

    return r1 > r2;
}

double max_value(vector<int> values, vector<int> weights, int W) {

    // Sort the array on the basis of values[i]/weights[i] in decreasing order.

    int n = values.size();

    // Create an array of pairs {values[i], weights[i]}
    vector<item> arr; 
    for (int i = 0; i < n; i++) {
        arr.push_back({values[i], weights[i]});
    }

    sort(arr.begin(), arr.end(), custom_comp);

    double result = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) { // If the current item can be included completely, do it.
            result += arr[i].value;
            W -= arr[i].weight;
        }
        else { // Otherwise, add the current time with as much weight as possible.
            result += (W * arr[i].value) / ((double)arr[i].weight);
            break;
        }
    }

    return result;
}

int main() {

    cout << max_value({120, 100, 60}, {30, 20, 10}, 50) << endl;
    cout << max_value({100, 100, 60}, {30, 20, 10}, 50) << endl;
    cout << max_value({1, 1, 1, 100}, {2, 2, 2, 6}, 6) << endl;
}