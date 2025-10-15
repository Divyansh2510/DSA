//Here we have to find the min distance and the maximum distance considering the "#" . For min distance consider 
// the "#" same as the character and for maximum distance consider "#" as different from char.

#include <iostream>
using namespace std;

int MinDiff(string s1, string s2) {
    int n = s1.length();
    int minDiff = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] && s1[i] != '#' && s2[i] != '#') {
            minDiff++;
        }
    }
    return minDiff;
}

int MaxDiff(string s1, string s2) {
    int n = s1.length();
    int maxDiff = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '#' || s2[i] == '#') {
            maxDiff++;
        }
    }
    return maxDiff;
}

int main() {
    string s1 = "#a##";
    string s2 = "bc##";
    cout << "Min: " << MinDiff(s1, s2) << endl;
    cout << "Max: " << MaxDiff(s1, s2) << endl;
    return 0;
}

