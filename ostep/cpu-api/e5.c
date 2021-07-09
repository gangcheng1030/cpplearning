//
// Created by gang cheng on 2021/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {           // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {   // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        int wc = wait(NULL);
        printf("child wait return %d.\n", wc);
    } else {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        int wc = wait(NULL);
        printf("wait return %d.\n", wc);
    }
    return 0;
}