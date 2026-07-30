#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += (i / 8) + 1;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string word;
    cout << "Enter the word: ";
    cin >> word;

    cout << "Minimum Pushes = " << obj.minimumPushes(word) << endl;

    return 0;
}
