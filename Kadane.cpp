//Here we will find the maximum sum in subarrays using Kadane's Technique.
#include<iostream>
//#include<math.h>
//#include<stdlib.h>
using namespace std;
int main()
{
  int arr[]={1,-4,4,3,6,-8};
  int n = sizeof(arr)/sizeof(arr[0]);
  int currSum=0,maxSum=INT_MIN;
  
  for(int i=0;i<n;i++)
  {
  	currSum+=arr[i];
  	maxSum=max(currSum,maxSum);
  	
  	if(currSum<0)
  	{
  		currSum=0;
	}
  }  
  cout<<maxSum;
  return 0;
}
