#include<iostream>
using namespace std;
void binary(int a[],int s,int e,int key);
void binary(int a[],int s,int e,int key){
	
	while(s<=e)
	{
	int mid=s+(e-s)/2;
			if(a[mid]==key)
			{
				cout<<"element is at  index"<<mid;
				return ;
			}
			 else if(a[mid]>key)
			{
				e=mid-1;	
			}
			else
			{
				s=mid+1;
			} 
		}
		cout<<"element not found";
	}
int main()
{
	int a[]={1,2,3,4,5,6,7};
	int key=4;
	binary(a,0,6,key);
	return 0;
}
