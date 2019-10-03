//
// Created by valentun on 03.10.19.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    scanf("%d", &N);

    int * array = (int *) malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i) {
        array[i] = i;

        printf("%d ", array[i]);
    }

    free(array);
}