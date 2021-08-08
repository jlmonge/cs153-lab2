#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: l2-changepr <pid> <priority>");
    }
    else {
        int pid = atoi(argv[1]);
        int priority = atoi(argv[2]);
    }
}