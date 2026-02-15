#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                // Circular index calculation (handles negative properly)
                int newIndex = ((i + nums[i]) % n + n) % n;
                result[i] = nums[newIndex];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums = {3, -2, 1, 1};

    vector<int> result = sol.constructTransformedArray(nums);

    cout << "Transformed Array: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

