#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 

typedef struct Bucket {
    int values[BUCKET_SIZE];
    int count;
} Bucket;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    Bucket buckets[BUCKET_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_SIZE;
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        insertionSort(buckets[i].values, buckets[i].count);
    }

    int idx = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[idx++] = buckets[i].values[j];
        }
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
