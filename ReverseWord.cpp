//Here we reverse wprds in string 

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                
                int left = start;
                int right = i - 1;
                
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                
                start = i + 1;
            }
        }
        
        return s;
    }
};

int main() {
    Solution obj;
    
    string s1 = "Let's take LeetCode contest";
    cout << obj.reverseWords(s1) << endl;
    
    string s2 = "Mr Ding";
    cout << obj.reverseWords(s2) << endl;
    
    return 0;
}
