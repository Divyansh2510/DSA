#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_ = INT_MIN;
        int min_ = INT_MAX;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            max_ = max(nums[i], max_);
            min_ = min(nums[i], min_);
        }

        int val = max_ - min_;

        return 1LL * k * val;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 2, 5, 4};
    int k = 3;

    long long result = obj.maxTotalValue(nums, k);

    cout << "Maximum Total Value: " << result << endl;

    return 0;
}
