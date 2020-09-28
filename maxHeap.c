#include <stdio.h>

void printHeap(int arr[], int n) {
    int i = 0;
    for(i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}

void heapify(int arr[], int i, int n) {
    static int iter = 0;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    printf("heap after %d iterations\n", iter);
    printHeap(arr, 6);
    iter++;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        // if largest is not the root
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, largest, n);
    }
}

void heapSort(int arr[], int n) {
    int i = 0;
    printf("creating a heap\n");
    for(i = n / 2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    }
    printf("performing heap sort\n");
    for(i = n - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, 0, i);
    }
}

int main() {
    int arr[6] = {12, 11, 13, 1, 4, 5};
    heapSort(arr, 6);
    printHeap(arr, 6);
}