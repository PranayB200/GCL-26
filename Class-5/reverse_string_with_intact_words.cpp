#include <bits/stdc++.h>
using namespace std;

string reverse_string_with_intact_words(string s) {

    vector<string> words;
    string current_word = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            words.push_back(current_word);
            current_word = "";
        }
        else {
            current_word += s[i];
        }
    }

    words.push_back(current_word);

    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += ".";
    }

    return result;
}


int main() {
    cout << reverse_string_with_intact_words("i.like.this.program.very.much") << endl;
    cout << reverse_string_with_intact_words("geeksforgeeks") << endl;
    cout << reverse_string_with_intact_words("..geeksforgeeks") << endl;
}
