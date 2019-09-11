//
// Created by valentun on 11.09.19.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    int N = 0;

    N = fork();

    if (N == 0) {
        printf("Hello from child %d\n", getpid() - N);
    } else {
        printf("Hello from parent %d\n", getpid() - N);
    }
}
