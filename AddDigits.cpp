//Here in these program we have to add the nums till we not get a single digit no.

#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num <= 9) {
            return num;
        }

        int sum = 0;
        while (num > 0) {
            sum += num % 10;  // get last digit
            num /= 10;       // remove last digit
        }

        return addDigits(sum); // recursive call
    }
};

int main(){
	Solution s;
	cout<<s.addDigits(38);
	return 0;
}
