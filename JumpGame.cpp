//Here we are given an array and check the using the values can we reach to last index or not .

#include<vector>
#include<iostream>
using namespace std;

bool canJump(vector<int>& nums) {
        int reachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // If current position is not reachable
            if (i > reachable) return false;

            reachable = max(reachable, i + nums[i]);

            // If we can reach or pass the last index
            if (reachable >= n - 1) return true;
        }

        return true;
    }
int main(){
	vector<int> nums = {1,1,1,1};
	cout << (canJump(nums) ? "true" : "false");
     
}
