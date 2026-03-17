#include <bits/stdc++.h>
using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<int> height(n,0);
    int ans = 0;

    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0)
                height[j]=0;
            else
                height[j]+=1;
        }

        vector<int> temp = height;
        sort(temp.begin(), temp.end(), greater<int>());

        for(int j=0;j<n;j++){
            ans = max(ans, temp[j]*(j+1));
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    cout << largestSubmatrix(matrix);
}
