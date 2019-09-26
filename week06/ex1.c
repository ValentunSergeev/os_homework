//
// Created by valentun on 25.09.19.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

int main() {
    int pipe_files[2];
    char first[]  = "1234567890";
    char second[100];

    pipe(pipe_files);

    write(pipe_files[PIPE_WRITE], first, strlen(first) + 1);
    read(pipe_files[PIPE_READ], second, 100);

    printf("%s", second);

}
