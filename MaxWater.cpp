//Here in these problem we are given an array which describes the height and widht of container , we have to find the container
// which can hold the  maximum capacity of water .
#include<iostream>
#include <algorithm>
using namespace std;

int max_capacity( int Height[],int size){
	int maxWater=0;
	int lp = 0;
	int rp =size-1;
	while(lp<rp){
		int w = rp-lp;
		int h = min(Height[lp],Height[rp]);
		int currWater = w*h;
		maxWater = max(maxWater,currWater);
		if (Height[lp] < Height[rp])
            lp++;
        else
            rp--;
	}
	return maxWater;
}

int main(){
	int Height[]={1,8,6,2,5,4,8,3,7};
	int size = sizeof(Height) / sizeof(Height[0]);
	int answer = max_capacity(Height,size);
	cout<<"Maximum Capcity of water:"<<answer;
	return 0;
}
