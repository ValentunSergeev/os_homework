//
// Created by valentun on 28.08.19.
//

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main() {
    char a[BUFFER_SIZE];

    fgets(a, BUFFER_SIZE, stdin);

    size_t len = strlen(a);

    for (int i = 0; i < len; ++i) {
        putc(a[len - i - 1], stdout);
    }
}