#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(number of bits)
int count_set_bits(int n) {

    int count = 0;
    while (n != 0) {
        if ((n & 1) != 0) {
            count++;
        }

        n = (n >> 1);
    }

    return count;
}

// Time complexity: O(number of set bits in n)
int count_set_bits_optimal(int n) {

    int count = 0;
    while (n != 0) {
        n = (n & (n - 1));
        count++;
    }

    return count;
}


int main() {
    cout << count_set_bits(45) << endl; // 4
    cout << count_set_bits(10) << endl; // 2
    cout << count_set_bits(2) << endl; // 1
    cout << count_set_bits(0) << endl; // 0

    cout << count_set_bits_optimal(45) << endl; // 4
    cout << count_set_bits_optimal(10) << endl; // 2
    cout << count_set_bits_optimal(2) << endl; // 1
    cout << count_set_bits_optimal(0) << endl; // 0
}