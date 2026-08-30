#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minElIdx = min_element(begin(nums),end(nums))-begin(nums);
        int maxElIdx = max_element(begin(nums),end(nums))-begin(nums);

        int left = min(minElIdx,maxElIdx);
        int right = max(minElIdx,maxElIdx);

        return min({left+1+n-right,right+1,n-left});
    }
    
int main(){
	vector<int> a = {1,3,10,5,8};
	cout<<minimumDeletions(a);
	return 0; 
}
