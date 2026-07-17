#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int n) 
{
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) 
	{
        if (arr[i] > max)
            max = arr[i];
    }
    // Create a count array to store occurrences
    int *count = (int*)calloc(max + 1, sizeof(int));
    // Count occurrences of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;	//Mapping the value with it's count
    // Build the sorted array using the count array
    int index = 0;
    for (int i=0;i<=max;i++) 
	{
        while (count[i]>0) 
		{
            arr[index++] = i;
            count[i]--;
        }
    }
    // Free dynamically allocated memory
    free(count);
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);
    countSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
