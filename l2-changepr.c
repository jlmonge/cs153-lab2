#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        printf(1, "Usage: l2-changepr <pid> <priority>\n");
    }
    else {
        int pid = atoi(argv[1]);
        int priority = atoi(argv[2]);

        if (priority < 1 || priority > 5) {
            printf(1, "Priority must be between 1 (highest) and 5 (lowest).\n");
            exit();
        }

        printf(1, "~~~ BEFORE ~~~\n");
        ps();
        changepriority(pid, priority);
        sleep(5);
        printf(1, "~~~ AFTER ~~~\n");
        ps();
    }
    exit();
    return 0;
}