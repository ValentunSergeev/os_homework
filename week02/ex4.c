//
// Created by valentun on 28.08.19.
//

#include <stdio.h>

void swap(int * a_ptr, int * b_ptr) {
    int buffer = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = buffer;
}

int main() {
    int a, b;

    printf("Input two integers: ");
    int in_result = scanf("%d %d", &a, &b);

    if (in_result < 2) {
        printf("Wrong input");
        return 1;
    }

    swap(&a, &b);

    printf("a: %d, b: %d", a, b);
}