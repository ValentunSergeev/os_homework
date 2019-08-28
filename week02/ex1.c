//
// Created by valentun on 28.08.19.
//

#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("Int: %d: %zu\n", a, sizeof(a));
    printf("Float: %f: %zu\n", b, sizeof(b));
    printf("Double: %f: %zu\n", c, sizeof(c));
}
