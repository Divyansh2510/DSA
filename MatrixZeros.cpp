//Set Matrix Zeros Problem 

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int cols = matrix[0].size();

        set<int> rowm;
        set<int> colm;

        // Step 1: find rows and columns that contain zero
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    rowm.insert(i);
                    colm.insert(j);
                }
            }
        }

        // Step 2: set corresponding rows and columns to zero
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowm.find(i) != rowm.end() || colm.find(j) != colm.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Helper function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    s.setZeroes(matrix);

    cout << "\nMatrix After setZeroes:" << endl;
    printMatrix(matrix);

    return 0;
}

