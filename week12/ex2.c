//
// Created by valentun on 06.11.19.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <unistd.h>

bool is_exists(char * name) {
    return access(name, F_OK) != -1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Wrong number of arguments");
        exit(1);
    }

    bool appendMode = false;

    if (argc == 3 && strcmp(argv[1], "-a") == 0) {
        appendMode = true;
    }

    int fileNameIndex = argc - 1;

    char * fileName = argv[fileNameIndex];

    if (!is_exists(fileName)) {
        appendMode = false;
    }

    FILE * out;

    if (appendMode) {
        out = fopen(fileName, "a");
    } else {
        out = fopen(fileName, "w+");
    }

    int c = fgetc(stdin);
    while (c != EOF)
    {
        fputc(c, out);
        c = fgetc(stdin);
    }
}
