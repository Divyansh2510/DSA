//These leetcode code problem solution Long pressed name.

#include <iostream>
using namespace std;

bool isLongPressedName(string name, string typed) {
    int i = 0, j = 0;

    while (j < typed.length()) {
        // Case 1: characters match
        if (i < name.length() && name[i] == typed[j]) {
            i++;
            j++;
        }
        // Case 2: long pressed character
        else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
        }
        // Case 3: invalid case
        else {
            return false;
        }
    }

    // Check if all characters in name are matched
    return i == name.length();
}

int main() {
    string name1 = "alex", typed1 = "aaleex";
    cout << isLongPressedName(name1, typed1) << endl; // 1 (true)

    string name2 = "saeed", typed2 = "ssaaedd";
    cout << isLongPressedName(name2, typed2) << endl; // 0 (false)

    return 0;
}

