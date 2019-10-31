//
// Created by valentun on 30.10.19.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    char buff[5];

    setvbuf(stdin, buff, _IOLBF, sizeof buff);

    char * string = "Hello";

    for (int i = 0; i < 5; ++i) {
        printf("%c", string[i]);

        sleep(1);
    }
}