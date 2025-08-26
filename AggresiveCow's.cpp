//Aggressive Cow's  Problem solved by using Binary Search Concept

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool IsPossible( vector<int> &arr , int n,int c,int minValue){
	int cows = 1, lastPos = arr[0];
	for(int i =1;i<n;i++){
		if(arr[i]-lastPos>=minValue){
			cows++;
			lastPos = arr[i];
		}
		if(cows == c){
			return  true;
		}
	}
	return false;
}

int MaxDistance( vector<int> &arr , int n,int c){
	sort(arr.begin(),arr.end());
	int st =1 , end = arr[n-1]-arr[0],ans=-1;
	while(st<=end){
		int mid = st+(end-st)/2;
		if (IsPossible(arr,n,c,mid)){
			ans = mid;
			st = mid +1;
		}
		else{
			end = mid-1;
		}
	}
	return ans;
}

int main(){
	 int temp[] = {1,2,8,4,9};
     vector<int> arr(temp, temp + 5);
	 int n=5, c=3;
	 cout<<MaxDistance(arr,n,c)<<endl;
	 return 0;
}
