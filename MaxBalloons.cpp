#include <iostream>
#include <unordered_map>
#include <algorithm>   // for min
using namespace std;

int maxNumberOfBalloons(string text) {
    unordered_map<char, int> m;

    for (char c : text) {
        m[c]++;
    }

    return min({
        m['b'],
        m['a'],
        m['n'],
        m['l'] / 2,
        m['o'] / 2
    });
}

int main() {
    string s = "nlaebolko";
    cout << maxNumberOfBalloons(s);
    return 0;
}

