#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int i = 0, j = 0;
    int starIndex = -1;
    int matchIndex = 0;

    while (i < s.length()) {
        
        // Case 1: characters match or '?'
        if (j < p.length() && (p[j] == s[i] || p[j] == '?')) {
            i++;
            j++;
        }
        // Case 2: '*' found
        else if (j < p.length() && p[j] == '*') {
            starIndex = j;
            matchIndex = i;
            j++;
        }
        // Case 3: mismatch but we had '*'
        else if (starIndex != -1) {
            j = starIndex + 1;
            matchIndex++;
            i = matchIndex;
        }
        // Case 4: mismatch and no '*'
        else {
            return false;
        }
    }

    // Check remaining characters in pattern
    while (j < p.length() && p[j] == '*') {
        j++;
    }

    return j == p.length();
}

int main() {
    string s, p;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter pattern: ";
    cin >> p;

    if (isMatch(s, p))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}

