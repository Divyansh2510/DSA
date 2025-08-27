//#include <iostream>
//
//void bubbleSort(int arr[], int n) {
//    bool swapped;
//    for (int i = 0; i < n - 1; i++) {
//        swapped = false; // Initialize swapped as false because no swap has occurred yet in this pass
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                // Swap arr[j] and arr[j + 1] because they are out of order
//                std::swap(arr[j], arr[j + 1]);
//                swapped = true; // Mark that a swap has occurred in this pass
//            }
//        }
//
//        // If no two elements were swapped in the inner loop, the array is already sorted
//        if (!swapped) {
//            break;
//        }
//    }
//}
//
//int main() {
//    int arr[] = {64, 25, 12, 22, 11};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    std::cout << "Original array: ";
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << " ";
//    }
//
//    bubbleSort(arr, n);
//
//    std::cout << "\nSorted array: ";
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << " ";
//    }
//
//    return 0;
//}

#include<stdio.h>
#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
	bool swapped;
	for(int i=0; i<n-1;i++){
		swapped = false;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped= true;
			}
		}
		if(!swapped){
			break;
		}
	}
}
int main()
{
	int arr[]={44,54,21,76,89,33};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"original data"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	bubblesort(arr,n);
	cout<<"sorted array"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
