#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
void printArray(int *A,int  n)//for printing array
{
	for(int i=0;i<=n;i++)
	{
		printf(" %d ",A[i]);
	}
	printf("\n");
}
int maximum(int A[], int n){   //for getting the max no
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;
    
}
void countSort(int *A,int n)
{   
    int i,j;
    int max = maximum(A,n);
	int *count= (int*)malloc((max+1)*sizeof(int));
	for( i=0;i<max+1;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		count[A[i]]=count[A[i]]+1;
	}
	i=0;
	j=0;
	while(i<=max)
	{
		if(count[i]>0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 
}

int main()
{
	int A[]={12,2,3,15,4,1};
	int n=6;
	printf("The array before sorting is\n");
	printArray(A, n);
	printf("The array after sorting is\n");
    countSort(A, n);
    printArray(A, n); 
    return 0;
}
