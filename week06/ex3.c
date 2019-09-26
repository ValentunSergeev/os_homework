//
// Created by valentun on 25.09.19.
//

#include <stdio.h>
#include <signal.h>

void on_sigint(int sig_n) {
    printf("Sigint caught");
}

void setup_signal_action(int signal, __sighandler_t handler) {
    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(signal, &action, NULL);
}

int main() {
    setup_signal_action(SIGINT, on_sigint);

   raise(SIGINT);
}