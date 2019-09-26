//
// Created by valentun on 26.09.19.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void parent(int child_pid) {
    sleep(10);

    kill(child_pid, SIGTERM);
}

void child1() {
    while (1) {
        printf("I'm alive\n");
        fflush(stdout);

        sleep(1);
    }
}

int main() {
    int p = fork();

    if (p > 0) {
        parent(p);
    } else {
        child1();
    }
}