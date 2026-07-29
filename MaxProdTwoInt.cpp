#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
  int maxProduct(int n) {
        int ans;
        int d;
        vector<int> p;
        while(n>0){
            d=n%10;
            p.push_back(d);
            n/=10;
        }
        sort(p.begin(),p.end(),greater<int>());
        ans = p[0]*p[1];
        return ans; 
    }
    
int main(){
	int n = 31;
	cout<<maxProduct(n);
	return 0;
}
