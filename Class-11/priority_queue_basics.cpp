#include<bits/stdc++.h>
using namespace std;

int main() {

    priority_queue<int> max_heap;

    // 5, 2, 1, 7, 3
    max_heap.push(5);
    max_heap.push(2);
    max_heap.push(1);
    max_heap.push(7);
    max_heap.push(3);

    while(!max_heap.empty()) {
        cout << max_heap.top() << endl;
        max_heap.pop();
    }
    cout << endl;
    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // 5, 2, 1, 7, 3
    min_heap.push(5);
    min_heap.push(2);
    min_heap.push(1);
    min_heap.push(7);
    min_heap.push(3);

    while(!min_heap.empty()) {
        cout << min_heap.top() << endl;
        min_heap.pop();
    }
    cout << endl;

    priority_queue<int> min_heap2; // Hacky implementation of min heap using max heap.
    // 5, 2, 1, 7, 3
    min_heap2.push(-5);
    min_heap2.push(-2);
    min_heap2.push(-1);
    min_heap2.push(-7);
    min_heap2.push(-3);

    while (!min_heap2.empty()) {
        cout << -min_heap2.top() << endl;
        min_heap2.pop();
    }
}