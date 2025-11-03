#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllCombinations(vector<int> &arr, int idx, int tar,
                            vector<vector<int>> &ans, vector<int> &combin)
    {
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }
        
        if (idx == arr.size() || tar < 0) return;

        // pick current element
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx, tar - arr[idx], ans, combin);
        combin.pop_back();

        // skip current element
        getAllCombinations(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;
        
        sort(arr.begin(), arr.end());  // avoid duplicates
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        getAllCombinations(arr, 0, tar, ans, combin);
        return ans;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum(arr, target);

    cout << "\nAll unique combinations:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (int &x : vec) cout << x << " ";
        cout << "]\n";
    }

    if(result.empty())
        cout << "No possible combination found!\n";

    return 0;
}

