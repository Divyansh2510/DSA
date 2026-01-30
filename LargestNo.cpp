#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator
bool compare(string a, string b) {
    return a + b > b + a;
}

string largestNumber(vector<int>& nums) {
    vector<string> arr;

    
    for (int num : nums) {
        arr.push_back(to_string(num));
    }

    
    sort(arr.begin(), arr.end(), compare);

    
    if (arr[0] == "0")
        return "0";

    
    string result = "";
    for (string s : arr) {
        result += s;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    string ans = largestNumber(nums);

    cout << "Largest Number: " << ans << endl;

    return 0;
}

