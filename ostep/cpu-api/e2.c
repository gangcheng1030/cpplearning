//
// Created by gang cheng on 2021/7/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    int fd = open("./e2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {           // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {   // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char s[] = "child\n";
        for (int i = 0; i < 100; i++)
            write(fd, s, sizeof(s)-1);
    } else {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        char s[] = "parent\n";
        for (int i = 0; i < 100; i++)
            write(fd, s, sizeof(s)-1);
    }
    close(fd);
    return 0;
}