//
// Created by valentun on 06.11.19.
//

#include <stdio.h>

int main() {
    FILE * out = fopen("ex3-1.txt", "w+");

    for (int i = 0; i < 1000000; ++i) {
        fprintf(out, "%d ", i);
    }
}
