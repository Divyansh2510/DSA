// Here we will find all permutations of a given array using recursion
#include <iostream>
#include <vector>
using namespace std;

void GetPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums); 
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        GetPerms(nums, idx + 1, ans);
        swap(nums[idx], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    GetPerms(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums); // store returned permutations

    
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

