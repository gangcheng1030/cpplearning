//
// Created by gang cheng on 2021/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {           // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {   // child (new process)
        char *myargs[4];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("./");
        myargs[2] = NULL;
        if (argc < 2) {
            execl(myargs[0], myargs[0], myargs[1]);
        } else if (strcmp(argv[1], "execl") == 0) {
            execl(myargs[0], myargs[0], myargs[1]);
        } else if (strcmp(argv[1], "execle") == 0) {
            execle(myargs[0], myargs[0], myargs[1], NULL);
        } else if (strcmp(argv[1], "execlp") == 0) {
            execlp(myargs[0], myargs[0], myargs[1]);
        } else if (strcmp(argv[1], "execv") == 0) {
            execv(myargs[0], myargs);
        } else if (strcmp(argv[1], "execvp") == 0) {
            execvp(myargs[0], myargs);
        } else {
            printf("no match command.\n");
        }
    } else {
        wait(NULL);
    }
    return 0;
}