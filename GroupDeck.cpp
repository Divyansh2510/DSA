#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> freq;

    for (int card : deck) {
        freq[card]++;
    }

    int g = 0;
    for (auto &it : freq) {
        g = gcd(g, it.second);
    }

    return g >= 2;
}

int main() {
    vector<int> a = {1,2,3,4,4,3,2,1};
    cout << (hasGroupsSizeX(a) ? "true" : "false") << endl;
    return 0;
}

