#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        string word;

        // Read words from first sentence
        stringstream ss1(s1);
        while (ss1 >> word) {
            freq[word]++;
        }

        // Read words from second sentence
        stringstream ss2(s2);
        while (ss2 >> word) {
            freq[word]++;
        }

        vector<string> result;
        for (auto &it : freq) {
            if (it.second == 1) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> ans = sol.uncommonFromSentences(s1, s2);

    cout << "Uncommon words are: ";
    for (string &w : ans) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}

