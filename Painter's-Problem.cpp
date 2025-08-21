//Painters Problem

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr , int n,int m,int maxAllowed){
	int painters=1,time =0;
	for(int i=0;i<n;i++){
		if(time + arr[i]<=maxAllowed){
			time += arr[i];
		}else{
			painters ++;
			time = arr[i];
		}
	}
	return painters <=m;
}

int PaintersProblem(vector<int> &arr , int n,int m){
	int sum =0 , maxVal = INT_MIN;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		maxVal = max(maxVal , arr[i]);
	}
	int st = maxVal , end = sum , ans = -1;
	while(st<=end){
		int mid = st + (end-st)/2;
		if(isPossible(arr,n,m,mid)){
			ans = mid;
			end = mid-1;
		}else{
			st = mid +1;
		}
	}
	return ans;
}

int main(){
	 int temp[] = {40,30,20,10};
     vector<int> arr(temp, temp + 4);
	 int n=4, m=2;
	 cout<<PaintersProblem(arr,n,m)<<endl;
	 return 0;
}
