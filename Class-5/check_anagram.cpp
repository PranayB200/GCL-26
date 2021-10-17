#include <bits/stdc++.h>
using namespace std;

bool check_anagrams(string a, string b) {

    if (a.length() != b.length()) {
        return false;
    }

    vector<int> char_freq(26, 0);

    for (int i = 0; i < a.length(); i++) {
        char_freq[a[i] - 'a']++;
        char_freq[b[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (char_freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << check_anagrams("abc", "bac") << endl;
    cout << check_anagrams("abcc", "baca");
}
