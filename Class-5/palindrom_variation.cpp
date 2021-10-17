#include <bits/stdc++.h>
using namespace std;

// Checks whether a character is alphanumeric or not.
bool is_valid(char ch) {
    return ((ch >='0' && ch <='9') || 
            (ch >='a' && ch <='z') || 
            (ch >='A' && ch <='Z'));
}

// Checks whether two characters are same or not (while ignoring the cases).
bool are_same(char ch1, char ch2) {
    return ((ch1 == ch2) ||                 // Checks if both characters are already same
            (ch1 - 'a' + 'A' == ch2) ||     // Checks if ch2 is the uppercase version of ch1
            (ch1 - 'A' + 'a' == ch2));      // Checks if ch2 is the lowercase version of ch1
}

bool check_palindrome(string s) {

    int i = 0, j = s.length() - 1;
    
    while (i < j) {

        if (!is_valid(s[i])) {
            i++;
        }
        else if (!is_valid(s[j])) {
            j--;
        }
        else {
            if (are_same(s[i], s[j])) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cout << check_palindrome("Ab,cba") << endl;
    cout << check_palindrome("Ab,Bcba") << endl;
}
