#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } 
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Combine arr1 and arr2
        for (int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};

int main() {

    // Input
    vector<int> nums = {5, 4, 3, 8};

    // Create object
    Solution obj;

    // Call function
    vector<int> result = obj.resultArray(nums);

    // Print result
    cout << "Result: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
