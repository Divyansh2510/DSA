#include <iostream>
#include <string>
using namespace std;

int reverseDegree(string s) {
    int n = s.length();
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int t = 'z' - s[i - 1] + 1;
        t = t * i;
        sum += t;
    }

    return sum;
}

int main() {
    string s = "abc";

    cout << reverseDegree(s);

    return 0;
}
