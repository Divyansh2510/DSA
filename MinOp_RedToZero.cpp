#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // Calculate total sum
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Sum of the subarray that we want to keep
        int target = totalSum - x;

        // If target is 0, we need to remove all elements
        if (target == 0) {
            return n;
        }

        int l = 0;
        int currentSum = 0;
        int maxLength = -1;

        // Sliding window
        for (int r = 0; r < n; r++) {
            currentSum += nums[r];

            // Shrink window if sum becomes too large
            while (l <= r && currentSum > target) {
                currentSum -= nums[l];
                l++;
            }

            // Found a valid subarray
            if (currentSum == target) {
                maxLength = max(maxLength, r - l + 1);
            }
        }

        // No valid subarray found
        if (maxLength == -1) {
            return -1;
        }

        // Remove everything outside the longest valid subarray
        return n - maxLength;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;

    int result = obj.minOperations(nums, x);

    cout << "Minimum operations: " << result << endl;

    return 0;
}
