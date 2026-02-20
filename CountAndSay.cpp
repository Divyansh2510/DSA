#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    // Base case
    if (n == 1) {
        return "1";
    }

    // Recursive call to get previous term
    string say = countAndSay(n - 1);
    string result = "";

    // Process the previous term
    for (int i = 0; i < say.length(); i++) {
        char ch = say[i];
        int count = 1;

        // Count consecutive same characters
        while (i < say.length() - 1 && say[i] == say[i + 1]) {
            count++;
            i++;
        }

        // Append count and character
        result += to_string(count) + string(1, ch);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 0;
    }

    string ans = countAndSay(n);
    cout << "Count and Say term " << n << " is: " << ans << endl;

    return 0;
}
