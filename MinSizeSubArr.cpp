#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    Solution obj;

    int target;
    int n;

    cout << "Enter target: ";
    cin >> target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.minSubArrayLen(target, nums);

    cout << "Minimum subarray length: " << result << endl;

    return 0;
}
