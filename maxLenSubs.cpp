#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add current character
            mp[s[right]]++;

            // If any character occurs more than 2 times
            while (mp[s[right]] > 2) {
                mp[s[left]]--;
                left++;
            }

            // Update maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s = "bcbbbcba";

    cout << obj.maximumLengthSubstring(s);

    return 0;
}

