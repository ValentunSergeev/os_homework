//
// Created by valentun on 25.09.19.
//

#include <stdio.h>
#include <signal.h>

void doSomething() {
    while (1) {

    }
}

void on_sigkill(int sig_n) {
    printf("SIGKILL caught\n");
    fflush(stdout);
}

void on_sigstop(int sig_n) {
    printf("SIGSTOP caught\n");
    fflush(stdout);
}

void on_sigusr1(int sig_n) {
    printf("SIGUSR1 caught\n");
    fflush(stdout);
}

void setup_signal_action(int signal, __sighandler_t handler) {
    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(signal, &action, NULL);
}

int main() {
    setup_signal_action(SIGKILL, on_sigkill);
    setup_signal_action(SIGSTOP, on_sigstop);
    setup_signal_action(SIGUSR1, on_sigusr1);

    raise(SIGINT);

    doSomething();
}

