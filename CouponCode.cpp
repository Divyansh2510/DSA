#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // helper function to check if code is valid
    bool isValidCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        // businessLine priority
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < code.size(); i++) {
            // check active
            if (!isActive[i]) continue;

            // check valid code
            if (!isValidCode(code[i])) continue;

            // check valid business line
            if (priority.find(businessLine[i]) == priority.end()) continue;

            // store (business priority, code)
            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }

        // sort by businessLine first, then by code
        sort(validCoupons.begin(), validCoupons.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        // extract only codes
        vector<string> result;
        for (auto& p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> code = {
        "SAVE10", "HELLO@", "MED_20", "FOOD50", "ELEC#1"
    };

    vector<string> businessLine = {
        "electronics", "grocery", "pharmacy", "restaurant", "electronics"
    };

    vector<bool> isActive = {
        true, true, true, false, true
    };

    vector<string> result = sol.validateCoupons(code, businessLine, isActive);

    cout << "Valid Coupons:\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}

