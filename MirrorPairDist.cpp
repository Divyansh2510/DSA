#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int getRev(int n){
        int rev=0;
        while(n!=0){
            int d=n%10;
            rev=rev*10+d;
            n /=10;
        }
        return  rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                 ans = min(ans , i-mp[nums[i]]);
            }
            mp[getRev(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }

int  main(){
	vector<int> n = {12,21,45,65,54};
	cout<<minMirrorPairDistance(n);
	return 0;
}
