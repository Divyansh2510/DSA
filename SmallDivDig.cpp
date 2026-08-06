#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int temp = n;
            int product = 1;

            // Calculate product of digits
            while (temp > 0) {
                product *= (temp % 10);
                temp /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};

int main() {
    Solution obj;

    int n, t;
    cin >> n >> t;

    cout << obj.smallestNumber(n, t);

    return 0;
}
