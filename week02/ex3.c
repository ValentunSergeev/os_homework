//
// Created by valentun on 28.08.19.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int spaces;
    int stars;
} LevelInfo;

typedef void (*level_funct)(int, int, LevelInfo *);

#define TYPE_TREE 0
#define TYPE_HALF_TREE 1
#define TYPE_TRIANGLE 2
#define TYPE_RECTANGLE 3

void tree(int total, int level, LevelInfo * data_ptr) {
    data_ptr->stars = 2 * level + 1;
    data_ptr->spaces = total - level - 1;
}

void half_tree(int total, int level, LevelInfo * data_ptr) {
    data_ptr->spaces = 0;
    data_ptr->stars = level + 1;
}

void triangle(int total, int level, LevelInfo * data_ptr) {
   int middle = total / 2;

   data_ptr->stars = middle - abs(middle - level) + 1;
   data_ptr->spaces = 0;
}

void rectangle(int total, int level, LevelInfo * data_ptr) {
    data_ptr->spaces = 0;
    data_ptr->stars = total;
}

int main(int argc, char** argv) {
    int n, type;

    if (argc != 3) {
        printf("Wrong number of arguments\n");
        return 1;
    }

    n = atoi(argv[1]);

    type = atoi(argv[2]);

    level_funct level_function;

    switch (type) {
        case TYPE_TREE:
            level_function = &tree;
            break;
        case TYPE_HALF_TREE:
            level_function = &half_tree;
            break;
        case TYPE_TRIANGLE:
            level_function = &triangle;

            if (n % 2 == 0) n ++;

            break;
        case TYPE_RECTANGLE:
            level_function = &rectangle;
            break;
        default:
            printf("Wrong type");
            return 1;
    }

    LevelInfo * levelInfo = malloc(sizeof(LevelInfo));

    for (int i = 0; i < n; ++i) {
        level_function(n, i, levelInfo);

        for (int j = 0; j < levelInfo->spaces; ++j) {
            printf(" ");
        }

        for (int j = 0; j < levelInfo->stars; ++j) {
            printf("*");
        }

        printf("\n");
    }
}