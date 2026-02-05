//Generate Parenthesis 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<string> &v, int n, int op, int cc, string s) {
        // Base case
        if (op == n && cc == n) {
            v.push_back(s);
            return;
        }

        // Add opening bracket if possible
        if (op < n) {
            helper(v, n, op + 1, cc, s + "(");
        }

        // Add closing bracket if valid
        if (cc < op) {
            helper(v, n, op, cc + 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        helper(v, n, 0, 0, "");
        return v;
    }
};

int main() {
    int n;
    cout << "Enter number of pairs: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "Valid Parentheses Combinations:\n";
    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}

