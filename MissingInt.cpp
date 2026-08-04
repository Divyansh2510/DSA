#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> missingIntegers(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 4, 2, 5};

    vector<int> ans = obj.missingIntegers(nums);

    cout << "Missing Integers: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}
