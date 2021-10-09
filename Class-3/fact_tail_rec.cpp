#include <bits/stdc++.h>
using namespace std;


void fact(int n, int m) {
    if (n == 0) {
        cout << m << endl;
        return;
    }

    fact(n - 1, m*n);
}

int main() {
    fact(6, 1);
}