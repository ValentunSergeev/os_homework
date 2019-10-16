//
// Created by valentun on 16.10.19.
//

#include <stdio.h>

void generateMin() {
    for (int i = 1; i <= 1000; ++i) {
        printf("%d ", i);
    }
}

void generateMax() {
    for (int i = 1; i <= 1000; ++i) {
        printf("%d ", i % 10);
    }
}

int main() {
    generateMin();

    printf("\n");

    generateMax();
}