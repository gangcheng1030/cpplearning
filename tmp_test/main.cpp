//
// Created by chenggang on 2021/6/24.
//

#include <stdio.h>
#include <string.h>

int main() {
    float data;
    unsigned long buff;
    int i;
    char s[35];

    data = (float) 0.75;
    memcpy(&buff, &data, 4);

    for (i = 33; i >= 0; i--) {
        if (i == 1 || i == 10) {
            s[i] = '-';
        } else {
            if (buff % 2 == 1) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
            buff /= 2;
        }
    }
    s[34] = '\0';
    printf("%s\n", s);

    return 0;
}