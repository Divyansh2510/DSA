//These is Maximum Gap problem 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maximumGap(vector<int>& nums) {
     int n  = nums.size();
     if(n<2) return 0;
     sort(nums.begin(),nums.end());
     int max_=0;
     for(int i=0;i<n-1;i++){
            int diff= nums[i+1]-nums[i];
            max_=max(max_,diff);
     }
     return max_;
   }
   
int main(){
	vector<int> num = {1,3,6,9};
	cout<<maximumGap(num);
	return 0;
}
