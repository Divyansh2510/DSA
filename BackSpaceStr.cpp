// Here in these code the # is considered as backspace so considered that and check whether the two strong are equal .
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;

        // Process first string
        for (char c : s) {
            if (c == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(c);
            }
        }

        string s1;
        while (!st.empty()) {
            s1 += st.top();
            st.pop();
        }

        // Process second string
        for (char c : t) {
            if (c == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(c);
            }
        }

        string s2;
        while (!st.empty()) {
            s2 += st.top();
            st.pop();
        }

        return s1 == s2;
    }
};

int main() {
    Solution sol;

    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (sol.backspaceCompare(s, t))
        cout << "Strings are equal after backspace processing" << endl;
    else
        cout << "Strings are NOT equal after backspace processing" << endl;

    return 0;
}

