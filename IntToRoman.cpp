//Here in these code we taken a INT no. as input and then converted it into an Roman Integer.

#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    // Values and symbols
    int values[]    = {1000, 900, 500, 400, 100, 90,  50, 40,  10, 9,   5, 4,  1};
    string symbols[] = {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string roman = "";

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            roman += symbols[i];
            num -= values[i];
        }
    }
    return roman;
}

int main() {
    cout << intToRoman(58);  // Output: LVIII
    return 0;
}

        
