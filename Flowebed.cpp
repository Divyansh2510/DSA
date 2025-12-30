//Thsse is flowebed problem solution of leetCode.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;  // plant flower
                    n--;
                    if (n == 0)
                        return true;
                }
            }
        }
        return n <= 0;
    }
};

int main() {
    Solution sol;

    
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << "Example 1 Output: "
         << (sol.canPlaceFlowers(flowerbed1, n1) ? "true" : "false")
         << endl;

    
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    cout << "Example 2 Output: "
         << (sol.canPlaceFlowers(flowerbed2, n2) ? "true" : "false")
         << endl;

    return 0;
}

