#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int n, string &curr, vector<string> &res) {
        // If string length becomes n, store it
        if(curr.length() == n) {
            res.push_back(curr);
            return;
        }

        // Try characters a, b, c
        for(char ch = 'a'; ch <= 'c'; ch++) {
            // Check happy string condition
            if(curr.empty() || curr.back() != ch) {
                curr.push_back(ch);        // choose character
                solve(n, curr, res);       // recursive call
                curr.pop_back();           // backtrack
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        string curr = "";

        solve(n, curr, res);

        if(res.size() < k) 
            return "";

        return res[k-1];
    }
};

int main() {
    int n, k;
    
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    string ans = obj.getHappyString(n, k);

    if(ans == "")
        cout << "Output: Empty string (Not enough happy strings)" << endl;
    else
        cout << "Output: " << ans << endl;

    return 0;
}

