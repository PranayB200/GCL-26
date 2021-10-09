#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int n) {

    if (n == 0) {
        return 0;
    }

    int sub_result = sum_of_digits(n / 10); // floor-division.
    int last_digit = n % 10; // remainder when divided by 10.

    return last_digit + sub_result;
}

int sum_of_digits_rec(int n, int res) {

    if (n == 0) {
        return res;
    }
    return sum_of_digits_rec(n / 10, res + n % 10);
}

int main() {
    cout << sum_of_digits_rec(12345, 0);
}