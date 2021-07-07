//
// Created by gang cheng on 2021/6/28.
//

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {
//    int x = 12345;
//    show_int(x);
//    int *p = &x;
//    show_pointer(p);

    short sx = -12345;
    unsigned uy = sx;
    printf("uy = %u:\t", uy);
    show_bytes((byte_pointer) &uy, sizeof(unsigned));
    return 0;
}