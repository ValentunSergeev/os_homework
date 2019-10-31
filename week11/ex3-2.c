//
// Created by valentun on 30.10.19.
//

#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Hello\n");
    fork();
    printf("\n");
    return 0;
}
