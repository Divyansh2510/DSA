#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1) return intervals;
        
        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        vector<int> current = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++) {
            
            // Check overlap
            if(intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            }
            else {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        
        // Push last interval
        ans.push_back(current);
        
        return ans;
    }
};

int main() {
    
    // Input intervals
    vector<vector<int>> intervals = {
        {1,3}, {2,6}, {8,10}, {15,18}
    };
    
    Solution obj;
    vector<vector<int>> result = obj.merge(intervals);
    
    cout << "Merged Intervals:\n";
    
    for(const auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    
    return 0;
}
