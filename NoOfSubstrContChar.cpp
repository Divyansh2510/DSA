#include<iostream>
#include<String>
#include<vector>
using namespace std;

int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int cnt = 0;
        int curcnt = 0;
        int left = 0;
        int n = s.length();

        for (int right = 0; right < n; right++) {
            char ch = s[right];
            freq[ch - 'a']++;

            if (freq[ch - 'a'] == 1)
                curcnt++;

            while (curcnt == 3) {
                cnt += (n - right);

                char c = s[left];
                freq[c - 'a']--;

                if (freq[c - 'a'] == 0)
                    curcnt--;

                left++;
            }
        }

        return cnt;
    }
    
int main(){
	string s = "abcabc";
	cout<<numberOfSubstrings(s);
	return 0;
}
