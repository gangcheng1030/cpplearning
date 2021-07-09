//
// Created by gang cheng on 2021/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) {           // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {   // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        printf("child.x = %d (pid:%d)\n", x, (int) getpid());
        x = 50;
        printf("child.x = %d (pid:%d)\n", x, (int) getpid());
    } else {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        printf("parent.x = %d (pid:%d)\n", x, (int) getpid());
        x = 80;
        printf("parent.x = %d (pid:%d)\n", x, (int) getpid());
    }
    return 0;
}