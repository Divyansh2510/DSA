//Here in these program we sum the digits of given nos in array and then return the minimum.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sumEle(int num){
        int s=0;
        while (num>0){
            int d = num%10;
            s+=d;
            num /=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=sumEle(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int ans = nums[0];
        return ans;
}

int main(){
	vector<int> a = {10,11,13};
	cout<<minElement(a);
	return 0;
}
