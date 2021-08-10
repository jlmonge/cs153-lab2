#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

// We want turnaround time and wait time.

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: l2-perf <pid>\n");
    }
    else {
        int pid = atoi(argv[1]);
        performance(pid);
    }
    exit();
    return 0;
}