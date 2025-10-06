//Here we are going to print all subsets in an array using Recursion.
#include<iostream>
#include<vector>
using namespace std;

void PrintSubsets(vector<int> arr,vector<int> &ans, int i){
	if(i==arr.size()){
		for(int val : ans){
			cout<<val<<" ";
		}
		cout<<endl;
		return ;
	}
	ans.push_back(arr[i]);
	PrintSubsets(arr,ans,i+1);
	ans.pop_back();
	PrintSubsets(arr,ans,i+1);
}

int main(){
	vector<int> arr = {1,2,3};
	vector<int> ans;
	
	PrintSubsets(arr ,ans, 0);
	return 0;
}
