#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

// The test should be running ps

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf(1, "Usage: l2-lottery <priority>\n");
    }
    else {
        int pid = getpid();
        int priority = atoi(argv[1]);
        modpr(pid, priority);
        ps();
    }
    exit();
    return 0;
}