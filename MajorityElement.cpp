//Here we will will find the majority element in the array by using 'Mooore's Voting ' algorothim.
#include<iostream>
using namespace std;

int majority_ele(int *nums, int numsSize){
	
	int freq=0,  ans=0;
	
	for(int i =0;i<numsSize;i++){
		
		if(freq==0)
		{
			ans = nums[i];
		}
		if(ans == nums[i])
		{
			freq++;
		}else{
			
			freq--;
		}
	}
	
	freq = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == ans){
            freq++;
        }
    }

    if(freq > numsSize / 2){
        return ans;
    } else {
        return -1; 
    }
}

int main(){
	
	int nums[] ={1,2,2,2,2,2,2,4,1,1};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int ans =majority_ele(nums,numsSize);
	if(ans != -1){
        cout << "Majority element: " << ans << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}
