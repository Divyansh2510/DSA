#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int orgColor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] == newColor || image[i][j] != orgColor) {
            return;
        }

        image[i][j] = newColor;

        dfs(image, i - 1, j, newColor, orgColor);
        dfs(image, i, j + 1, newColor, orgColor);
        dfs(image, i + 1, j, newColor, orgColor);
        dfs(image, i, j - 1, newColor, orgColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    Solution obj;
    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
