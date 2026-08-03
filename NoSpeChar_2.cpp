#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        // Store last occurrence of lowercase letters
        // and first occurrence of uppercase letters
        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                lastLower[word[i] - 'a'] = i;
            } else {
                int idx = word[i] - 'A';
                if (firstUpper[idx] == -1)
                    firstUpper[idx] = i;
            }
        }

        int count = 0;

        // Count special letters
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    string word;

    cout << "Enter the string: ";
    cin >> word;

    cout << "Number of Special Characters: "
         << obj.numberOfSpecialChars(word) << endl;

    return 0;
}
