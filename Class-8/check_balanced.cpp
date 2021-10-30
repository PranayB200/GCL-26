#include <bits/stdc++.h>
using namespace std;

// Check whether the opening and closing brackets are corresponding to each other or not.
bool are_same(char op, char cl) {
    if (op == '(') {
        return (cl == ')');
    }
    if (op == '[') {
        return (cl == ']');
    }
    if (op == '{') {
        return (cl == '}');
    }
    return false;
}

bool is_balanced(string x) {

    stack<char> helper;
    for (int i = 0; i < x.length(); i++) {

        // If x[i] is an opening bracket, push it into the stack.
        if (x[i] == '[' or x[i] == '(' or x[i] == '{') {
            helper.push(x[i]);
        }

        // Otherwise, check if the top of the stack contains the corresponding opening bracket.
        else {
            if (helper.empty()) {
                return false;
            }
            
            if (are_same(helper.top(), x[i])) {
                helper.pop();
            }
            else {
                return false;
            }
        }
    }

    return (helper.empty());
}

int main() {

    cout << is_balanced("[{}]()") << endl;  // true
    cout << is_balanced("((])") << endl;    // false
    cout << is_balanced(")))") << endl;     // false
    cout << is_balanced("[[{") << endl;     // false
}