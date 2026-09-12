#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        int min_val = *std::min_element(nums1.begin(), nums1.end());
        
        // If the minimum element is odd, we can always subtract it 
        // from even numbers to make all elements odd.
        if (min_val % 2 != 0) {
            return true;
        }
        
        // If the minimum element is even, we can only succeed if 
        // all elements in nums1 are already even.
        for (int x : nums1) {
            if (x % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> nums1 = {1, 4, 7};
    std::cout << "Test 1 [1, 4, 7]: " << (sol.uniformArray(nums1) ? "true" : "false") << " (Expected: true)\n";

    // Test Case 2
    std::vector<int> nums2 = {2, 3};
    std::cout << "Test 2 [2, 3]:    " << (sol.uniformArray(nums2) ? "true" : "false") << " (Expected: false)\n";

    // Test Case 3
    std::vector<int> nums3 = {4, 6};
    std::cout << "Test 3 [4, 6]:    " << (sol.uniformArray(nums3) ? "true" : "false") << " (Expected: true)\n";

    return 0;
}
