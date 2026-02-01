#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int start, int n, int k) {
        // If combination size becomes k, store it
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++) {
            temp.push_back(i);          // Choose
            backtrack(i + 1, n, k);     // Explore
            temp.pop_back();            // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution obj;
    vector<vector<int>> result = obj.combine(n, k);

    cout << "Combinations are:\n";
    for (const auto &comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i != comb.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}

