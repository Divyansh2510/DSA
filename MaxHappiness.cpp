//These is the maximum happiness problem . Here when we select one element then the value of others decrease by one (it cant become negative) .
// Hence we have to return maximum happiness.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());

        if(k==1){
            return happiness[0];
        }
        int dec = 0;
        long long sum=0;
        int num;
        for(int i=0;i<k;i++){
            num = happiness[i]-dec;
            if(num>=0){
                sum+=num;
            }
            dec++;
        }
        return sum;
    }
    
int main(){
	vector<int> happiness = {1,2,3};
	cout<<maximumHappinessSum(happiness,2);
	return 0;
}
