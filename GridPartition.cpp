#include <bits/stdc++.h>
using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    long long totalSum = 0;

    // Step 1: Total sum
    for (auto &row : grid) {
        for (int val : row) {
            totalSum += val;
        }
    }

    // If total sum is odd ? not possible
    if (totalSum % 2 != 0) return false;

    long long target = totalSum / 2;

    // Step 2: Horizontal cut
    long long currSum = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            currSum += grid[i][j];
        }
        if (currSum == target) return true;
    }

    // Step 3: Column sum precomputation
    vector<long long> colSum(n, 0);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            colSum[j] += grid[i][j];
        }
    }

    // Step 4: Vertical cut
    currSum = 0;
    for (int j = 0; j < n - 1; j++) {
        currSum += colSum[j];
        if (currSum == target) return true;
    }

    return false;
}

int main() {
    // Example 1
    vector<vector<int>> grid1 = {{1, 4}, {2, 3}};
    cout << (canPartitionGrid(grid1) ? "true" : "false") << endl;

    // Example 2
    vector<vector<int>> grid2 = {{1, 3}, {2, 4}};
    cout << (canPartitionGrid(grid2) ? "true" : "false") << endl;

    // Custom test (single row case)
    vector<vector<int>> grid3 = {
        {100000, 100000, 100000, 100000, 100000}
    };
    cout << (canPartitionGrid(grid3) ? "true" : "false") << endl;

    return 0;
}
