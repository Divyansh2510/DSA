#include <bits/stdc++.h>
using namespace std;

bool isNonDecreasing(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1])
            return false;
    }
    return true;
}

int minimumOperations(vector<int>& nums) {
    int operations = 0;

    while (!isNonDecreasing(nums)) {
        int minSum = INT_MAX;
        int idx = 0;

        
        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minSum = sum;
                idx = i;
            }
        }

        
        nums[idx] = nums[idx] + nums[idx + 1];
        nums.erase(nums.begin() + idx + 1);

        operations++;
    }

    return operations;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minimumOperations(nums) << endl;

    return 0;
}

