//Here we will use an optimized way to find the pairs in an array who's sum matches the target value.

#include<iostream>
#include<vector>
using namespace std;

vector<int> PairSum(vector<int> nums,int target){
	vector<int> ans;
	int n = nums.size();
	int i =0,j=n-1;
	
	while(i<j){
		int sum = nums[i]+nums[j];
		if(sum>target)
        {
        	j--;
				}
		else if(sum<target){
			i++;
		}
		else{
			ans.push_back(nums[i]);
			ans.push_back(nums[j]);
			return ans;
		}
				
	}
	return ans;
}

int main()
{
  int arr[] = {2, 7, 11, 15};  
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
  int target=18;
  vector<int> ans = PairSum(nums,target);
  cout<<ans[0]<<","<<ans[1]<<endl;
  return 0;
}
