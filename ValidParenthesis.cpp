//Here in these code we  give a string containing parenthesis and we have to check whether the order is correct or not 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            // If it's an opening bracket ? push
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                // Closing bracket but stack empty ? invalid
                if(st.empty()) return false;

                // Check matching pair
                if((st.top() == '(' && s[i] == ')') ||
                   (st.top() == '{' && s[i] == '}') ||
                   (st.top() == '[' && s[i] == ']'))
                {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    if(sol.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}

