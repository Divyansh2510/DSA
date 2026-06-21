#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
   int maxCost = 0;

        // Find maximum cost
        for(int cost : costs) {
            maxCost = max(maxCost, cost);
        }

        // Counting array
        vector<int> count(maxCost + 1, 0);

        // Store frequency of each cost
        for(int cost : costs) {
            count[cost]++;
        }

        int ans = 0;

        // Traverse prices from low to high
        for(int price = 1; price <= maxCost; price++) {

            while(count[price] > 0 && coins >= price) {
                coins -= price;
                ans++;
                count[price]--;
            }

            if(coins < price)
                break;
        }

        return ans;
    }
    
    int main(){
    	vector<int> c = {1,3,2,4,1};
    	int coins = 7;
    	cout<<maxIceCream(c,coins);
    	return 0;
	}
