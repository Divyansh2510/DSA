//Slding window problem solution 

#include<iostream>
#include<vector>
#include<deque>
using namespace std;



vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // stores indices
        vector<int> res;

        // Process first window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            // Max of previous window
            res.push_back(nums[dq.front()]);

            // Remove indices out of current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Max of last window
        res.push_back(nums[dq.front()]);

        return res;
    }

int main(){
	vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = maxSlidingWindow(nums,3);
    
    for(int n : ans){
    	cout<<n;
	}
	return 0;
}
