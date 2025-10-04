//In  these program we will be checking whether the given array is sorted or not using Recursive approch
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 0 || n == 1) {
        return true; // base case
    }
    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted(arr, n);
    return 0;
}

