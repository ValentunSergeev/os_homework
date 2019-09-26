//
// Created by valentun on 25.09.19.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

int pipe_files[2];

void parent() {
    char string[]  = "1234567890";

    write(pipe_files[PIPE_WRITE], string, strlen(string) + 1);
}

void child() {
    char string[100];

    read(pipe_files[PIPE_READ], string, 100);

    printf("%s", string);
}

int main() {
    pipe(pipe_files);

    int p = fork();

    if (p > 0) {
        parent();
    } else {
        child();
    }
}