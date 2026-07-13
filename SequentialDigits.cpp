#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        string s = "123456789";

        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();

        for (int len = lowLen; len <= highLen; len++) {

            for (int i = 0; i + len <= 9; i++) {

                int num = stoi(s.substr(i, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int low, high;

    cout << "Enter low and high: ";
    cin >> low >> high;

    vector<int> ans = obj.sequentialDigits(low, high);

    cout << "Sequential numbers are:\n";

    for (int x : ans)
        cout << x << " ";

    return 0;
}
