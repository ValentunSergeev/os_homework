//
// Created by valentun on 11.09.19.
//

#include <unistd.h>

int main() {
    for (int i = 0; i < 5; ++i) {
        fork();
    }

    sleep(5);
}