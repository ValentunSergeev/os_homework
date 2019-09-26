//
// Created by valentun on 26.09.19.
//

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

int pipe_files[2];

void parent(int child_pid) {
    write(pipe_files[PIPE_WRITE], &child_pid, sizeof(int));

    printf("[PARENT] Pid %d send. Waiting for state changes\n", child_pid);
    fflush(stdout);

    waitpid(child_pid, NULL, WUNTRACED);

    printf("[PARENT] State changed\n");
    fflush(stdout);
}

void child1() {
    int pid;
    read(pipe_files[PIPE_READ], &pid, sizeof(int));

    printf("[CHILD1] Pid %d gotten\n", pid);
    fflush(stdout);

    sleep(2);

    printf("[CHILD1] Killing CHILD2\n");
    fflush(stdout);

    kill(pid, SIGSTOP);
}

void child2() {
    printf("[CHILD2] Started\n");
    fflush(stdout);

    while (1) {
        printf("[CHILD2] Alive\n");
        fflush(stdout);
        sleep(1);
    }
}

int main() {
    pipe(pipe_files);

    int p1 = fork();

    if (p1 > 0) {
        int p2 = fork();

        if (p2 > 0) {
            parent(p2);
        } else {
            child2();
        }
    } else {
        child1();
    }
}