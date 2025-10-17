//Here in these code we have solved the Nqueens problems using recursion.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if placing a queen at (row, col) is safe
    bool isSafe(vector<string> &board, int row, int col, int n) {
        // Check the column above
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // Recursive backtracking function
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";

    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}

