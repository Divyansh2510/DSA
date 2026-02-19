#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        queue<pair<pair<int,int>,int>> q;

        // Push all rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(ans,time);

            // top
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({{i-1,j},time+1});
            }

            // right
            if(j+1<m && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({{i,j+1},time+1});
            }

            // bottom
            if(i+1<n && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({{i+1,j},time+1});
            }

            // left
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({{i,j-1},time+1});
            }
        }

        // Check if any fresh orange remains
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution obj;
    int result = obj.orangesRotting(grid);

    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}

