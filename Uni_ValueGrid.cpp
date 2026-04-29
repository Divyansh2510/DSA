#include <vector>
#include<iostream>>
#include <algorithm>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> arr;

    // Step 1: Flatten
    for (auto &row : grid) {
        for (int num : row) {
            arr.push_back(num);
        }
    }

    // Step 2: Check feasibility
    int rem = arr[0] % x;
    for (int num : arr) {
        if (num % x != rem) return -1;
    }

    // Step 3: Sort
    sort(arr.begin(), arr.end());

    // Step 4: Median
    int n = arr.size();
    int median = arr[n / 2];

    // Step 5: Count operations
    int ops = 0;
    for (int num : arr) {
        ops += abs(num - median) / x;
    }

    return ops;
}

int main(){
	vector<vector<int>> a = {{1,5},{2,3}};
	cout<<minOperations(a,1);
	return 0;
}
