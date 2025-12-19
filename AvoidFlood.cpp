// These is leet problem Avoid Flood solution .

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);

        // lastRain[lake] = last day this lake was filled
        unordered_map<int, int> lastRain;

        // indices of days where rains[i] == 0 (dry days)
        set<int> dryDays;

        for (int i = 0; i < n; i++) {

            if (rains[i] == 0) {
                // mark this day as available for drying
                dryDays.insert(i);
                ans[i] = 1;  // temporary value, can be any lake
            }
            else {
                int lake = rains[i];

                // If lake was already full ? need a dry day after last rain
                if (lastRain.count(lake)) {
                    int lastDay = lastRain[lake];

                   
                    auto it = dryDays.upper_bound(lastDay);
                    if (it == dryDays.end()) {
                        
                        return {};
                    }

                    
                    ans[*it] = lake;
                    dryDays.erase(it);
                }

                
                lastRain[lake] = i;
                ans[i] = -1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,0,1,2};

    vector<int> result = s.avoidFlood(nums);

    if (result.empty()) {
        cout << "[]";   
    } else {
        for (int x : result) {
            cout << x << " ";
        }
    }
    return 0;
}

