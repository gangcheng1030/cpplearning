//
// Created by gang cheng on 2021/7/3.
//

#include <stdio.h>

int div16(int x) {
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}

int main() {
    int x;
    x = 32;
    printf("%d\n", div16(x));

    x = 78;
    printf("%d\n", div16(x));

    x = -34;
    printf("%d\n", div16(x));
}