#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        // Maximum element should be n-1
        if (nums[n - 1] != n - 1) {
            return false;
        }

        // Check numbers from 1 to n-2
        for (int i = 0; i < n - 1; i++) {

            // Expected value is i+1
            if (nums[i] != i + 1) {
                return false;
            }
        }

        // Last two elements must be same
        return nums[n - 1] == nums[n - 2];
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 3, 3, 2};

    if (obj.isGood(nums)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
