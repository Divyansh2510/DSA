#include <stdio.h>
#include <stdlib.h>

#define MAX 100001   // adjust if needed

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestBalanced(int* nums, int n) {
    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        // Frequency arrays
        int evenFreq[MAX] = {0};
        int oddFreq[MAX] = {0};

        int distinctEven = 0;
        int distinctOdd = 0;

        for (int j = i; j < n; j++) {

            int val = nums[j];

            if (val % 2 == 0) {
                if (evenFreq[abs(val)] == 0)
                    distinctEven++;
                evenFreq[abs(val)]++;
            } else {
                if (oddFreq[abs(val)] == 0)
                    distinctOdd++;
                oddFreq[abs(val)]++;
            }

            if (distinctEven == distinctOdd) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

int main() {
    int nums[] = {1, 2, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = longestBalanced(nums, n);

    printf("Longest Balanced Subarray Length: %d\n", result);

    return 0;
}

