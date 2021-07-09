//
// Created by gang cheng on 2021/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int res = pipe(fd);
    if (res == -1) {
        fprintf(stderr, "create pipe failed\n");
        exit(1);
    }

    int rc1 = fork();
    if (rc1 < 0) {           // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc1 == 0) {   // child (new process)
        char s[] = "hello pipe!";
        write(fd[1], s, sizeof(s)-1);
        return 0;
    }

    int rc2 = fork();
    if (rc2 < 0) {           // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc2 == 0) {   // child (new process)
        char buf[100];
        read(fd[0], buf, sizeof(buf));
        printf("read: %s\n", buf);
        return 0;
    }

    wait(NULL);
    return 0;
}