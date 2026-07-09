#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])>1){
                arr[i]=arr[i-1]+1;
            }
        }
        int max = arr[n-1];
        return max;
    }
    
int main(){
	vector<int> a = {1,2,2,1,1};
	cout<<maximumElementAfterDecrementingAndRearranging(a);
	return 0;
}
