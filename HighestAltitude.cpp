#include<iostream>
#include<vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
        int max_=0;
        int sum=0;
        int n = gain.size();
        for(int i=0;i<n;i++){
            sum+=gain[i];
            max_=max(max_,sum);
        }
        return max_;
    }
    
int main(){
	vector<int> a = {-5,1,5,0,-7};
	cout<<largestAltitude(a);
	return 0;
}
