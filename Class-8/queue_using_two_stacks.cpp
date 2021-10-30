#include <bits/stdc++.h>
using namespace std;

void queue_push(stack<int> &s1, stack<int> &s2, int x) {
    s1.push(x);
}

int queue_pop(stack<int> &s1, stack<int> &s2) {

    // If the queue is empty, return -1.
    if (s1.empty()) {
        return -1;
    }

    // Empty s1 into s2.
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    int result = s2.top();
    s2.pop();

    // Empty s2 into s1.
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }

    return result;
}

int main() {

    stack<int> s1;
    stack<int> s2;

    queue_push(s1, s2, 1);
    queue_push(s1, s2, 2);
    queue_push(s1, s2, 3);

    cout << queue_pop(s1, s2) << endl; // 1

    queue_push(s1, s2, 4);

    cout << queue_pop(s1, s2) << endl; // 2
    cout << queue_pop(s1, s2) << endl; // 3
    cout << queue_pop(s1, s2) << endl; // 4
    cout << queue_pop(s1, s2) << endl; // -1
}
