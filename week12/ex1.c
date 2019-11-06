//
// Created by valentun on 06.11.19.
//

#include <stdio.h>

int main() {
    FILE * in = fopen("/dev/random", "r");
    FILE * out = fopen("ex1.txt", "w+");

    char buffer[20];

    fgets(buffer, 20, in);

    for (int i = 0; i < 20; ++i) {
        fprintf(out, "%d ", buffer[i]);
    }
}
