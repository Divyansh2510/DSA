#include <stdio.h>

#define SIZE 5  // Define the size of the array

void selection(int a[], int size);

int main() {
    int a[SIZE] = {7, 8, 3, 1, 2};
    int smallest;

    printf("Sorted array is:\n");
    for (int i = 0; i < SIZE - 1; i++) {
        smallest = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (a[j] < a[smallest]) {
                smallest = j;
            }
        }
        // Swap the found smallest element with the current element
        int temp = a[smallest];
        a[smallest] = a[i];
        a[i] = temp;
    }

    selection(a, SIZE);
    return 0;
}

void selection(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

