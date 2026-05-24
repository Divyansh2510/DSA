#include<iostream>
#include<vector>
using namespace std;

  bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }

int main(){
	vector<int> a = {2,1,3,4};
	cout<<check(a);
	return 0;
}
