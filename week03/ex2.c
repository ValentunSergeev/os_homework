//
// Created by valentun on 04.09.19.
//

#include <stdio.h>

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3,1,5,2,10};

    bubble_sort(arr, 5);

    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
    }
}
