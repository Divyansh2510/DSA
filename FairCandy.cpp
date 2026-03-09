#include <stdio.h>

int main() {
    
    int aliceSizes[] = {1, 2};
    int bobSizes[] = {2, 3};
    
    int n = 2; // size of aliceSizes
    int m = 2; // size of bobSizes
    
    int sumA = 0, sumB = 0;

    // Calculate sum of Alice's candies
    for(int i = 0; i < n; i++){
        sumA += aliceSizes[i];
    }

    // Calculate sum of Bob's candies
    for(int i = 0; i < m; i++){
        sumB += bobSizes[i];
    }

    int diff = (sumA - sumB) / 2;

    for(int i = 0; i < n; i++){
        int x = aliceSizes[i];

        for(int j = 0; j < m; j++){
            int y = bobSizes[j];

            if(x - y == diff){
                printf("Swap boxes: [%d, %d]\n", x, y);
                return 0;
            }
        }
    }

    return 0;
}


