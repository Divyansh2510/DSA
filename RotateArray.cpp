#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    obj.rotate(nums, k);

    cout << "Rotated array: ";
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}

