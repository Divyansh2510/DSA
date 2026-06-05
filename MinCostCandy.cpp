#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int sum = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {   // skip every 3rd candy
                sum += cost[i];
            }
        }

        return sum;
}
int main(){
	vector<int> a = {3,3,3,1};
	cout<<minCost(a);
	return 0;
}
