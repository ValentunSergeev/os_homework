//
// Created by valentun on 11.09.19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[100] = "";

    printf("> ");
    scanf("%s", buffer);

    while (strcmp(buffer, "exit") != 0) {
        system(buffer);

        printf("> ");
        scanf("%s", buffer);
    }
}