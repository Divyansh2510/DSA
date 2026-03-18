#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sum matrix
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        int ans = 0;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                preSum[i][j] = grid[i-1][j-1]
                             + preSum[i-1][j]
                             + preSum[i][j-1]
                             - preSum[i-1][j-1];

                if(preSum[i][j] <= k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };

    int k = 7;

    int result = obj.countSubmatrices(grid, k);
    cout << "Count of submatrices: " << result << endl;

    return 0;
}
