#include<iostream>
#include<String>
#include<algorithm>
using namespace std;

long long sumAndMultiply(int n) {
        int sum = 0;
        string s;

        while (n > 0) {
            int d = n % 10;

            if (d != 0) {
                sum += d;
                s.push_back(d + '0');
            }

            n /= 10;
        }

        if (s.empty())
            return 0;

        reverse(s.begin(), s.end());

        long long a = stoll(s);

        return a * sum;
    }
    
    
int main(){
	 cout<<sumAndMultiply(10200304);
	 return 0;
}
