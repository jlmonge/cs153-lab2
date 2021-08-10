#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf(1, "Usage: l2-inher <priority>\n");
    }
    else {
        int pid = getpid();
        int priority = atoi(argv[1]);
        int status;

        printf(1, "~~~ BEFORE ~~~\n");
        ps();
        printf(1, "~~~ AFTER ~~~\n");

        modpr(pid, priority);

        pid = fork();

        if (pid < 0) {
            printf(1, "ERROR: FORK");
            exitWithStatus(-1);
        }
        if (pid == 0) {;
            printf(1, "child %d has a priority of %d (expected %d)\n", getpid(), getpr(), priority);
            exitWithStatus(0);
        }
        else {
            printf(1,"parent %d of child %d has a priority of %d (expected %d)\n", getpid(), pid, getpr(), priority);
            pid = wait(&status);
            printf(1, "child %d done, parent %d exiting\n", pid, getpid());
        }
    }
    exit();
    return 0;
}