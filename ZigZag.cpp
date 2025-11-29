#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ZigZag(string s, int numRows){
    if(numRows == 1 || numRows >= s.length()) 
        return s;

    vector<string> rows(numRows);
    int currRow = 0;
    bool goingDown = false;

    for(char c : s){
        rows[currRow] += c;

        // Flip direction at top or bottom
        if(currRow == 0 || currRow == numRows - 1)
            goingDown = !goingDown;

        currRow += (goingDown ? 1 : -1);
    }

    string ans = "";
    for(string &row : rows)
        ans += row;

    return ans;
}

int main(){
    string s = "PAYPALISHIRING";
    cout << ZigZag(s, 3);
    return 0;
}

