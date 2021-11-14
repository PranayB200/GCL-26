#include<bits/stdc++.h>
using namespace std;

// ------------------ Deletion ------------------

// `index`: represents the current index that we are heapifying.
void top_down_heapify(vector<int> &arr, int index) {

    int left_child_index = 2*index + 1;
    int right_child_index = 2*index + 2;

    // We need the max of arr[index], arr[left_child_index], arr[right_child_index].
    int largest_value_index = index;
    if (left_child_index < arr.size() && arr[largest_value_index] < arr[left_child_index]) {
        largest_value_index = left_child_index;
    }
    if (right_child_index < arr.size() && arr[largest_value_index] < arr[right_child_index]) {
        largest_value_index = right_child_index;
    }

    // Stopping condition. In order to save ourselves from infinite recursion.
    if (index != largest_value_index) {
        swap(arr[index], arr[largest_value_index]);
        top_down_heapify(arr, largest_value_index);
    }
}

void delete_root(vector<int> &arr) {

    // Replace the value of the root node with the value of the last node.
    arr[0] = arr[arr.size() - 1];

    // Remove the last node.
    arr.pop_back();

    top_down_heapify(arr, 0);
}

// ------------------------------------------------------------------------


// ------------------ Insertion ------------------

// `index`: represents the current index that we are heapifying.
void bottom_up_heapify(vector<int> &arr, int index) {

    if (index == 0) {
        return;
    }

    int parent_index = (index - 1) / 2;

    if (arr[index] > arr[parent_index]) {
        swap(arr[index], arr[parent_index]);
        bottom_up_heapify(arr, parent_index);
    }
}

void insert(vector<int> &arr, int ele) {
    arr.push_back(ele);
    bottom_up_heapify(arr, arr.size() - 1);
}

// ------------------------------------------------------------------------

int main() {

    vector<int> arr = {20, 10, 7, 5, 3, 2};
    delete_root(arr);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    insert(arr, 20);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}